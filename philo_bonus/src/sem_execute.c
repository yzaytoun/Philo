/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:54:17 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/02/19 18:30:23 by yzaytoun         ###   ########.fr       */
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
	ft_increment_semaphore(process, FORK_SEM);
	philo->left_fork.is_used = FALSE;
	ft_increment_semaphore(process, FORK_SEM);
	philo->right_fork.is_used = FALSE;
}

//ANCHOR - Get forks from table
void	ft_getforks_sem(t_process *process, t_philo *philo)
{
	if (philo->left_fork.is_used == FALSE)
	{
		ft_decrement_semaphore(process, FORK_SEM);
		philo->left_fork.is_used = TRUE;
		philo->laststatus = TAKEN_FORK;
		ft_print_log(process, philo);
	}
	if (philo->right_fork.is_used == FALSE && process->params.philo_num > 1)
	{
		ft_decrement_semaphore(process, FORK_SEM);
		philo->right_fork.is_used = TRUE;
		philo->laststatus = TAKEN_FORK;
		ft_print_log(process, philo);
	}
}

//ANCHOR - SEM EXECUTE
void	ft_semexecute(t_process *process, t_philo *philo,
		void (*f)(t_process *, t_philo *))
{
	ft_decrement_semaphore(process, MAIN_SEM);
	(*f)(process, philo);
	ft_increment_semaphore(process, MAIN_SEM);
}
//!SECTION