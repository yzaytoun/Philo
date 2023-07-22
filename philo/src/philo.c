/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:56:07 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/22 11:22:02 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//SECTION - Philo
//ANCHOR - Create Philos
static t_philo	*ft_createphilo(size_t size)
{
	t_philo	*philo;

	if (!size)
		return (NULL);
	philo = malloc(sizeof(t_philo) * size);
	if (!philo)
		ft_perror("No philo was created");
	return (philo);
}

//ANCHOR - Create Forks
static t_fork	*ft_createphilo(size_t size)
{
	t_fork	*fork;

	if (!size)
		return (NULL);
	fork = malloc(sizeof(t_fork) * size);
	if (!fork)
		ft_perror("No Forks");
	return (fork);
}

//ANCHOR - Create Process
t_process	*ft_createprocess(t_params params)
{
	t_process	*process;

	if (params.philo_num <= 0)
		return (NULL);
	process = malloc(sizeof(t_process));
	if (!process)
		ft_perror("No process");
	process->params = params;
	process->philo = ft_createphilo(params.philo_num);
	process->fork = ft_createforks(params.philo_num);
	ft_apply(process, ft_assign_ids);
	return (process);
}

//ANCHOR - Free All
void	ft_freeall(t_process **process)
{
	ft_check(pfthread_mutex_destroy(&(*process)->mutex));
	free((*process)->philo);
	free((*process)->fork);
	free((*process));
	pthread_exit(NULL);
}

//ANCHOR - Philo apply
void	*ft_apply(t_process *process, int (*f)(t_process *, int))
{
	int	count;

	count = 1;
	while (count <= process->params.philo_num)
	{
		if ((int)ft_check((*f)(process, count)) == DIED)
			return ((void *)DIED);
		++count;
	}
}

//!SECTION
