/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:45:56 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/08/24 19:26:42 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//SECTION - Execute
//ANCHOR - Eat
void	ft_eat(t_process *process, t_philo *philo)
{
	if (philo->left_fork.is_used == TRUE
		&& philo->right_fork.is_used == TRUE)
	{
		philo->laststatus = EATING;
		ft_printstatus(*philo, ft_timediff(process, philo));
		philo->timer = ft_delaymil(process->params.time_to_eat);
		philo->data.eat_count++;
		process->dropforks(process, philo);
	}
}

//ANCHOR - Sleep
void	ft_sleep(t_process *process, t_philo *philo)
{
	if (philo->laststatus != DIED)
	{
		philo->laststatus = SLEEPING;
		ft_printstatus(*philo, ft_timediff(process, philo));
		philo->timer= ft_delaymil(process->params.time_to_sleep);
		philo->data.sleep_count++;
	}
}

//ANCHOR - Is alive
void	ft_isalive(t_process *process, t_philo *philo)
{
	if (ft_timediff(process, philo) >= process->params.time_to_die)
	{
		philo->laststatus = DIED;
		ft_printstatus(*philo, ft_timediff(process, philo));
	}
}

//!SECTION