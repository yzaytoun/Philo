/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:51:35 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/25 20:53:39 by yzaytoun         ###   ########.fr       */
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
	return (current_time);
}

//ANCHOR - Adjust
void	ft_printtime(void)
{
	t_timeval	current_time;

	current_time = ft_gettimeofday();
	printf("\U0001F570 %ld:%ld:%ld:%d",
		current_time.currtime / SEC_PER_HOUR,
		(current_time.currtime % SEC_PER_HOUR) / SEC_PER_MIN,
		(current_time.currtime % SEC_PER_HOUR) % SEC_PER_MIN,
		(int)current_time.usec / 1000);
}

//ANCHOR - Add current time to time limit
void	ft_addcurrenttime(t_params *params)
{
	long	time;

	time = params->time_to_die.currtime;
	params->time_to_die.currtime = time + ft_gettimeofday().currtime;
	time = params->time_to_eat.currtime;
	params->time_to_eat.currtime = time + ft_gettimeofday().currtime;
	time = params->time_to_sleep.currtime;
	params->time_to_sleep.currtime = time + ft_gettimeofday().currtime;
}

//!SECTION