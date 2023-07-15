/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:56:07 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/14 17:15:16 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//SECTION - Philo
//ANCHOR - Create Philos
static t_philo	*ft_createphilo(size_t size)
{
	t_philo	philo;

	if (!size)
		return (NULL);
	philo = malloc(sizeof(t_philo) * size);
	if (!philo)
		ft_perror("No philo was created");
	return (philo);
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
	if (process->philo == NULL)
		ft_perror("No philosophers");
	return (process);
}

//ANCHOR - Free All
void	ft_freeall(t_process **process)
{
	pthread_mutex_destroy(&(*process)->mutex);
	free((*process)->philo);
	free((*process));
}

//!SECTION