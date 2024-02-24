/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:13:03 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/02/24 10:38:04 by yzaytoun         ###   ########.fr       */
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
	process->philo[count].params = process->params;
	return (EXIT_SUCCESS);
}

//ANCHOR - Philo apply
void	ft_apply(t_process *process, int (*f)(t_process *, int), int lock)
{
	int	count;

	count = 0;
	if (lock == APPLY_LOCK)
		ft_try(
			pthread_mutex_lock(
				&((t_mutex *)process->synchronizer)->main_mutex), FUNC);
	process->params.philo_status_counter = 0;
	while (count < process->params.philo_num)
	{
		ft_try((*f)(process, count), FUNC);
		if (f != NULL && ((*f) == ft_forcestop)
			&& process->catch_status == DIED)
			break ;
		++count;
	}
	if (lock == APPLY_LOCK)
		ft_try(
			pthread_mutex_unlock(
				&((t_mutex *)process->synchronizer)->main_mutex), FUNC);
}

//!SECTION