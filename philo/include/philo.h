/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:19:37 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/20 21:03:23 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H		/*Philo.h*/
# define PHILO_H

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
}				t_philo;

typedef struct s_params
{
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				repetition_num;
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
}				t_process;

/*Functions*/
//STUB - Basic Functions
void		ft_putstr_fd(char *string, int fd);
long		ft_atoi(const char *str);
t_params	ft_getarguments(int argc, char *argv[]);
void		ft_philo_apply(t_process *process, int (*f)(t_process *, int));

//STUB - Printer
void		ft_perror(char *string);
void		ft_printstatus(t_philo philo);

//STUB - Philo
t_process	*ft_createprocess(t_params params);
void		ft_freeall(t_process **process);

//STUB - Mutex
void		ft_check(int status);

//STUB - Routine
void		ft_routine(t_process *process);
void		ft_run(t_process *process);

//STUB - Time
void		ft_printtime(void);
void		ft_delay(int seconds);

//STUB - Threads
int			ft_createthread(t_process *process, int philo_id);
int			ft_threadjoin(t_process *process, int philo_id);
#endif		/*End Philo.h*/