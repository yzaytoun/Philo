/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:59:32 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/02/19 18:34:57 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include "pstruct.h"

typedef enum e_semtype
{
	FORK_SEM,
	MAIN_SEM
}	t_semtype;

/*Functions*/
//STUB - Basic Functions
void		ft_putstr_fd(const char *string, int fd);
long		ft_atoi(const char *str);
t_params	ft_getarguments(int argc, char *argv[]);
void		ft_apply(t_process *process, int (*f)(t_process *, int));

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
int			ft_createthread(t_process *process, int philo_id);

//STUB - Routine
void		ft_run(t_process *process);

//STUB - Time
void		ft_msleep(long miliseconds, t_process *process, t_philo *philo);
long		ft_get_current_time(void);
long		ft_time_diff(long first_time, long second_time);

//STUB - Routine
void		ft_eat(t_process *process, t_philo *philo);
void		ft_sleep(t_process *process, t_philo *philo);
t_bool		ft_isalive(t_process *process, t_philo *philo);
void		ft_think(t_process *process, t_philo *philo);

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