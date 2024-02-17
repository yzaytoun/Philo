/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxfunc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 18:51:14 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/02/17 19:25:01 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

//SECTION - Auxiliary functions
//ANCHOR - check return value
void	ft_try(int status, const char *func)
{
	const int	errornum = errno;

	if (status)
	{
		printf("status = %d\n", status);
		if (status == 16)
			ft_perror("Resource busy", func);
		else if (status == 11)
			ft_perror("Resource deadlock avoided", func);
		else if (status == 22)
			ft_perror("Invalid argument", func);
		else if (status == 3)
			ft_perror("No such process", func);
		else if (status == SEM_FAILED)
		{
			printf("errno = %d\n", errornum);
			if (errornum == 9)
				ft_perror("No such device or address", func);
			else
				ft_perror("Semaphore Error", func);
		}
		else
			ft_perror("Error", func);
	}
}

//ANCHOR - Catch errors
void	ft_catch(t_process *process)
{
	if (process->catch_status == DIED)
	{
		ft_freeall(&process);
		printf("Thread Died");
		exit(EXIT_SUCCESS);
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