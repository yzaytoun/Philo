/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:13:03 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/27 19:08:06 by yzaytoun         ###   ########.fr       */
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

//!SECTION