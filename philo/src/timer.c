/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:51:35 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/20 19:44:39 by yzaytoun         ###   ########.fr       */
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

//!SECTION