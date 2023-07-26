/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:45:56 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/26 18:14:55 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//SECTION - Execute
//ANCHOR - Eat
void	ft_eat(t_process *process, int philo_id)
{
	if (process->philo->left_fork.is_used == TRUE
		&& process->philo->right_fork.is_used == TRUE)
	{
		ft_printstatus(philo_id, EATING);
		while (process->philo[philo_id].timer.currtime
			< process->params.time_to_eat.currtime)
		{
			ft_delay(5);
			process->philo[philo_id].timer.currtime++;
		}
		process->philo[philo_id].data.eat_count++;
	}
}

//ANCHOR - Sleep
void	ft_sleep(t_process *process, int philo_id)
{
	if (process->philo->left_fork.is_used == TRUE
		&& process->philo->right_fork.is_used == TRUE
		&& process->philo[philo_id].laststatus == EATING)
	{
		ft_printstatus(process->philo->id, SLEEPING);
		while (process->philo[philo_id].timer.currtime
			< process->params.time_to_sleep.currtime)
		{
			ft_delay(5);
			process->philo[philo_id].timer.currtime++;
		}
		process->philo->left_fork.is_used = FALSE;
		process->philo->right_fork.is_used = FALSE;
	}
	else
		ft_printstatus(philo_id, THINKING);
	process->philo[philo_id].data.sleep_count++;
}

//ANCHOR - Is alive
void	ft_isalive(t_process *process, int philo_id)
{
	if (process->philo[philo_id].timer.currtime
		< process->params.time_to_die.currtime * 1000)
		process->philo[philo_id].laststatus = DIED;
}

//!SECTION