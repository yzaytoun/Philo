/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:51:35 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/09/15 17:49:35 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//SECTION - Time Functions
//ANCHOR - Delay Function
void	ft_delaymil(long miliseconds, t_process *process, t_philo *philo)
{
	const long	start = ft_current_time();

	if (philo != NULL && philo->laststatus == DIED)
		return ;
	while ((ft_current_time() - start) < miliseconds)
	{
		if (process != NULL && philo != NULL)
			ft_isalive(process, philo);
		if (philo != NULL && philo->laststatus == DIED)
			break ;
		usleep(1);
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
