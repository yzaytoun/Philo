/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:51:35 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/27 21:01:23 by yzaytoun         ###   ########.fr       */
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
t_timeval	ft_gettimeofday(void)
{
	struct timeval	time;
	struct timezone	timezone;
	t_timeval		current_time;

	if (gettimeofday(&time, &timezone) != 0)
		ft_perror("Get time of day");
	current_time.currtime
		= time.tv_sec % SEC_PER_DAY
		+ timezone.tz_dsttime * SEC_PER_HOUR
		- timezone.tz_minuteswest * SEC_PER_MIN;
	current_time.currtime = (current_time.currtime + SEC_PER_DAY) % SEC_PER_DAY;
	current_time.usec
		= time.tv_usec % SEC_PER_DAY
		+ timezone.tz_dsttime * SEC_PER_HOUR
		- timezone.tz_minuteswest * SEC_PER_MIN;
	return (current_time);
}

//ANCHOR - printtime
void	ft_printtime(void)
{
	printf("\U0001F570 %d", (int)ft_gettimeofday().usec / 2000);
}

//ANCHOR - Add current time to time limit
void	ft_addcurrenttime(t_params *params)
{
	long	time;

	time = params->time_to_die.usec;
	params->time_to_die.usec = time + ft_gettimeofday().usec;
	time = params->time_to_eat.usec;
	params->time_to_eat.usec = time + ft_gettimeofday().usec;
	time = params->time_to_sleep.usec;
	params->time_to_sleep.usec = time + ft_gettimeofday().usec;
}

//!SECTION