/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:51:35 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/02/12 19:10:39 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//SECTION - Time Functions
//ANCHOR - Delay Function
void	ft_msleep(long miliseconds, t_process *process, t_philo *philo)
{
	const long	starttime = ft_get_current_time();

	if (philo != NULL && philo->laststatus == DIED)
		return ;
	if (process != NULL && philo != NULL)
	{
		while (ft_isalive(process, philo) == TRUE)
		{
			if (ft_timediff(ft_get_current_time(), starttime) == miliseconds)
			{
				ft_threadexecute(process, ft_printstatus, philo);
				break ;
			}
			usleep(50);
		}
	}
	else
		usleep(miliseconds * 1000);
}

//ANCHOR - Set Timer
long	ft_get_current_time(void)
{
	struct timeval	time;
	struct timezone	timezone;
	static long		current_time;

	if (gettimeofday(&time, &timezone) != 0)
		ft_perror("Get time of day");
	current_time = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (current_time);
}

//ANCHOR - Add current time to time limit
long	ft_timediff(long currtime, long starttime)
{
	return (currtime - starttime);
}
//!SECTION
