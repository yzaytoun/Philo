/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:13:03 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/21 20:09:29 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//SECTION - Apply
//ANCHOR - Assign ids
int	ft_assign_ids(t_process *process, int philo_id)
{
	process->philo[philo_id].id = philo_id + 1;
	process->fork[philo_id].id = philo_id + 1;
	process->philo[philo_id].left_fork.id = philo_id + 1;
	if (philo_id != 0)
		process->philo[philo_id].right_fork.id = process->params.philo_num;
	else
		process->philo[philo_id].right_fork.id
			= (process->params.philo_num + philo_id)
			- process->params.philo_num;
	return (TRUE);
}

//ANCHOR - Unlock mutex
void	ft_check(int status)
{
	if (status)
	{
		ft_perror("pthread_mutex_unlock");
		pthread_exit(NULL);
	}
}

//!SECTION