/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:13:03 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/26 17:59:39 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//SECTION - Apply
//ANCHOR - Assign ids
int	ft_assign_ids(t_process *process, int philo_id)
{
	process->philo[philo_id].id = philo_id;
	process->fork[philo_id].id = philo_id;
	process->philo[philo_id].left_fork.id = philo_id;
	if (philo_id == 1)
		process->philo[philo_id].right_fork.id = process->params.philo_num;
	else
		process->philo[philo_id].right_fork.id
			= (process->params.philo_num + philo_id - 1)
			- process->params.philo_num;
	return (EXIT_SUCCESS);
}


//ANCHOR - Update timers and timelimits
int	ft_updatetimer(t_process *process, int philo_id)
{
	process->philo[philo_id].timer = ft_gettimeofday();
	return (EXIT_SUCCESS);
}

//NOTE - AUX functions
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
		params->time_to_die.currtime = input * 1000;
	else if (count == 3)
		params->time_to_eat.currtime = input * 1000;
	else if (count == 4)
		params->time_to_sleep.currtime = input * 1000;
	else if (count == 5)
		params->repetition_num = input;
}
//!SECTION