/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:19:37 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/31 18:17:07 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H		/*Philo.h*/
# define PHILO_H 

# include "pstruct.h"

/*Functions*/
//STUB - Basic Functions
void		ft_putstr_fd(char *string, int fd);
long		ft_atoi(const char *str);
t_params	ft_getarguments(int argc, char *argv[]);
void		*ft_apply(t_process *process, int (*f)(t_process *, int));

//STUB - Printer
void		ft_perror(char *string);
void		ft_printstatus(t_philo philo, int laststatus);

//STUB - Philo
t_process	*ft_createprocess(t_params params);
void		ft_freeall(t_process **process);

//STUB - Apply
void		*ft_try(int laststatus);
int			ft_assign_ids(t_process *process, int philo_id);
int			ft_updatetimer(t_process *process, int philo_id);
void		ft_assign_params(t_params *params, int count, long input);
int			ft_initmutex(t_process *process, int count);
int			ft_destroymutex(t_process *process, int count);


//STUB - Routine
void		*ft_routine(t_philo *philo);
int			ft_run(t_process *process);

//STUB - Time
void		ft_delay(int seconds);
long		ft_gettimeofday(void);
void		ft_addcurrenttime(t_params *params);


//STUB - Threads
int			ft_createthread(t_process *process, int philo_id);
void		ft_threadexecute(t_process *process,
				void (*f)(t_process *, int), int philo_id);

//STUB - Execute
void		ft_eat(t_process *process, int philo_id);
void		ft_sleep(t_process *process, int philo_id);
void		ft_isalive(t_process *process, int philo_id);

#endif		/*End Philo.h*/