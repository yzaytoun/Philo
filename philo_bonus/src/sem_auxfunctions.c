/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_auxfunctions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:41:50 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/02/19 19:52:18 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

//SECTION - Auxiliarly Functions

//ANCHOR - Increment semaphore
void	ft_increment_semaphore(t_process *process, int sem_id)
{
	if (sem_id == MAIN_SEM)
	{
		if (((t_semaphor *)process->synchronizer)->main_sem_value
			< SEM_VALUE_MAX)
		{
			ft_try(
				sem_post(
					((t_semaphor *)process->synchronizer)->main_semaphor),
				FUNC);
			((t_semaphor *)process->synchronizer)->main_sem_value++;
		}
	}
	else if (sem_id == FORK_SEM)
	{
		if (((t_semaphor *)process->synchronizer)->fork_sem_value
			< SEM_VALUE_MAX)
		{
			ft_try(
				sem_post(
					((t_semaphor *)process->synchronizer)->forks_semaphor),
				FUNC);
			((t_semaphor *)process->synchronizer)->fork_sem_value++;
		}
	}
}

//ANCHOR - Decrement semaphore
void	ft_decrement_semaphore(t_process *process, int sem_id)
{
	if (sem_id == MAIN_SEM)
	{
		ft_try(
			sem_wait(
				((t_semaphor *)process->synchronizer)->main_semaphor), FUNC);
		((t_semaphor *)process->synchronizer)->main_sem_value--;
	}
	else if (sem_id == FORK_SEM)
	{
		ft_try(sem_wait(
				((t_semaphor *)process->synchronizer)->forks_semaphor), FUNC);
		((t_semaphor *)process->synchronizer)->fork_sem_value--;
	}
}

//ANCHOR - Open semaphores
void	ft_open_semaphore(t_process *process)
{
	((t_semaphor *)process->synchronizer)->main_semaphor
		= sem_open("/philo_sem", O_CREAT, 0644, 1);
	if (((t_semaphor *)process->synchronizer)->main_semaphor == SEM_FAILED)
	{
		ft_freeall(&process);
		ft_perror("Open Main Semaphores", FUNC);
	}
	((t_semaphor *)process->synchronizer)->forks_semaphor
		= sem_open("/forks_sem", O_CREAT, 0644, process->params.philo_num);
	if (((t_semaphor *)process->synchronizer)->forks_semaphor == SEM_FAILED)
	{
		ft_freeall(&process);
		ft_perror("Open forks Semaphores", FUNC);
	}
	ft_try(sem_unlink("/philo_sem"), FUNC);
	ft_try(sem_unlink("/forks_sem"), FUNC);
}

//ANCHOR - Close semaphores
void	ft_close_semaphore(t_process *process)
{
	ft_try(sem_close(((t_semaphor *)process->synchronizer)->main_semaphor),
		FUNC);
	ft_try(sem_close(((t_semaphor *)process->synchronizer)->forks_semaphor),
		FUNC);
}
//!SECTION