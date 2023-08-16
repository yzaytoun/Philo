/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 19:19:47 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/08/14 20:31:44 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

//SECTION - Main Bonus Loop
//ANCHOR - Routine
static void	ft_routine(void)
{
	/*Do nothting*/
}

//ANCHOR - Run loop
void	ft_run(t_process *process)
{
	if (!process || process->params.philo_num <= 0)
		return ;
	process->synchronizer = malloc(sizeof(t_semaphor));
	if (!process->synchronizer)
		return ;
	process->main_loop = ft_routine;
	((t_semaphor *)process->synchronizer)->semaphor
		= sem_open("/new_sem", O_CREAT, 0644, BUFSIZ);
	ft_try(sem_wait(((t_semaphor *)process->synchronizer)->semaphor));
	ft_apply(process, ft_createthread);
	ft_apply(process, ft_threadjoin);
	ft_try(sem_close(((t_semaphor *)process->synchronizer)->semaphor));
	ft_try(sem_unlink(((t_semaphor *)process->synchronizer)->semaphor));
}
//!SECTION