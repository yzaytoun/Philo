/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkthreads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 19:54:58 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/02/24 11:19:36 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//SECTION - Update status
//ANCHOR - Check if all threads are Created
int	ft_all_threadsactive(t_process *process, int counter)
{
	if (process->philo[counter].laststatus == STARTED)
		process->params.philo_status_counter++;
	else if (process->philo[counter].laststatus == DIED)
		process->catch_status = DIED;
	if (process->params.philo_status_counter == process->params.philo_num)
		process->lock = FALSE;
	return (EXIT_SUCCESS);
}

//ANCHOR - Check if all threads are Finished
int	ft_all_threadsfinished(t_process *process, int counter)
{
	if (process->philo[counter].laststatus == DIED)
		process->catch_status = DIED;
	else if (process->philo[counter].laststatus == FINISHED)
		process->params.philo_status_counter++;
	if (process->params.philo_status_counter == process->params.philo_num)
		process->params.all_ate = TRUE;
	return (EXIT_SUCCESS);
}

//ANCHOR - Check if all threads are Alive
int	ft_forcestop(t_process *process, int counter)
{
	process->philo[counter].laststatus = DIED;
	return (EXIT_SUCCESS);
}

//ANCHOR - Check fork locks
int	ft_check_forklocks(t_process *process, int counter)
{
	if (process->fork[counter].is_used == TRUE)
	{
		process->fork[counter].is_used = FALSE;
		ft_try(pthread_mutex_unlock(&process->fork[counter].mutex), FUNC);
	}
	return (EXIT_SUCCESS);
}

//!SECTION