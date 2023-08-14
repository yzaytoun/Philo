/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:33:36 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/08/14 19:24:28 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//SECTION - Routine Section
//ANCHOR - Routine
static void	ft_routine(t_process *process, t_philo *philo)
{
	philo->timer = process->params.start_time;
	while (philo->timer < process->params.time_to_die
		&& philo->laststatus != DIED
		&& ft_threadlimit(process, philo) == FALSE)
	{
		ft_threadexecute(process, ft_getforks, philo);
		ft_threadexecute(process, ft_eat, philo);
		ft_threadexecute(process, ft_sleep, philo);
		ft_threadexecute(process, ft_addtime, philo);
		ft_threadexecute(process, ft_isalive, philo);
		if (philo->laststatus == DIED)
			break ;
		ft_threadchecker(process, ft_check_deadthread);
	}
}

//ANCHOR - Mainthread loop
static void	*ft_mainthread_loop(void *args)
{
	t_philo		*philo;
	t_process	*process;

	philo = (t_philo *)args;
	process = philo->process;
	process->func = ft_routine;
	ft_threadexecute(process, ft_init_thread, philo);
	while (process->lock != FALSE)
		ft_threadchecker(process, ft_all_threadsactive);
	ft_startroutine(process, philo);
	ft_threadchecker(process, ft_check_forklocks);
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
	process->main_loop = ft_mainthread_loop;
	ft_apply(process, ft_createthread);
	ft_apply(process, ft_threadjoin);
}

//!SECTION
