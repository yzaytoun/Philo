/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 19:49:16 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/08/08 21:08:15 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//SECTION Threads
//ANCHOR - Execute
void	ft_threadexecute(t_process *process,
	void (*f)(t_process *, t_philo *), t_philo *philo)
{
	ft_try(pthread_mutex_lock(&process->mutex));
	(*f)(process, philo);
	ft_try(pthread_mutex_unlock(&process->mutex));
}

//ANCHOR - Thread limit
int	ft_threadlimit(t_process *process, t_philo *philo)
{
	if (philo->data.eat_count == process->params.repetition_num
		&& process->params.repetition_num > 0)
		return (TRUE);
	return (FALSE);
}

//ANCHOR - Thread join
int	ft_threadjoin(t_process *process, int count)
{
	size_t	status;

	ft_try(pthread_join(process->philo[count].thread, (void *)(&status)));
	if (status)
		if (status == DIED)
			process->catch_status = DIED;
	return (EXIT_SUCCESS);
}

//ANCHOR - Check lock
void	ft_startroutine(t_process *process, t_philo *philo)
{
	ft_try(pthread_mutex_lock(&process->main_mutex));
	if (process->lock == FALSE)
	{
		ft_try(pthread_mutex_unlock(&process->main_mutex));
		ft_routine(process, philo);
		return ;
	}
	ft_try(pthread_mutex_unlock(&process->main_mutex));
}

//ANCHOR - initthread
void	ft_init_thread(t_process *process, t_philo *philo)
{
	(void)process;
	philo->laststatus = STARTED;
	ft_printstatus(*philo);
}
//!SECTION
