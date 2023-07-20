/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 19:49:16 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/20 20:47:23 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//SECTION Threads
//ANCHOR - Create Threads
int	ft_createthread(t_process *process, int philo_id)
{
	ft_check(pthread_create(&(process->philo[philo_id].thread), NULL,
			(void *)ft_routine, process));
	return (TRUE);
}

//ANCHOR - Detach threads
int	ft_threadjoin(t_process *process, int philo_id)
{
	ft_check(pthread_detach(process->philo[philo_id].thread));
	return (TRUE);
}
//!SECTION
