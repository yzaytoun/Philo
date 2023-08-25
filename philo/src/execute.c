/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:45:56 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/08/25 18:53:00 by yzaytoun         ###   ########.fr       */
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
		ft_delaymil(process->params.time_to_eat);
		philo->timer = ft_gettimeofday();
		philo->data.eat_count++;
		process->dropforks(process, philo);
	}
}

//ANCHOR - Sleep
void	ft_sleep(t_process *process, t_philo *philo)
{
	if (philo->laststatus == EATING)
	{
		philo->laststatus = SLEEPING;
		ft_printstatus(*philo, ft_timediff(process, philo));
		ft_delaymil(process->params.time_to_sleep);
		philo->timer = ft_gettimeofday();
		philo->data.sleep_count++;
	}
}

//ANCHOR - Think
void	ft_think(t_process *process, t_philo *philo)
{
	if (philo->laststatus != DIED)
	{
		philo->laststatus = THINKING;
		ft_printstatus(*philo, ft_timediff(process, philo));
		ft_delaymil(process->params.time_to_sleep);
		philo->timer = ft_gettimeofday();
		philo->data.think_count++;
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