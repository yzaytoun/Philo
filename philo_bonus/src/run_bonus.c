/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 19:19:47 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/08/19 18:33:47 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

//SECTION - Main Bonus Loop
//ANCHOR - Routine
static void	ft_routine(t_process *process, t_philo *philo)
{
	philo->timer = process->params.start_time;
	while (philo->timer < process->params.time_to_die
		&& philo->laststatus != DIED
		&& ft_threadlimit(process, philo) == FALSE)
	{
		ft_semexecute(process, ft_getforks_from_table, philo);
		ft_semexecute(process, ft_eat, philo);
		ft_semexecute(process, ft_sleep, philo);
		ft_semexecute(process, ft_addtime, philo);
		ft_semexecute(process, ft_isalive, philo);
		if (philo->laststatus == DIED)
			break ;
	}
}

//ANCHOR - Mainthread loop
static void	*ft_mainprocess_loop(void *args)
{
	t_philo		*philo;
	t_process	*process;

	philo = (t_philo *)args;
	process = philo->process;
	process->func = ft_routine;
	ft_startroutine(process, philo);
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
	((t_semaphor *)process->synchronizer)->main_semaphor
		= sem_open("/philo_sem", O_CREAT | O_EXCL, 0644,
			process->params.philo_num);
	ft_marktime(&process->params);
	ft_apply(process, ft_create_childprocess);
	ft_apply(process, ft_wait_childprocess);
	ft_try(sem_close(((t_semaphor *)process->synchronizer)->main_semaphor));
	ft_try(sem_unlink(((t_semaphor *)process->synchronizer)->main_semaphor));
}
//!SECTION