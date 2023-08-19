/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:59:32 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/08/19 18:30:20 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include "philo.h"
# include <sys/stat.h>
# include <sys/sem.h>
# include <sys/types.h>
# include <semaphore.h>
# include <fcntl.h>
# include <signal.h>

typedef struct s_semaphor
{
	sem_t		main_semaphor;
	sem_t		forks_semaphor;
	int			sem_value;
}				t_semaphor;

/*Bonus Functions*/
int		ft_create_childprocess(t_process *process, int count);
int		ft_wait_childprocess(t_process *process, int count);

void	ft_semexecute(t_process *process, t_philo *philo,
			void (*function)(t_process *, t_philo *));
void	ft_dropforks_sem(t_process *process, t_philo *philo);

#endif