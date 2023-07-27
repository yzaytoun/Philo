/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxfunc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 18:51:14 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/27 20:52:18 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//SECTION - Auxiliary functions
//ANCHOR - Bzero
void	ft_bzero(void *pointer, size_t n)
{
	unsigned char	*p;

	p = pointer;
	while (n--)
		*p++ = 0;
}

//ANCHOR - check return value
void	*ft_try(int laststatus)
{
	if (laststatus == DIED)
		return ((void *)DIED);
	else if (laststatus && laststatus != DIED)
	{
		ft_perror("Error");
		printf("Status -> %d\n", laststatus);
	}
	return (NULL);
}

//ANCHOR - AUX Assign input
void	ft_assign_params(t_params *params, int count, long input)
{
	if (count == 1)
		params->philo_num = input;
	else if (count == 2)
		params->time_to_die.usec = input;
	else if (count == 3)
		params->time_to_eat.usec = input;
	else if (count == 4)
		params->time_to_sleep.usec = input;
	else if (count == 5)
		params->repetition_num = input;
}

//!SECTION