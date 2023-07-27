/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 19:49:16 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/27 20:46:03 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//SECTION Threads
//ANCHOR - Execute
void	ft_threadexecute(t_process *process,
	void (*f)(t_process *, int), int philo_id)
{
	ft_try(pthread_mutex_lock(&process->mutex));
	(*f)(process, philo_id);
	ft_try(pthread_mutex_unlock(&process->mutex));
	//ft_try(pthread_detach(process->philo[philo_id].thread));
}

//ANCHOR - Create Threads
int	ft_createthread(t_process *process, int philo_id)
{
	process->philo[philo_id].process = process;
	ft_try(pthread_create(&(process->philo[philo_id].thread), NULL,
			(void *)ft_routine, &process->philo[philo_id]));
	return (EXIT_SUCCESS);
}

//ANCHOR - Detach threads
int	ft_threadjoin(t_process *process, int philo_id)
{
	ft_try(pthread_join(process->philo[philo_id].thread, (void *)
			(uintptr_t) &process->philo[philo_id].laststatus));
	if (process->philo[philo_id].laststatus == DIED)
	{
		ft_printstatus(philo_id, DIED);
		return (DIED);
	}
	return (EXIT_SUCCESS);
}
//!SECTION
