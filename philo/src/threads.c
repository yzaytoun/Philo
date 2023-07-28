/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 19:49:16 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/28 18:15:37 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//SECTION Threads
//ANCHOR - Execute
void	ft_threadexecute(t_process *process,
	void (*f)(t_process *, int), int philo_id)
{
	ft_try(pthread_mutex_lock(&process->mutex));
	(*f)(process, philo_id);
	ft_try(pthread_mutex_unlock(&process->mutex));
}

//!SECTION
