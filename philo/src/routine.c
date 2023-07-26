/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:33:36 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/26 18:13:02 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//SECTION - Routine Function
//ANCHOR - Validate fork
static int	ft_validfork(int philo_fork, int fork_id)
{
	return (philo_fork - fork_id + 1);
}

//ANCHOR - Get forks
static void	ft_getforks(t_process *process, int philo_id)
{
	if (process->fork[philo_id].is_used == FALSE
		&& ft_validfork(process->philo[philo_id].left_fork.id
			, process->fork[philo_id].id) == TRUE)
	{
		process->philo[philo_id].left_fork.is_used = TRUE;
		ft_printstatus(process->philo[philo_id].id, TAKEN_FORK);
	}
	else if (process->fork[philo_id].is_used == FALSE
		&& ft_validfork(process->philo[philo_id].right_fork.id
			, process->fork[philo_id].id) == TRUE)
	{
		process->philo[philo_id].right_fork.is_used = TRUE;
		ft_printstatus(process->philo[philo_id].id, TAKEN_FORK);
	}
}

//ANCHOR - Routine
void	*ft_routine(t_philo *philo)
{
	t_process	*process;

	process = philo->process;
	ft_threadexecute(process, ft_getforks, philo->id);
	ft_threadexecute(process, ft_eat, philo->id);
	ft_threadexecute(process, ft_sleep, philo->id);
	ft_threadexecute(process, ft_isalive, philo->id);
	return ((void *)(uintptr_t)philo->laststatus);
}

//ANCHOR - Run
int	ft_run(t_process *process)
{
	if (!process || process->philo == NULL)
		return (EXIT_FAILURE);
	ft_try(pthread_mutex_init(&process->mutex, NULL));
	ft_apply(process, ft_updatetimer);
	ft_addcurrenttime(&process->params);
	ft_apply(process, ft_createthread);
	if ((int)ft_apply(process, ft_threadjoin) == DIED)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

//!SECTION