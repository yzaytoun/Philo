/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:13:03 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/02/24 14:13:25 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
void	ft_apply(t_process *process, int (*f)(t_process *, int))
{
	int	count;

	count = 0;
	process->params.philo_status_counter = 0;
	while (count < process->params.philo_num)
	{
		ft_try((*f)(process, count), FUNC);
		if (process->catch_status == DIED)
			break ;
		else if (process->catch_status == FINISHED)
			process->params.philo_status_counter++;
		++count;
	}
	if (process->params.philo_status_counter == process->params.philo_num)
		process->params.all_ate = TRUE;
}

//!SECTION