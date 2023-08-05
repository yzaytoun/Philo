/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:33:36 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/08/05 17:38:38 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//SECTION - Routine Function
//ANCHOR - Take Fork
static void	ft_takefork(t_process *process, t_philo *philo, int fork_side)
{
	if (fork_side == LEFT)
	{
		philo->left_fork.is_used = TRUE;
		process->fork[process->counter].is_used = TRUE;
		philo->laststatus = TAKEN_FORK;
	}
	else if (fork_side == RIGHT)
	{
		philo->right_fork.is_used = TRUE;
		process->fork[process->counter].is_used = TRUE;
		philo->laststatus = TAKEN_FORK;
	}
}

//ANCHOR - Validate fork
static int
	ft_validfork(t_process *process, int philo_id, int counter, int fork_side)
{
	if (fork_side == LEFT)
	{
		return (process->philo[philo_id - 1].left_fork.id
			- process->fork[counter].id + 1);
	}
	else if (fork_side == RIGHT)
	{
		return (process->philo[philo_id - 1].right_fork.id
			- process->fork[counter].id + 1);
	}
	return (FALSE);
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
			ft_takefork(process, philo, LEFT);
			ft_try(pthread_mutex_lock(&process->fork[process->counter].mutex));
			ft_printstatus(*philo);
		}
		else if (process->fork[process->counter].is_used == FALSE
			&& ft_validfork(process, philo->id, process->counter, RIGHT)
			== TRUE)
		{
			ft_takefork(process, philo, RIGHT);
			ft_try(pthread_mutex_lock(&process->fork[process->counter].mutex));
			ft_printstatus(*philo);
		}
		process->counter++;
	}
}

//ANCHOR - Routine
void	*ft_routine(t_philo *philo)
{
	t_process	*process;

	process = philo->process;
	ft_delay(10);
	philo->timer = process->params.start_time;
	while (philo->timer < process->params.time_to_die
		&& ft_threadlimit(process, philo) == FALSE)
	{
		ft_threadexecute(process, ft_isalive, philo);
		if (philo->laststatus == DIED)
			return ((void *)(uintptr_t)philo->laststatus);
		ft_threadexecute(process, ft_getforks, philo);
		ft_threadexecute(process, ft_eat, philo);
		ft_threadexecute(process, ft_sleep, philo);
		philo->timer++;
	}
	ft_threadexecute(process, ft_isalive, philo);
	return ((void *)(uintptr_t)philo->laststatus);
}

//ANCHOR - Run
void	ft_run(t_process *process)
{
	if (!process || process->philo == NULL)
		return ;
	ft_try(pthread_mutex_init(&process->mutex, NULL));
	ft_try(pthread_mutex_init(&process->main_mutex, NULL));
	ft_addcurrenttime(&process->params);
	ft_apply(process, ft_initmutex);
	ft_apply(process, ft_createthread);
	ft_apply(process, ft_threadjoin);
	ft_checkstatus(process);
	ft_catch(process);
}

//!SECTION