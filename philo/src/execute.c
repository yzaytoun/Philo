/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:45:56 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/02/24 10:57:06 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//SECTION - Execute
//ANCHOR - Eat
void	ft_eat(t_process *process, t_philo *philo)
{
	ft_isalive(process, philo);
	ft_threadexecute(process, ft_update_status, philo);
	if (philo->left_fork.is_used == TRUE
		&& philo->right_fork.is_used == TRUE
		&& philo->laststatus != DIED && process->catch_status != DIED)
	{
		philo->laststatus = EATING;
		ft_threadexecute(process, ft_print_log, philo);
		philo->last_eat_time = ft_get_current_time();
		ft_msleep(philo->params.time_to_eat, process, philo);
		philo->data.eat_count++;
		process->dropforks(process, philo);
	}
	ft_isalive(process, philo);
	ft_threadexecute(process, ft_update_status, philo);
}

//ANCHOR - Sleep
void	ft_sleep(t_process *process, t_philo *philo)
{
	if (philo->laststatus == EATING
		&& philo->laststatus != DIED && process->catch_status != DIED)
	{
		philo->laststatus = SLEEPING;
		ft_threadexecute(process, ft_print_log, philo);
		ft_msleep(philo->params.time_to_sleep, process, philo);
		philo->data.sleep_count++;
	}
	ft_isalive(process, philo);
	ft_threadexecute(process, ft_update_status, philo);
}

//ANCHOR - Think
void	ft_think(t_process *process, t_philo *philo)
{
	if (philo->laststatus == SLEEPING
		&& philo->laststatus != DIED && process->catch_status != DIED)
	{
		philo->laststatus = THINKING;
		ft_threadexecute(process, ft_print_log, philo);
	}
	ft_isalive(process, philo);
	ft_threadexecute(process, ft_update_status, philo);
}

//ANCHOR - Check fork locks
void	ft_update_status(t_process *process, t_philo *philo)
{
	if (philo->laststatus == DIED)
		process->catch_status = DIED;
}

//ANCHOR - Is alive
t_bool	ft_isalive(t_process *process, t_philo *philo)
{
	if (philo->laststatus == DIED || process->catch_status == DIED)
		return (FALSE);
	if (ft_time_diff(
			ft_get_current_time(),
			philo->last_eat_time) >= process->params.time_to_die)
	{
		philo->laststatus = DIED;
		return (FALSE);
	}
	return (TRUE);
}

//!SECTION