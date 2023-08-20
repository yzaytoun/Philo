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
void	ft_semexecute(t_process *process, void (*function)(t_process *))
{
	ft_increment_semaphore(process);
	process->counter = 0;
	process->params.philo_status_counter = 0;
	while (process->counter < process->params.philo_num)
	{
		(*function)(process);
		process->counter++;
	}
	ft_decrement_semaphore(process);
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
	ft_get_semvalue(process);
	if (((t_semaphor *)process->synchronizer)->sem_value < SEM_VALUE_MAX)
	{
		ft_try(
			sem_post(&((t_semaphor *)process->synchronizer)->forks_semaphor));	
	}
	philo->left_fork.is_used = FALSE;
	ft_get_semvalue(process);
	if (((t_semaphor *)process->synchronizer)->sem_value < SEM_VALUE_MAX)
	{
		ft_try(
			sem_post(&((t_semaphor *)process->synchronizer)->forks_semaphor));	
	}
	philo->right_fork.is_used = FALSE;
}

//ANCHOR - Get forks from table
void	ft_getforks_sem(t_process *process, t_philo *philo)
{
	if (philo->left_fork.is_used == FALSE)
	{
		ft_get_semvalue(process);
		if (((t_semaphor *)process->synchronizer)->sem_value > 0)
			ft_try(sem_wait(&((t_semaphor *)process->synchronizer)->forks_semaphor));
		philo->left_fork.is_used = TRUE;
		philo->laststatus = TAKEN_FORK;
		ft_printstatus(*philo);
	}
	else if (philo->right_fork.is_used == FALSE)
	{
		ft_get_semvalue(process);
		if (((t_semaphor *)process->synchronizer)->sem_value > 0)
			ft_try(sem_wait(&((t_semaphor *)process->synchronizer)->forks_semaphor));
		philo->right_fork.is_used = TRUE;
		philo->laststatus = TAKEN_FORK;
		ft_printstatus(*philo);
	}
}
//!SECTION