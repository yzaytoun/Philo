/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 19:49:16 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/08/31 20:16:30 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//SECTION - Routine Function
//ANCHOR - Drop forks
void	ft_dropforks(t_process *process, t_philo *philo)
{
	ft_try(
		pthread_mutex_unlock(&process->fork[philo->left_fork.id - 1].mutex)
		);
	ft_try(
		pthread_mutex_unlock(&process->fork[philo->right_fork.id - 1].mutex)
		);
	process->fork[philo->left_fork.id - 1].is_used = FALSE;
	process->fork[philo->right_fork.id - 1].is_used = FALSE;
	philo->left_fork.is_used = FALSE;
	philo->right_fork.is_used = FALSE;
}

//ANCHOR - Take Fork
static void	ft_takefork(t_process *process, t_philo *philo, int fork_side)
{
	if (fork_side == LEFT)
	{
		philo->left_fork.is_used = TRUE;
		process->fork[process->counter].is_used = TRUE;
		philo->laststatus = TAKEN_FORK;
	}
	else if (fork_side == RIGHT)
	{
		philo->right_fork.is_used = TRUE;
		process->fork[process->counter].is_used = TRUE;
		philo->laststatus = TAKEN_FORK;
	}
}

//ANCHOR - Validate fork
static int
	ft_validfork(t_process *process, int philo_id, int counter, int fork_side)
{
	if (fork_side == LEFT)
	{
		return (process->philo[philo_id - 1].left_fork.id
			- process->fork[counter].id + 1);
	}
	else if (fork_side == RIGHT)
	{
		return (process->philo[philo_id - 1].right_fork.id
			- process->fork[counter].id + 1);
	}
	return (FALSE);
}

//ANCHOR - Get forks
void	ft_getforks(t_process *process, t_philo *philo)
{
	process->counter = 0;
	if (philo->data.eat_count > 0)
		ft_delaymil(100);
	while (process->counter < process->params.philo_num)
	{
		if (process->fork[process->counter].is_used == FALSE
			&& ft_validfork(process, philo->id, process->counter, LEFT) == TRUE)
		{
			ft_takefork(process, philo, LEFT);
			ft_try(pthread_mutex_lock(&process->fork[process->counter].mutex));
			ft_printstatus(
				*philo, ft_timediff(philo, process->params.start_time));
		}
		else if (process->fork[process->counter].is_used == FALSE
			&& ft_validfork(process, philo->id, process->counter, RIGHT)
			== TRUE)
		{
			ft_takefork(process, philo, RIGHT);
			ft_try(pthread_mutex_lock(&process->fork[process->counter].mutex));
			ft_printstatus(
				*philo, ft_timediff(philo, process->params.start_time));
		}
		process->counter++;
	}
}
//!SECTION
