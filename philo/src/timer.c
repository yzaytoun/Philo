/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:51:35 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/17 20:43:29 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//SECTION - Time Functions
//ANCHOR - Delay Function
void	ft_delay(void)
{
	int	counter;

	counter = 0;
	while (counter < 50000)
	{
		usleep(10);
		++counter;
	}
}

//ANCHOR - Adjust
void	ft_adjust(struct timeval *time)
{
	(void)gettimeofday(time, NULL);
	printf("%ld:", (time->tv_sec/1000000/60));
	printf("%ld", (time->tv_sec%3600)/60);
	printf(":%d\n", time->tv_usec % 60);
}

//!SECTION