/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:33:36 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/21 20:19:27 by yzaytoun         ###   ########.fr       */
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
			philo->left_fork.is_used = TRUE;
		else if (process->fork[count].is_used == FALSE
			&& ft_validfork(philo->right_fork.id
				, process->fork[count].id) == TRUE)
			philo->right_fork.is_used = TRUE;
	}
}

//ANCHOR - Routine
static void	ft_lockthread(t_philo *philo, t_process *process)
{
	//philo->timer = ft_settimer();
	ft_check(pthread_mutex_lock(&(process->mutex)));
	philo->status = EATING;
	while (philo->timer < process->params.time_to_eat)
	{
		ft_printstatus(*philo);
		ft_delay(10);
		++philo->timer;
	}
	ft_check(pthread_mutex_unlock(&(process->mutex)));
	ft_check(pthread_detach(philo->thread));
}

void	ft_routine(t_process *process, t_philo *philo)
{
	int	count;

	ft_getforks(philo, process);
	if (philo->left_fork.is_used == TRUE
		&& philo->right_fork.is_used == TRUE)
		ft_lockthread(philo, process);
}

//ANCHOR - Run
void	ft_run(t_process *process)
{
	if (!process || process->philo == NULL)
		return ;
	ft_check(pthread_mutex_init(&process->mutex, NULL));
	ft_apply(process->philo, ft_createthread);
	ft_apply(process->philo, ft_threadjoin);
}

//!SECTION