/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 19:19:47 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/08/25 19:51:24 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

//SECTION - Main Bonus Loop
//ANCHOR - Routine
static void	ft_routine(t_process *process, t_philo *philo)
{
	philo->timer = process->params.start_time;
	while (ft_timediff(process, philo) < process->params.time_to_die
		&& philo->laststatus != DIED
		&& process->catch_status != DIED
		&& ft_threadlimit(process, philo) == FALSE)
	{
		ft_getforks_sem(process, philo);
		//ft_eat(process, philo);
		//ft_sleep(process, philo);
		//ft_think(process, philo);
		ft_isalive(process, philo);
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
	printf("inside the child sem = %d\n", ((t_semaphor *)process->synchronizer)->main_sem_value);
	ft_decrement_semaphore(process);
	printf("2 inside the child sem = %d\n", ((t_semaphor *)process->synchronizer)->main_sem_value);
	process->func(process, philo);
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
	ft_apply(process, ft_create_childprocess, APPLY_NO_LOCK);
	while (process->lock == TRUE)
		ft_apply(process, ft_check_allprocesses, APPLY_NO_LOCK);
	printf("3 outside the child sem = %d\n", ((t_semaphor *)process->synchronizer)->main_sem_value);
	ft_increment_semaphore(process);
	printf("4 outside the child sem = %d\n", ((t_semaphor *)process->synchronizer)->main_sem_value);
	ft_delaymil(process->params.time_to_die * 3000);
	ft_apply(process, ft_wait_childprocess, APPLY_NO_LOCK);
	ft_close_semaphore(process);
}
//!SECTION