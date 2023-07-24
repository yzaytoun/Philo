/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:51:35 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/24 20:03:59 by yzaytoun         ###   ########.fr       */
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

//ANCHOR - Adjust
void	ft_printtime(void)
{
	struct timeval	time;
	struct timezone	timezone;
	long			current_time;

	if (gettimeofday(&time, &timezone) != 0)
		ft_perror("Get time of day");
	current_time
		= time.tv_sec % SEC_PER_DAY
		+ timezone.tz_dsttime * SEC_PER_HOUR
		- timezone.tz_minuteswest * SEC_PER_MIN;
	current_time = (current_time + SEC_PER_DAY) % SEC_PER_DAY;
	printf("\U0001F570\t%ld:%ld:%ld:%d/t",
		current_time / SEC_PER_HOUR,
		(current_time % SEC_PER_HOUR) / SEC_PER_MIN,
		(current_time % SEC_PER_HOUR) % SEC_PER_MIN,
		time.tv_usec / 1000);
}

//ANCHOR - Set Timer
long	ft_gettime(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

//ANCHOR - Add current time to time limit
void	ft_addcurrenttime(t_params *params)
{
	long	time;

	time = params->time_to_die;
	params->time_to_die = time + ft_gettime();
	time = params->time_to_eat;
	params->time_to_eat = time + ft_gettime();
	time = params->time_to_sleep;
	params->time_to_sleep = time + ft_gettime();
}

//!SECTION