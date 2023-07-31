/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:13:03 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/31 19:03:56 by yzaytoun         ###   ########.fr       */
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

//ANCHOR - Create Threads
int	ft_createthread(t_process *process, int count)
{
	process->philo[count].process = process;
	ft_try(pthread_create(&process->philo[count].thread, NULL,
			(void *)ft_routine, &process->philo[count]));
	ft_try(pthread_join(process->philo[count].thread, (void *)
			(uintptr_t) &process->philo[count].laststatus));
	return (process->philo[count].laststatus);
}

//ANCHOR - Update timers and timelimits
int	ft_updatetimer(t_process *process, int count)
{
	process->philo[count].timer = process->params.start_time;
	return (EXIT_SUCCESS);
}

//ANCHOR - Initiate Fork mutexes
int	ft_initmutex(t_process *process, int count)
{
	return (pthread_mutex_init(&process->fork[count].mutex, NULL));
}

//ANCHOR - Destroy fork mutexes
int	ft_destroymutex(t_process *process, int count)
{
	return (pthread_mutex_destroy(&process->fork[count].mutex));
}
//!SECTION