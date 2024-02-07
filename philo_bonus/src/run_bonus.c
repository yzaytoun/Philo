/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 19:19:47 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/02/07 18:42:39 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

//SECTION - Main Bonus Loop
//ANCHOR - Routine
static void	ft_routine(t_process *process, t_philo *philo)
{
	if (philo->id % 2 == 0)
		ft_delaymil(20, process, philo);
	philo->timer = process->params.start_time;
	philo->time_reset = process->params.start_time;
	while (philo->laststatus != DIED
		&& ft_threadlimit(process, philo) == FALSE)
	{
		ft_semexecute(process, philo, ft_getforks_sem);
		ft_semexecute(process, philo, ft_eat);
		ft_semexecute(process, philo, ft_sleep);
		ft_semexecute(process, philo, ft_think);
		ft_delaymil(20, process, philo);
	}
}

//ANCHOR - Mainthread loop
static void	*ft_mainprocess_loop(void *args)
{
	t_philo		*philo;
	t_process	*process;

	if (args == NULL)
		return (NULL);
	philo = (t_philo *)args;
	ft_initprocess(&process, philo);
	ft_decrement_semaphore(process, MAIN_SEM);
	process->func(process, philo);
	ft_close_semaphore(process);
	exit(EXIT_SUCCESS);
}

//ANCHOR - Run loop
void	ft_run(t_process *process)
{
	if (!process || process->params.philo_num <= 0)
		return ;
	process->synchronizer = malloc(sizeof(t_semaphor));
	if (!process->synchronizer)
		return ;
	process->main_loop = ft_mainprocess_loop;
	process->dropforks = ft_dropforks_sem;
	process->lock = TRUE;
	process->func = ft_routine;
	ft_open_semaphore(process);
	process->params.start_time = ft_get_current_time();
	ft_apply(process, ft_create_childprocess, APPLY_NO_LOCK);
	ft_delaymil(20, NULL, NULL);
	process->counter = 0;
	while (process->counter < process->params.philo_num + 1)
	{
		ft_increment_semaphore(process, MAIN_SEM);
		++process->counter;
	}
	ft_apply(process, ft_wait_childprocess, APPLY_NO_LOCK);
	ft_close_semaphore(process);
}
//!SECTION