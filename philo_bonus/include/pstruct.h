/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pstruct.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:16:19 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/02/17 19:24:47 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSTRUCT_H		/* pstruct header */
# define PSTRUCT_H

# include <stdio.h>
# include <sys/time.h>
# include <sys/stat.h>
# include <sys/sem.h>
# include <sys/types.h>
# include <semaphore.h>
# include <fcntl.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

/*Macros*/
# define APPLY_LOCK 1
# define APPLY_NO_LOCK 0
# define SEC_PER_DAY 86400
# define SEC_PER_HOUR 3600
# define SEC_PER_MIN 60
# define LEFT 0
# define RIGHT 1
# define FUNC __func__
# ifndef SEM_FAILED
#  define SEM_FAILED -1
# endif

/*Structs*/
typedef struct s_process	t_process;

typedef enum s_status
{
	STARTED = 1000,
	EATING = 1100,
	TAKEN_FORK = 2200,
	SLEEPING = 3300,
	THINKING = 4400,
	DIED = 5500,
	FINISHED
}			t_status;

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_params
{
	int			philo_num;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	int			repetition_num;
	long		start_time;
	int			philo_status_counter;
	t_bool		all_ate;
}	t_params;

typedef struct s_meta /*Meta data about the philo*/
{
	int	eat_count;
	int	sleep_count;
	int	think_count;
}				t_meta;

typedef struct s_fork
{
	int				id;
	t_bool			is_used;
	pthread_mutex_t	mutex;
}			t_fork;

typedef struct s_philo
{
	int			id;
	t_meta		data;
	t_status	laststatus;
	pthread_t	thread;
	t_fork		left_fork;
	t_fork		right_fork;
	long		timer;
	t_process	*process;
	pid_t		pid;
	long		last_eat_time;
	t_params	params;
}				t_philo;

typedef struct s_semaphor
{
	sem_t		*main_semaphor;
	int			main_sem_value;
	sem_t		*forks_semaphor;
	int			fork_sem_value;
}				t_semaphor;

struct s_process
{
	void			*synchronizer;
	t_philo			*philo;
	t_params		params;
	t_fork			*fork;
	int				counter;
	size_t			catch_status;
	t_bool			lock;
	void			(*func)(t_process *, t_philo *);
	void			*(*main_loop)(void *);
	void			(*dropforks)(t_process *, t_philo *);
};

#endif		/* pstruct header */