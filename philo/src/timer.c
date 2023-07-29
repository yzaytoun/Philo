/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:51:35 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/28 16:52:02 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//SECTION - Time Functions
//ANCHOR - Delay Function
void	ft_delay(int seconds)
{
	int	counter;
	int	limit;

	if (seconds == 0 || !seconds)
		return ;
	limit = seconds * 1000;
	counter = 0;
	while (counter < limit)
	{
		usleep(seconds);
		++counter;
	}
}

//ANCHOR - Set Timer
long	ft_gettimeofday(void)
{
	struct timeval	time;
	struct timezone	timezone;
	long			current_time;

	if (gettimeofday(&time, &timezone) != 0)
		ft_perror("Get time of day");
	current_time
		= time.tv_usec % SEC_PER_DAY
		+ timezone.tz_dsttime * SEC_PER_HOUR
		- timezone.tz_minuteswest * SEC_PER_MIN;
	return (current_time);
}

//ANCHOR - Add current time to time limit
void	ft_addcurrenttime(t_params *params)
{
	params->start_time = ft_gettimeofday();
	params->time_to_die += params->start_time;
	params->time_to_eat += params->start_time;
	params->time_to_sleep += params->start_time;
}

//!SECTION