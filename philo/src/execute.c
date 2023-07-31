/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:45:56 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/31 18:18:35 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//SECTION - Execute
//ANCHOR - Eat
void	ft_eat(t_process *process, int philo_id)
{
	if (process->philo[philo_id].left_fork.is_used == TRUE
		&& process->philo[philo_id].right_fork.is_used == TRUE)
	{
		ft_printstatus(process->philo[philo_id], EATING);
		while (process->philo[philo_id].timer
			< process->params.time_to_eat)
		{
			ft_delay(5);
			process->philo[philo_id].timer++;
		}
		process->philo[philo_id].data.eat_count++;
		process->philo[philo_id].laststatus = EATING;
	}
}

//ANCHOR - Sleep
void	ft_sleep(t_process *process, int philo_id)
{
	if (process->philo[philo_id].left_fork.is_used == TRUE
		&& process->philo[philo_id].right_fork.is_used == TRUE
		&& process->philo[philo_id].laststatus == EATING)
	{
		ft_printstatus(process->philo[philo_id], SLEEPING);
		while (process->philo[philo_id].timer
			< process->params.time_to_sleep)
		{
			ft_delay(5);
			process->philo[philo_id].timer++;
		}
		process->philo[philo_id].left_fork.is_used = FALSE;
		process->philo[philo_id].right_fork.is_used = FALSE;
	}
	else
		ft_printstatus(process->philo[philo_id], THINKING);
	process->philo[philo_id].data.sleep_count++;
}

//ANCHOR - Is alive
void	ft_isalive(t_process *process, int philo_id)
{
	if (process->philo[philo_id].timer
		< (process->params.time_to_die))
		process->philo[philo_id].laststatus = DIED;
}

//!SECTION