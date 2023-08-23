/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 19:49:16 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/08/23 18:14:03 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//SECTION Threads
//ANCHOR - Execute
void	ft_threadexecute(t_process *process,
	void (*f)(t_process *, t_philo *), t_philo *philo)
{
	ft_try(pthread_mutex_lock(&((t_mutex *)process->synchronizer)->mutex));
	(*f)(process, philo);
	ft_try(pthread_mutex_unlock(&((t_mutex *)process->synchronizer)->mutex));
}

//ANCHOR - Thread limit
int	ft_threadlimit(t_process *process, t_philo *philo)
{
	if (philo->data.eat_count == process->params.repetition_num
		&& process->params.repetition_num > 0)
		return (TRUE);
	return (FALSE);
}

//ANCHOR - Create Threads
int	ft_createthread(t_process *process, int count)
{
	process->philo[count].process = process;
	return (
		pthread_create(&process->philo[count].thread, NULL,
			process->main_loop, &process->philo[count])
	);
}

//ANCHOR - Thread join
int	ft_threadjoin(t_process *process, int count)
{
	return (
		pthread_join(process->philo[count].thread,
			(void *)&process->catch_status)
	);
}

//ANCHOR - initthread
void	ft_initprocess(t_process **process, t_philo *philo)
{
	(*process) = philo->process;
	philo->laststatus = STARTED;
	ft_printstatus(*philo);
}
//!SECTION
