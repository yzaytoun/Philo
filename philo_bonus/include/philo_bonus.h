/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:59:32 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/02/17 19:23:50 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include "pstruct.h"

# define FORK_SEM 1
# define MAIN_SEM 2

/*Functions*/
//STUB - Basic Functions
void		ft_putstr_fd(const char *string, int fd);
long		ft_atoi(const char *str);
t_params	ft_getarguments(int argc, char *argv[]);
void		ft_apply(t_process *process, int (*f)(t_process *, int), int lock);

//STUB - Printer
void		ft_perror(const char *string, const char *func);
void		ft_print_log(t_process *process, t_philo *philo);

//STUB - Philo
t_process	*ft_createprocess(t_params params);
void		ft_freeall(t_process **process);

//STUB - AUX functions
void		ft_try(int status, const char *func);
void		ft_assign_params(t_params *params, int count, long input);
void		ft_catch(t_process *process);

//STUB - Apply
int			ft_assign_ids(t_process *process, int philo_id);
int			ft_initforkmutex(t_process *process, int count);
int			ft_destroyforkmutex(t_process *process, int count);
int			ft_createthread(t_process *process, int philo_id);

//STUB - Mutexes
void		ft_initmutexes(t_process **process);
void		ft_destroy_allmutexes(t_process *process);

//STUB - Routine
void		ft_run(t_process *process);

//STUB - Time
void		ft_msleep(long miliseconds, t_process *process, t_philo *philo);
long		ft_get_current_time(void);
long		ft_time_diff(long first_time, long second_time);
long		ft_time_add(long first_time, long second_time);

//STUB - Threads
int			ft_jointhread(t_process *process, int count);
void		ft_threadexecute(t_process *process,
				void (*f)(t_process *, t_philo *), t_philo *philo);
int			ft_threadlimit(t_process *process, t_philo *philo);
void		ft_initprocess(t_process **process, t_philo *philo);

//STUB - Execute
void		ft_eat(t_process *process, t_philo *philo);
void		ft_sleep(t_process *process, t_philo *philo);
t_bool		ft_isalive(t_process *process, t_philo *philo);
void		ft_think(t_process *process, t_philo *philo);

//STUB - Forks
void		ft_dropforks(t_process *process, t_philo *philo);
void		ft_getforks(t_process *process, t_philo *philo);

//STUB - Thread checker
int			ft_check_deadthread(t_process *process, int counter);
int			ft_all_threadsactive(t_process *process, int counter);
int			ft_check_forklocks(t_process *process, int counter);
int			ft_all_threadsfinished(t_process *process, int counter);
int			ft_kill_threads(t_process *process, int counter);

void		print_philo(t_philo philo);

/*Bonus Functions*/
//STUB - Process managemente functions
int			ft_create_childprocess(t_process *process, int count);
int			ft_wait_childprocess(t_process *process, int count);
int			ft_killprocess(t_process *process, int count);

//STUB - Semaphore execution
void		ft_semexecute(t_process *process, t_philo *philo,
				void (*f)(t_process *, t_philo *));
void		ft_dropforks_sem(t_process *process, t_philo *philo);
void		ft_getforks_sem(t_process *process, t_philo *philo);
int			ft_check_allprocesses(t_process *process, int count);

//STUB - Semaphores
void		ft_increment_semaphore(t_process *process, int sem_id);
void		ft_decrement_semaphore(t_process *process, int sem_id);
void		ft_open_semaphore(t_process *process);
void		ft_close_semaphore(t_process *process);

#endif