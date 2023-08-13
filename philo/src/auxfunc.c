/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxfunc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 18:51:14 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/08/11 18:37:48 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//SECTION - Auxiliary functions
//ANCHOR - check return value
void	ft_try(int status)
{
	if (status)
	{
		printf("status = %d\n", status);
		if (status == 16)
			ft_perror("Resource busy");
		else if (status == 11)
			ft_perror("Resource deadlock avoided");
		else
			ft_perror("Error");
	}
}

//ANCHOR - Catch errors
void	ft_catch(t_process *process)
{
	if (process->catch_status != EXIT_SUCCESS)
	{
		printf("Last status %zu\n", process->catch_status);
		ft_apply(process, ft_threadjoin);
		ft_freeall(&process);
		ft_perror("Error");
	}
}

//ANCHOR - AUX Assign input
void	ft_assign_params(t_params *params, int count, long input)
{
	if (count == 1)
		params->philo_num = input;
	else if (count == 2)
		params->time_to_die = input;
	else if (count == 3)
		params->time_to_eat = input;
	else if (count == 4)
		params->time_to_sleep = input;
	else if (count == 5)
		params->repetition_num = input;
}

//!SECTION