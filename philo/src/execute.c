/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:45:56 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/02/08 20:09:06 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//SECTION - Execute
//ANCHOR - Eat
void	ft_eat(t_process *process, t_philo *philo)
{
	if (philo->left_fork.is_used == TRUE
		&& philo->right_fork.is_used == TRUE
		&& philo->laststatus != DIED)
	{
		philo->laststatus = EATING;
		ft_threadexecute(process, ft_printstatus, philo);
		ft_delaymil(process->params.time_to_eat, process, philo);
		philo->last_eat_time = ft_get_current_time();
		philo->timer = ft_get_current_time();
		philo->data.eat_count++;
		process->dropforks(process, philo);
	}
}

//ANCHOR - Sleep
void	ft_sleep(t_process *process, t_philo *philo)
{
	if (philo->laststatus == EATING && philo->laststatus != DIED)
	{
		philo->laststatus = SLEEPING;
		ft_threadexecute(process, ft_printstatus, philo);
		ft_delaymil(process->params.time_to_sleep, process, philo);
		philo->timer = ft_get_current_time();
		philo->data.sleep_count++;
	}
}

//ANCHOR - Think
void	ft_think(t_process *process, t_philo *philo)
{
	if (philo->laststatus != DIED)
	{
		philo->laststatus = THINKING;
		ft_threadexecute(process, ft_printstatus, philo);
		ft_delaymil(process->params.time_to_sleep, process, philo);
		philo->timer = ft_get_current_time();
		philo->data.think_count++;
	}
}

//ANCHOR - Is alive
void	ft_isalive(t_process *process, t_philo *philo)
{
	if (ft_timediff(
			philo->timer,
			philo->last_eat_time) >= process->params.time_to_die)
	{
		ft_threadexecute(process, ft_printstatus, philo);
		philo->laststatus = DIED;
	}
}

//!SECTION