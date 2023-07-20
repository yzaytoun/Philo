/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:33:36 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/20 21:03:18 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//SECTION - Routine Function
//ANCHOR - Get forks
static void	ft_getforks(t_philo *philo, int *forks)
{
	int	count;

	count = 0;
	while(count < philo_num)
	{
		if (forks[count] == FALSE)
			philo->fork_left = fork[count].id;
	}
}

//ANCHOR - Routine
static void	ft_lockthread(t_process *process, int philo_id)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	ft_check(pthread_mutex_lock(&(process->mutex)));
	while (current_time.tv_sec < process->params.time_to_eat)
	{
		ft_printstatus(process->philo[philo_id]);
		ft_delay(10);
		++current_time.tv_sec;
	}
	ft_check(pthread_mutex_unlock(&(process->mutex)));
	ft_check(pthread_detach(process->philo[philo_id].thread));
}

void	ft_routine(t_process *process)
{
	int	count;

	ft_getforks(process->philo[num]);
	if (process->philo[])
		ft_lockthread()
	++count;
}

//ANCHOR - Run
void	ft_run(t_process *process)
{
	if (!process || process->philo == NULL)
		return ;
	ft_check(pthread_mutex_init(&process->mutex, NULL));
	ft_philo_apply(process->philo, ft_createthread);
	ft_philo_apply(process->philo, ft_threadjoin);
}

//!SECTION