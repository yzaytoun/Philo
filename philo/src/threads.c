/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 19:49:16 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/08/05 17:11:17 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//SECTION Threads
//ANCHOR - Execute
void	ft_threadexecute(t_process *process,
	void (*f)(t_process *, t_philo *), t_philo *philo)
{
	ft_try(pthread_mutex_lock(&process->mutex));
	(*f)(process, philo);
	ft_try(pthread_mutex_unlock(&process->mutex));
}

//ANCHOR - Thread limit
int	ft_threadlimit(t_process *process, t_philo *philo)
{
	if (philo->data.eat_count == process->params.repetition_num
		&& process->params.repetition_num > 0)
		return (TRUE);
	return (FALSE);
}

//ANCHOR - Thread join
int	ft_threadjoin(t_process *process, int count)
{
	void	*status;

	ft_try(pthread_join(process->philo[count].thread, &status));
	if ((size_t)status == DIED)
		process->catch_status = DIED;
	return (EXIT_SUCCESS);
}

//ANCHOR - Thread detach
int	ft_detachthread(t_process *process, int count)
{
	return (pthread_detach(process->philo[count].thread));
}

//!SECTION
