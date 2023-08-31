/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:51:35 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/08/31 20:28:23 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//SECTION - Time Functions
//ANCHOR - Delay Function
void	ft_delaymil(int miliseconds)
{
	int	count;

	count = 0;
	if (miliseconds == 0 || !miliseconds)
		return ;
	while (count < miliseconds)
	{
		usleep(100);
		count++;
	}
}

//ANCHOR - Set Timer
long	ft_current_time(void)
{
	struct timeval	time;
	struct timezone	timezone;

	if (gettimeofday(&time, &timezone) != 0)
		ft_perror("Get time of day");
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

//ANCHOR - Add current time to time limit
long	ft_timediff(t_philo *philo, long currtime)
{
	return (
		philo->timer - currtime
	);
}
//!SECTION
