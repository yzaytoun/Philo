/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:19:37 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/14 19:46:34 by yzaytoun         ###   ########.fr       */
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

/*Macros*/
# define TRUE 1
# define FALSE !TRUE

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
}				t_philo;

typedef struct s_process
{
	pthread_t		thread;
	pthread_mutex_t	mutex;
	t_philo			*philo;
}				t_process;

/*Functions*/
//STUB - Basic Functions
void		ft_putstr_fd(char *string, int fd);

//STUB - Printer
void		ft_perror(char *string);

//STUB - Philo
t_process	*ft_createprocess(int philo_num);
void		ft_freeall(t_process **process);


//STUB - Routine
void		ft_routine(t_process *process);
void		ft_run(t_process *process);
#endif		/*End Philo.h*/