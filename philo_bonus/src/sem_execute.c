/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:54:17 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/08/21 18:21:03 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

//SECTION - Semaphores safe execution
//ANCHOR - SEM Execute
void	ft_semexecute(t_process *process, void (*function)(t_process *))
{
	process->counter = 0;
	process->params.philo_status_counter = 0;
	while (process->counter < process->params.philo_num)
	{
		(*function)(process);
		process->counter++;
	}
}

//ANCHOR - Check all processes
void	ft_check_allprocesses(t_process *process)
{
	if (process->philo[process->counter].laststatus == STARTED)
		process->params.philo_status_counter++;
	if (process->params.philo_status_counter == process->params.philo_num)
		process->lock = FALSE;
}

//ANCHOR - Drop Forks
void	ft_dropforks_sem(t_process *process, t_philo *philo)
{
	if (((t_semaphor *)process->synchronizer)->fork_sem_value < SEM_VALUE_MAX)
	{
		((t_semaphor *)process->synchronizer)->fork_sem_value++;
		ft_try(
			sem_post(((t_semaphor *)process->synchronizer)->forks_semaphor));
	}
	philo->left_fork.is_used = FALSE;
	if (((t_semaphor *)process->synchronizer)->fork_sem_value < SEM_VALUE_MAX)
	{
		((t_semaphor *)process->synchronizer)->fork_sem_value++;
		ft_try(
			sem_post(((t_semaphor *)process->synchronizer)->forks_semaphor));
	}
	philo->right_fork.is_used = FALSE;
}

//ANCHOR - Get forks from table
void	ft_getforks_sem(t_process *process, t_philo *philo)
{
	if (philo->left_fork.is_used == FALSE)
	{
		((t_semaphor *)process->synchronizer)->fork_sem_value--;
		ft_try(sem_wait(
				((t_semaphor *)process->synchronizer)->forks_semaphor));
		philo->left_fork.is_used = TRUE;
		philo->laststatus = TAKEN_FORK;
		ft_printstatus(*philo);
	}
	if (philo->right_fork.is_used == FALSE)
	{
		if (((t_semaphor *)process->synchronizer)->fork_sem_value > 0) 
		{
			((t_semaphor *)process->synchronizer)->fork_sem_value--;
			ft_try(sem_wait(
					((t_semaphor *)process->synchronizer)->forks_semaphor));
		}
		philo->right_fork.is_used = TRUE;
		philo->laststatus = TAKEN_FORK;
		ft_printstatus(*philo);
	}
}
//!SECTION