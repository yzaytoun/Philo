/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:19:37 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/17 20:27:15 by yzaytoun         ###   ########.fr       */
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
# define TAKEN_FORK 12
# define SLEEPING 13
# define THINKING 14
# define DIED 15

/*Structs*/
typedef struct s_status
{
	int	died;
	int	eat;
	int	wait;
}				t_status;

typedef struct s_philo
{
	int			id;
	t_status	status;
	pthread_t	thread;
}				t_philo;

typedef struct s_params
{
	int		philo_num;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		repetition_num;
}				t_params;


typedef struct s_process
{
	pthread_mutex_t	mutex;
	t_philo			*philo;
	t_params		params;
}				t_process;

/*Functions*/
//STUB - Basic Functions
void		ft_putstr_fd(char *string, int fd);
long		ft_atoi(const char *str);
t_params	ft_getarguments(int argc, char *argv[]);
void		ft_philo_apply(t_philo *philo, void (*f)(t_philo *), int philo_num);

//STUB - Printer
void		ft_perror(char *string);

//STUB - Philo
t_process	*ft_createprocess(t_params params);
void		ft_freeall(t_process **process);

//STUB - Mutex
void		ft_check(int status);

//STUB - Routine
void		ft_routine(t_process *process);
void		ft_run(t_process *process);

//STUB - Time
void		ft_adjust(struct timeval *time);
#endif		/*End Philo.h*/