/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:54:17 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/08/19 18:37:26 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

//SECTION - Semaphores safe execution
//ANCHOR - SEM Execute
void	ft_semexecute(t_process *process, t_philo *philo,
	void (*function)(t_process *, t_philo *))
{
	ft_get_semvalue(process);
	if (((t_semaphor *)process->synchronizer)->sem_value > 0)
	{
		ft_try(sem_wait(&((t_semaphor *)process->synchronizer)->main_semaphor));
		(*function)(process, philo);
		ft_get_semvalue(process);
		if (((t_semaphor *)process->synchronizer)->sem_value < SEM_VALUE_MAX)
		{
			ft_try(
				sem_post(
					&((t_semaphor *)process->synchronizer)->main_semaphor));
		}
	}	
}

//ANCHOR - Drop Forks
void	ft_dropforks_sem(t_process *process, t_philo *philo)
{
	ft_get_semvalue(process);
	if (((t_semaphor *)process->synchronizer)->sem_value < SEM_VALUE_MAX)
	{
		ft_try(
			sem_post(&((t_semaphor *)process->synchronizer)->forks_semaphor));
	}
}

//ANCHOR - Get semaphore values
void	ft_get_semvalue(t_process *process)
{
	ft_try(
		sem_getvalue(
			((t_semaphor *)process->synchronizer)->main_semaphor,
			&((t_semaphor *)process->synchronizer)->sem_value
			)
		);
}

//
//!SECTION