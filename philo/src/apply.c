/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:13:03 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/08/24 17:56:40 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//SECTION - Apply
//ANCHOR - Assign ids
int	ft_assign_ids(t_process *process, int count)
{
	process->philo[count].id = count + 1;
	process->fork[count].id = count + 1;
	process->philo[count].left_fork.id = count + 1;
	if (count == 0)
		process->philo[count].right_fork.id = process->params.philo_num;
	else
		process->philo[count].right_fork.id
			= (process->params.philo_num + count)
			- process->params.philo_num;
	return (EXIT_SUCCESS);
}

//ANCHOR - Philo apply
void	ft_apply(t_process *process, int (*f)(t_process *, int), int lock)
{
	if (lock == APPLY_LOCK)
	{
		ft_try(
			pthread_mutex_lock(
				&((t_mutex *)process->synchronizer)->main_mutex));
	}
	process->counter = 0;
	process->params.philo_status_counter = 0;
	while (process->counter < process->params.philo_num)
	{
		ft_try((*f)(process, process->counter));
		if (process->catch_status == DIED)
			break ;
		++process->counter;
	}
	if (lock == APPLY_LOCK)
	{
		ft_try(
			pthread_mutex_unlock(
				&((t_mutex *)process->synchronizer)->main_mutex));
	}
}

//!SECTION