/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:33:36 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/17 17:57:45 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//SECTION - Routine Function
//ANCHOR - Create Threads
void	ft_createthread(t_philo *philo)
{
	ft_check(pthread_create(&(philo->thread), NULL,
			(void *)ft_routine, &(philo->status)));
}

//ANCHOR - Routine
void	ft_routine(t_process *process)
{
	(void)process;
	printf("Routine Function");
}

//ANCHOR - Run
void	ft_run(t_process *process)
{
	if (!process)
		return ;
	ft_check(pthread_mutex_init(&process->mutex, NULL));
	ft_philo_apply(process->philo, ft_createthread, process->params.philo_num);
}

//!SECTION