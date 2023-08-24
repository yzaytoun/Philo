/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:25:16 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/08/24 18:00:05 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//SECTION - Mutex
//ANCHOR - Initiate all mutexes 
void	ft_initmutexes(t_process *process)
{
	ft_try(
		pthread_mutex_init(&((t_mutex *)process->synchronizer)->mutex, NULL));
	ft_try(
		pthread_mutex_init(
			&((t_mutex *)process->synchronizer)->main_mutex, NULL));
	ft_apply(process, ft_initforkmutex, APPLY_NO_LOCK);

}

//ANCHOR - Destroy all Mutexes
void	ft_destroy_allmutexes(t_process *process)
{
	ft_apply(process, ft_check_forklocks, APPLY_LOCK);
	ft_try(
		pthread_mutex_destroy(&((t_mutex *)process->synchronizer)->mutex));
	ft_try(
		pthread_mutex_destroy(&((t_mutex *)process->synchronizer)->main_mutex));
	ft_apply(process, ft_destroyforkmutex, APPLY_NO_LOCK);
}

//ANCHOR - Initiate Fork mutexes
int	ft_initforkmutex(t_process *process, int count)
{
	return (pthread_mutex_init(&process->fork[count].mutex, NULL));
}

//ANCHOR - Destroy fork mutexes
int	ft_destroyforkmutex(t_process *process, int count)
{
	return (pthread_mutex_destroy(&process->fork[count].mutex));
}

//!SECTION