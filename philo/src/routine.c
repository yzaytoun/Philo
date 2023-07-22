/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:33:36 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/22 11:26:28 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//SECTION - Routine Function
//ANCHOR - Validate fork
static int	ft_validfork(int philo_fork, int fork_id)
{
	return (philo_fork - fork_id + 1);
}

//ANCHOR - Get forks
static void	ft_getforks(t_philo *philo, t_process *process)
{
	int	count;

	count = 0;
	while (count < process->params.philo_num)
	{
		if (process->fork[count].is_used == FALSE
			&& ft_validfork(philo->left_fork.id
				, process->fork[count].id) == TRUE)
		{
			philo->left_fork.is_used = TRUE;
			ft_printtstatus(philo->id, TAKEN_FORK);
		}
		else if (process->fork[count].is_used == FALSE
			&& ft_validfork(philo->right_fork.id
				, process->fork[count].id) == TRUE)
		{
			philo->right_fork.is_used = TRUE;
			ft_printtstatus(philo->id, TAKEN_FORK);
		}
	}
}

//ANCHOR - Routine
static void	ft_lockthread(t_philo *philo, t_process *process)
{
	//philo->timer = ft_settimer();
	ft_check(pthread_mutex_lock(&(process->mutex)));
	while (philo->timer < process->params.time_to_eat)
	{
		ft_delay(10);
		++philo->timer;
	}
	ft_check(pthread_mutex_unlock(&(process->mutex)));
	ft_check(pthread_detach(philo->thread));
	return ;
}

void	*ft_routine(t_process *process, t_philo *philo)
{
	int	count;

	ft_getforks(philo, process);
	if (philo->left_fork.is_used == TRUE
		&& philo->right_fork.is_used == TRUE)
	{
		ft_printstatus(philo->id, EATING);
		ft_lockthread(philo, process);
		ft_printstatus(philo->id, SLEEPING);
	}
	else
		ft_printstatus(philo->id, THINKING);
	return ((void *)philo->status);
}

//ANCHOR - Run
int	ft_run(t_process *process)
{
	if (!process || process->philo == NULL)
		return ;
	ft_check(pthread_mutex_init(&process->mutex, NULL));
	ft_apply(process->philo, ft_createthread);
	if ((int)ft_apply(process->philo, ft_threadjoin) == DIED)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

//!SECTION