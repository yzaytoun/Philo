/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:19:37 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/08/19 18:09:06 by yzaytoun         ###   ########.fr       */
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
void		ft_printstatus(t_philo philo);

//STUB - Philo
t_process	*ft_createprocess(t_params params);
void		ft_freeall(t_process **process);

//STUB - AUX functions
void		ft_try(int status);
void		ft_assign_params(t_params *params, int count, long input);
void		ft_catch(t_process *process);

//STUB - Apply
int			ft_assign_ids(t_process *process, int philo_id);
int			ft_initforkmutex(t_process *process, int count);
int			ft_destroyforkmutex(t_process *process, int count);
int			ft_createthread(t_process *process, int philo_id);

//STUB - Routine
void		ft_run(t_process *process);

//STUB - Time
void		ft_delay(int seconds);
long		ft_gettimeofday(void);
void		ft_marktime(t_params *params);

//STUB - Threads
void		ft_threadexecute(t_process *process,
				void (*f)(t_process *, t_philo *), t_philo *philo);
int			ft_threadlimit(t_process *process, t_philo *philo);
int			ft_threadjoin(t_process *process, int philo_id);
void		ft_startroutine(t_process *process, t_philo *philo);
void		ft_init_thread(t_process *process, t_philo *philo);

//STUB - Execute
void		ft_eat(t_process *process, t_philo *philo);
void		ft_sleep(t_process *process, t_philo *philo);
void		ft_isalive(t_process *process, t_philo *philo);
void		ft_addtime(t_process *process, t_philo *philo);

//STUB - Forks
void		ft_dropforks(t_process *process, t_philo *philo);
void		ft_getforks(t_process *process, t_philo *philo);

//STUB - Thread checker
void		ft_threadchecker(t_process *process, int (*func)(t_process *, int));
int			ft_check_deadthread(t_process *process, int counter);
int			ft_all_threadsactive(t_process *process, int counter);
int			ft_check_forklocks(t_process *process, int counter);
#endif		/*End Philo.h*/