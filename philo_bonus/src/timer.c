/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:51:35 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/02/17 19:25:34 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

//SECTION - Time Functions
//ANCHOR - Delay Function
void	ft_msleep(long miliseconds, t_process *process, t_philo *philo)
{
	const long	start_time = ft_get_current_time();

	if (philo != NULL && philo->laststatus == DIED)
		return ;
	if (process != NULL && philo != NULL)
	{
		while (ft_time_diff(ft_get_current_time(), start_time) < miliseconds)
		{
			if (ft_isalive(process, philo) == FALSE)
				break ;
			usleep(10);
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

	if (gettimeofday(&time, &timezone) != 0)
		ft_perror("Get time of day", FUNC);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
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
