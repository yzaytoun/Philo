/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pstruct.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:16:19 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/26 17:59:39 by yzaytoun         ###   ########.fr       */
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
typedef struct s_timeval
{
	long		currtime;
	long		usec;
}				t_timeval;

typedef struct s_meta /*Meta data about the philo*/
{
	int	eat_count;
	int	sleep_count;
	int	think_count;
}				t_meta;


typedef struct s_fork
{
	int		id;
	int		is_used;
}			t_fork;

typedef struct s_process	t_process;

typedef struct s_philo
{
	int			id;
	t_meta		data;
	int			laststatus;
	pthread_t	thread;
	t_fork		left_fork;
	t_fork		right_fork;
	t_timeval	timer;
	t_process	*process;
}				t_philo;

typedef struct s_params
{
	int			philo_num;
	t_timeval	time_to_die;
	t_timeval	time_to_eat;
	t_timeval	time_to_sleep;
	int			repetition_num;
}				t_params;

struct s_process
{
	pthread_mutex_t	mutex;
	t_philo			*philo;
	t_params		params;
	t_fork			*fork;
};

#endif		/* pstruct header */