/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:33:36 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/31 19:59:53 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//SECTION - Routine Function
//ANCHOR - Validate fork
static int	ft_validfork(t_process *process, int philo_id, int flag)
{
	if (flag == LEFT)
	{
		return (process->philo[philo_id - 1].left_fork.id
			- process->fork[philo_id - 1].id + 1);
	}
	else
		return (process->philo[philo_id - 1].left_fork.id
			- process->fork[philo_id - 1].id + 1);
}

//ANCHOR - Get forks
static void	ft_getforks(t_process *process, int philo_id)
{
	if (process->fork[philo_id - 1].is_used == FALSE
		&& ft_validfork(process, philo_id, LEFT) == TRUE)
	{
		process->philo[philo_id - 1].left_fork.is_used = TRUE;
		ft_printstatus(process->philo[philo_id - 1], TAKEN_FORK);
	}
	if (process->fork[philo_id - 1].is_used == FALSE
		&& ft_validfork(process, philo_id, RIGHT) == TRUE)
	{
		process->philo[philo_id - 1].right_fork.is_used = TRUE;
		ft_printstatus(process->philo[philo_id - 1], TAKEN_FORK);
	}
}

//ANCHOR - Routine
void	*ft_routine(t_philo *philo)
{
	t_process	*process;

	process = philo->process;
	while (philo->timer < process->params.time_to_die)
	{
		printf("fork = %d\n", philo->left_fork.is_used);
		printf("fork2 = %d\n", philo->right_fork.is_used);
		ft_threadexecute(process, ft_getforks, philo->id);
		printf("after fork = %d\n", philo->right_fork.is_used);

		//ft_threadexecute(process, ft_eat, philo->id);
		//ft_threadexecute(process, ft_sleep, philo->id);
		//ft_threadexecute(process, ft_isalive, philo->id);
		philo->timer++;
	}
	return ((void *)(uintptr_t)philo->laststatus);
}

//ANCHOR - Run
int	ft_run(t_process *process)
{
	if (!process || process->philo == NULL)
		return (EXIT_FAILURE);
	ft_try(pthread_mutex_init(&process->mutex, NULL));
	ft_addcurrenttime(&process->params);
	ft_apply(process, ft_updatetimer);
	ft_apply(process, ft_initmutex);
	if ((size_t)ft_apply(process, ft_createthread) == DIED)
		return (DIED);
	return (EXIT_SUCCESS);
}

//!SECTION