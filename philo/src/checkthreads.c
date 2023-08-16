/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updatestatus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 19:54:58 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/08/08 20:08:50 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//SECTION - Update status
//ANCHOR - Check if all threads are Created
int	ft_all_threadsactive(t_process *process, int counter)
{
	if (process->philo[counter].laststatus == STARTED)
		process->params.philo_status_counter++;
	if (process->params.philo_status_counter == process->params.philo_num)
	{
		process->lock = FALSE;
		return (TRUE);
	}
	return (FALSE);
}

//ANCHOR - Check if all threads are Alive
int	ft_check_deadthread(t_process *process, int counter)
{
	if (process->philo[counter].laststatus == DIED)
	{
		process->catch_status = DIED;
		return (TRUE);
	}
	return (FALSE);
}

//ANCHOR - Check fork locks
int	ft_check_forklocks(t_process *process, int counter)
{
	if (process->fork[counter].is_used == TRUE)
	{
		process->fork[counter].is_used = FALSE;
		ft_try(pthread_mutex_unlock(&process->fork[counter].mutex));
	}
	return (FALSE);
}

//ANCHOR - Update status main
void	ft_threadchecker(t_process *process, int (*func)(t_process *, int))
{
	ft_try(pthread_mutex_lock(&((t_mutex *)process->synchronizer)->main_mutex));
	process->counter = 0;
	process->params.philo_status_counter = 0;
	while (process->counter < process->params.philo_num)
	{
		if ((*func)(process, process->counter) == TRUE)
		{
			ft_try(pthread_mutex_unlock(&((t_mutex *)process->synchronizer)->main_mutex));
			return ;
		}
		process->counter++;
	}
	ft_try(pthread_mutex_unlock(&((t_mutex *)process->synchronizer)->main_mutex));
}

//!SECTION