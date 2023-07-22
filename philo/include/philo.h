/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:19:37 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/22 11:23:34 by yzaytoun         ###   ########.fr       */
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
void		ft_printstatus(int philo_id, int status);

//STUB - Philo
t_process	*ft_createprocess(t_params params);
void		ft_freeall(t_process **process);

//STUB - Apply
void		*ft_check(int status);
int			ft_assign_ids(t_process *process, int philo_id);

//STUB - Routine
void		*ft_routine(t_process *process, t_philo *philo);
int			ft_run(t_process *process);

//STUB - Time
void		ft_printtime(void);
void		ft_delay(int seconds);
long		ft_settimer(void);

//STUB - Threads
int			ft_createthread(t_process *process, int philo_id);
int			ft_threadjoin(t_process *process, int philo_id);

#endif		/*End Philo.h*/