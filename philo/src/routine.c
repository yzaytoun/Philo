/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:33:36 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/08/01 20:21:41 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//SECTION - Routine Function
//ANCHOR - Validate fork
static int
	ft_validfork(t_process *process, int philo_id, int counter, int flag)
{
	if (flag == LEFT)
	{
		return (process->philo[philo_id - 1].left_fork.id
			- process->fork[counter].id + 1);
	}
	else
		return (process->philo[philo_id - 1].right_fork.id
			- process->fork[counter].id + 1);
}

//ANCHOR - Get forks
static void	ft_getforks(t_process *process, t_philo *philo)
{
	process->counter = 0;
	while (process->counter < process->params.philo_num)
	{
		if (process->fork[process->counter].is_used == FALSE
			&& ft_validfork(process, philo->id, process->counter, LEFT) == TRUE)
		{
			philo->left_fork.is_used = TRUE;
			process->fork[process->counter].is_used = TRUE;
			ft_try(pthread_mutex_lock(&process->fork[process->counter].mutex));
			ft_printstatus(*philo, TAKEN_FORK);
		}
		else if (process->fork[process->counter].is_used == FALSE
			&& ft_validfork(process, philo->id, process->counter, RIGHT)
			== TRUE)
		{
			philo->right_fork.is_used = TRUE;
			process->fork[process->counter].is_used = TRUE;
			ft_try(pthread_mutex_lock(&process->fork[process->counter].mutex));
			ft_printstatus(*philo, TAKEN_FORK);
		}
		process->counter++;
	}
}

//ANCHOR - Routine
void	*ft_routine(t_philo *philo)
{
	t_process	*process;

	process = philo->process;
	while (philo->timer < process->params.time_to_die
		&& ft_threadlimit(process, philo) == FALSE)
	{
		ft_threadexecute(process, ft_getforks, philo);
		ft_threadexecute(process, ft_eat, philo);
		//ft_threadexecute(process, ft_sleep, philo->id);
		philo->timer++;
		ft_threadexecute(process, ft_isalive, philo);
	}
	printf("status = %d\n", philo->laststatus);
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