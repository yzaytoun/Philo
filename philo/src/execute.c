/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:45:56 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/08/01 20:19:07 by yzaytoun         ###   ########.fr       */
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
		ft_printstatus(*philo, EATING);
		while (philo->timer < process->params.time_to_eat)
		{
			philo->timer++;
		}
		philo->data.eat_count++;
		philo->laststatus = EATING;
		printf("done eating\n");
		ft_try(
			pthread_mutex_unlock(
				&process->fork[philo->left_fork.id - 1].mutex));
		process->fork[philo->left_fork.id - 1].is_used = FALSE;
		ft_try(
			pthread_mutex_unlock(
				&process->fork[philo->right_fork.id - 1].mutex));
		process->fork[philo->right_fork.id - 1].is_used = FALSE;
		philo->left_fork.is_used = FALSE;
		philo->right_fork.is_used = FALSE;
	}
}

//ANCHOR - Sleep
void	ft_sleep(t_process *process, t_philo *philo)
{
	if (philo->left_fork.is_used == TRUE
		&& philo->right_fork.is_used == TRUE
		&& philo->laststatus == EATING)
	{
		ft_printstatus(*philo, SLEEPING);
		while (philo->timer < process->params.time_to_sleep)
		{
			ft_delay(5);
			philo->timer++;
		}
		philo->left_fork.is_used = FALSE;
		philo->right_fork.is_used = FALSE;
	}
	philo->data.sleep_count++;
}

//ANCHOR - Is alive
void	ft_isalive(t_process *process, t_philo *philo)
{
	if (philo->timer == process->params.time_to_die)
	{
		philo->laststatus = DIED;
		ft_printstatus(*philo, DIED);
	}
}

//!SECTION