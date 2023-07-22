/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 19:49:16 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/22 11:18:04 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//SECTION Threads
//ANCHOR - Create Threads
int	ft_createthread(t_process *process, int philo_id)
{
	ft_check(pthread_create(&(process->philo[philo_id].thread), NULL,
			(void *)ft_routine, process));
	return (EXIT_SUCCESS);
}

//ANCHOR - Detach threads
int	ft_threadjoin(t_process *process, int philo_id)
{
	ft_check(pthread_join(process->philo[philo_id].thread,
			(int) process->philo->status));
	if (process->philo->status == DIED)
	{
		ft_printstatus(philo_id, DIED);
		return (DIED);
	}
	return (EXIT_SUCCESS);
}
//!SECTION
