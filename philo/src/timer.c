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
	if (philo != NULL && philo->laststatus == DIED)
		return ;
	if (process != NULL && philo != NULL)
	{
		//time add(philo->timer + miliseconds) is more than time_to_die
		// break; AND log dead
		if (miliseconds)
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
long	ft_time_add(long first_time, long second_time)
{
	return (first_time + second_time);
}

//ANCHOR - current time to time limit
long	ft_time_diff(long first_time, long second_time)
{
	return (first_time - second_time);
}
//!SECTION
