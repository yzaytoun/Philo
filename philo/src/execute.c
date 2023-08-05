/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:45:56 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/08/05 13:09:52 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//SECTION - Execute
//ANCHOR - Eat
static void	ft_dropforks(t_process *process, t_philo *philo)
{
	ft_try(
		pthread_mutex_unlock(&process->fork[philo->left_fork.id - 1].mutex)
		);
	ft_try(
		pthread_mutex_unlock(&process->fork[philo->right_fork.id - 1].mutex)
		);
	process->fork[philo->left_fork.id - 1].is_used = FALSE;
	process->fork[philo->right_fork.id - 1].is_used = FALSE;
	philo->left_fork.is_used = FALSE;
	philo->right_fork.is_used = FALSE;
}

void	ft_eat(t_process *process, t_philo *philo)
{
	if (philo->left_fork.is_used == TRUE
		&& philo->right_fork.is_used == TRUE)
	{
		philo->laststatus = EATING;
		ft_printstatus(*philo);
		ft_delay(2);
		philo->data.eat_count++;
		ft_dropforks(process, philo);
	}
}

//ANCHOR - Sleep
void	ft_sleep(t_process *process, t_philo *philo)
{
	(void)process;
	if (philo->laststatus == EATING)
	{
		philo->laststatus = SLEEPING;
		ft_printstatus(*philo);
		ft_delay(2);
		philo->data.sleep_count++;
	}
}

//ANCHOR - Is alive
void	ft_isalive(t_process *process, t_philo *philo)
{
	if (philo->timer == process->params.time_to_die)
	{
		philo->laststatus = DIED;
		ft_printstatus(*philo);
	}
}

//!SECTION