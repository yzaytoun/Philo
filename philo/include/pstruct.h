/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pstruct.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:16:19 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/21 17:49:34 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSTRUCT_H		/* pstruct header */
# define PSTRUCT_H

# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

/*Macros*/
# define TRUE 1
# define FALSE !TRUE
# define EATING 11
# define TAKEN_FORK 22
# define SLEEPING 33
# define THINKING 44
# define DIED 55
# define SEC_PER_DAY 86400
# define SEC_PER_HOUR 3600
# define SEC_PER_MIN 60

/*Structs*/
typedef struct s_philo
{
	int			id;
	int			status;
	pthread_t	thread;
	int			fork_left;
	int			fork_right;
	long		timer;
}				t_philo;

typedef struct s_params
{
	int			philo_num;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			repetition_num;
}				t_params;

typedef struct s_fork
{
	int		id;
	int		is_used;
}			t_fork;

typedef struct s_process
{
	pthread_mutex_t	mutex;
	t_philo			*philo;
	t_params		params;
	t_fork			*fork;
}					t_process;

#endif		/* pstruct header */