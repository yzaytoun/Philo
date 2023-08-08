/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:45:56 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/08/08 20:16:45 by yzaytoun         ###   ########.fr       */
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
	const int	timelimit = philo->timer + process->params.time_to_eat;

	if (philo->left_fork.is_used == TRUE
		&& philo->right_fork.is_used == TRUE)
	{
		philo->laststatus = EATING;
		ft_printstatus(*philo);
		while (philo->timer < timelimit)
		{
			philo->timer = ft_gettimeofday();
			ft_delay(5);
		}
		philo->data.eat_count++;
		ft_dropforks(process, philo);
	}
}

//ANCHOR - Sleep
void	ft_sleep(t_process *process, t_philo *philo)
{
	const int	timelimit = philo->timer + process->params.time_to_sleep;

	if (philo->laststatus == EATING)
	{
		philo->laststatus = SLEEPING;
		ft_printstatus(*philo);
		while (philo->timer < timelimit)
		{
			philo->timer = ft_gettimeofday();
			ft_delay(5);
		}
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

//ANCHOR - Increment loop
void	ft_addtime(t_process *process, t_philo *philo)
{
	(void)process;
	philo->timer += ft_gettimeofday();
}
//!SECTION