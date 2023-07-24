/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:33:36 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/24 18:19:00 by yzaytoun         ###   ########.fr       */
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
			ft_printstatus(philo->id, TAKEN_FORK);
		}
		else if (process->fork[count].is_used == FALSE
			&& ft_validfork(philo->right_fork.id
				, process->fork[count].id) == TRUE)
		{
			philo->right_fork.is_used = TRUE;
			ft_printstatus(philo->id, TAKEN_FORK);
		}
	}
}

//ANCHOR - Routine
static void	ft_lockthread(t_philo *philo, t_process *process)
{
	long	timelimit;

	philo->timer = ft_settimer();
	timelimit = process->params.time_to_eat + philo->timer;
	while (philo->timer < timelimit)
		++philo->timer;
}

void	*ft_routine(t_philo *philo)
{
	t_process	*process;

	process = philo->process;
	ft_getforks(philo, process);
	if (philo->left_fork.is_used == TRUE
		&& philo->right_fork.is_used == TRUE)
	{
		ft_printstatus(philo->id, EATING);
		ft_lockthread(philo, process);
		ft_printstatus(philo->id, SLEEPING);
		philo->left_fork.is_used = FALSE;
		philo->right_fork.is_used = FALSE;
		ft_delay(10);
		ft_printstatus(philo->id, THINKING);
	}
	else
		ft_printstatus(philo->id, THINKING);
	ft_check(pthread_mutex_unlock(&(process->mutex)));
	ft_check(pthread_detach(philo->thread));
	return ((void *)(uintptr_t)philo->status);
}

//ANCHOR - Run
int	ft_run(t_process *process)
{
	if (!process || process->philo == NULL)
		return (EXIT_FAILURE);
	ft_check(pthread_mutex_init(&process->mutex, NULL));
	ft_apply(process, ft_createthread);
	if ((int)ft_apply(process, ft_threadjoin) == DIED)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

//!SECTION