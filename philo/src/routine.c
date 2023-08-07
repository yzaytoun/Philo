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

//SECTION - Routine Section
//ANCHOR - Update status
static void	ft_philo_statusupdate(t_process *process)
{
	ft_try(pthread_mutex_lock(&process->main_mutex));
	process->counter = 0;
	process->params.philo_status = 0;
	while (process->counter < process->params.philo_num)
	{
		if (process->philo[process->counter].laststatus == STARTED)
			process->params.philo_status++;
		else if (process->philo[process->counter].laststatus == DIED)
		{
			process->catch_status = DIED;
			ft_try(pthread_mutex_unlock(&process->main_mutex));
			return ;
		}
		process->counter++;
	}
	if (process->params.philo_status == process->params.philo_num)
		process->lock = FALSE;
	ft_try(pthread_mutex_unlock(&process->main_mutex));
}

//ANCHOR - Routine
void	ft_routine(t_process *process, t_philo *philo)
{
	philo->timer = process->params.start_time;
	while (philo->timer < process->params.time_to_die
		&& ft_threadlimit(process, philo) == FALSE)
	{
		ft_threadexecute(process, ft_isalive, philo);
		ft_threadexecute(process, ft_getforks, philo);
		ft_threadexecute(process, ft_eat, philo);
		ft_threadexecute(process, ft_sleep, philo);
		ft_threadexecute(process, ft_addtime, philo);
	}
}

//ANCHOR - Mainthread loop
void	*ft_mainthread_loop(void *args)
{
	t_philo		*philo;
	t_process	*process;

	philo = (t_philo *)args;
	process = philo->process;
	ft_threadexecute(process, ft_init_thread, philo);
	while (process->lock != FALSE)
		ft_philo_statusupdate(process);
	ft_checklock(process, philo);
	return ((void *)(uintptr_t)philo->laststatus);
}

//ANCHOR - Run
void	ft_run(t_process *process)
{
	if (!process || process->philo == NULL)
		return ;
	ft_try(pthread_mutex_init(&process->mutex, NULL));
	ft_try(pthread_mutex_init(&process->main_mutex, NULL));
	process->lock = TRUE;
	ft_marktime(&process->params);
	ft_apply(process, ft_initforkmutex);
	ft_apply(process, ft_createthread);
	ft_apply(process, ft_threadjoin);
	ft_checkstatus(process);
}

//!SECTION