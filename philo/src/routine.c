/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:33:36 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/21 18:05:46 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//SECTION - Routine Function
//ANCHOR - Get forks
static void	ft_getforks(t_philo *philo, t_process *process)
{
	int	count;

	count = 0;
	while (count < process->params.philo_num)
	{
		if (process->fork[count].is_used == FALSE)
			philo->fork_left = process->fork[count].id;
	}
}

//ANCHOR - Routine
static void	ft_lockthread(t_philo *philo, t_process *process)
{
	//philo->timer = ft_settimer();
	ft_check(pthread_mutex_lock(&(process->mutex)));
	while (philo->timer < process->params.time_to_eat)
	{
		ft_printstatus(*philo);
		ft_delay(10);
		++philo->timer;
	}
	ft_check(pthread_mutex_unlock(&(process->mutex)));
	ft_check(pthread_detach(philo->thread));
}

void	ft_routine(t_process *process, t_philo *philo)
{
	int	count;

	ft_getforks(philo, process);
	if (philo->fork_left == TRUE && philo->fork_right == TRUE)
		ft_lockthread(philo, process);
}

//ANCHOR - Run
void	ft_run(t_process *process)
{
	if (!process || process->philo == NULL)
		return ;
	ft_check(pthread_mutex_init(&process->mutex, NULL));
	ft_apply(process->philo, ft_createthread);
	ft_apply(process->philo, ft_threadjoin);
}

//!SECTION