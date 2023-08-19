/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:59:32 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/08/14 20:26:03 by yzaytoun         ###   ########.fr       */
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

typedef struct s_semaphor
{
    sem_t     main_semaphor;
    sem_t     semaphor;
}               t_semaphor;

#endif