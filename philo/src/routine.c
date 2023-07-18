/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:33:36 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/18 20:34:52 by yzaytoun         ###   ########.fr       */
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
	int	count;

	count = 0;
	while (count < process->params.philo_num)
	{
		ft_printtime();
		ft_delay();
		++count;
	}
	printf("Routine Function");
}

//ANCHOR - Run
void	ft_run(t_process *process)
{
	if (!process || process->philo == NULL)
		return ;
	ft_check(pthread_mutex_init(&process->mutex, NULL));
	ft_philo_apply(process->philo, ft_createthread, process->params.philo_num);
	ft_philo_apply(process->philo, ft_createthread, process->params.philo_num);
}

//!SECTION