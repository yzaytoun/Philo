/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:45:56 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/08/21 18:23:40 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//SECTION - Execute
//ANCHOR - Eat
void	ft_eat(t_process *process, t_philo *philo)
{
	const int	timelimit = philo->timer + process->params.time_to_eat;

	if (philo->left_fork.is_used == TRUE
		&& philo->right_fork.is_used == TRUE)
	{
		philo->laststatus = EATING;
		ft_printstatus(*philo);
		while (philo->timer < timelimit)
			philo->timer += ft_gettimeofday();
		philo->data.eat_count++;
		process->dropforks(process, philo);
	}
}

//ANCHOR - Sleep
void	ft_sleep(t_process *process, t_philo *philo)
{
	const int	timelimit = philo->timer + process->params.time_to_sleep;

	if (philo->laststatus == EATING)
	{
		philo->laststatus = SLEEPING;
		ft_printstatus(*philo);
		while (philo->timer < timelimit)
			philo->timer += ft_gettimeofday();
		philo->data.sleep_count++;
	}
}

//ANCHOR - Is alive
void	ft_isalive(t_process *process, t_philo *philo)
{
	if (philo->timer >= process->params.time_to_die)
	{
		philo->laststatus = DIED;
		ft_printstatus(*philo);
	}
}

//ANCHOR - Increment loop
void	ft_addtime(t_process *process, t_philo *philo)
{
	(void)process;
	philo->timer += ft_gettimeofday();
}
//!SECTION