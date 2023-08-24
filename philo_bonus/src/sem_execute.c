/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:54:17 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/08/24 19:33:44 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

//SECTION - Semaphores safe execution
//ANCHOR - Check all processes
int	ft_check_allprocesses(t_process *process, int count)
{
	if (process->philo[count].laststatus == STARTED)
		process->params.philo_status_counter++;
	if (process->params.philo_status_counter == process->params.philo_num)
		process->lock = FALSE;
	return (EXIT_SUCCESS);
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
		if (((t_semaphor *)process->synchronizer)->fork_sem_value > 0)
		{
			((t_semaphor *)process->synchronizer)->fork_sem_value--;
			ft_try(sem_wait(
					((t_semaphor *)process->synchronizer)->forks_semaphor));
		}	
		philo->left_fork.is_used = TRUE;
		philo->laststatus = TAKEN_FORK;
		ft_printstatus(*philo, ft_timediff(process, philo));
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
		ft_printstatus(*philo, ft_timediff(process, philo));
	}
}
//!SECTION