/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:56:07 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/08/24 18:50:26 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//SECTION - Philo
//ANCHOR - Create Philos
static t_philo	*ft_createphilo(size_t size)
{
	t_philo	*philo;

	if (!size || size == 0)
		return (NULL);
	philo = malloc(sizeof(t_philo) * size);
	if (!philo)
		ft_perror("Philos", FUNC);
	memset(philo, 0, sizeof(t_philo) * size);
	return (philo);
}

//ANCHOR - Create Forks
static t_fork	*ft_createforks(size_t size)
{
	t_fork	*fork;

	if (!size || size == 0)
		return (NULL);
	fork = malloc(sizeof(t_fork *) * size);
	if (!fork)
		ft_perror("Forks", FUNC);
	memset(fork, 0, sizeof(t_fork) * size);
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
		ft_perror("Process structure", FUNC);
	memset(process, 0, sizeof(t_process));
	process->params = params;
	process->philo = ft_createphilo(params.philo_num);
	process->fork = ft_createforks(params.philo_num);
	ft_apply(process, ft_assign_ids, APPLY_NO_LOCK);
	return (process);
}

//ANCHOR - Free All
void	ft_freeall(t_process **process)
{
	free((*process)->philo);
	free((*process)->fork);
	free((*process)->synchronizer);
	free((*process));
}

//!SECTION
