#include "philo_bonus.h"

//SECTION - Auxiliarly Functions
//ANCHOR - Get semaphore values
void	ft_get_semvalue(t_process *process)
{
	ft_try(
		sem_getvalue(
			((t_semaphor *)process->synchronizer)->forks_semaphor,
			&((t_semaphor *)process->synchronizer)->sem_value
			)
		);
}
//ANCHOR - Increment semaphore
void    ft_increment_semaphore(t_process *process)
{
    ft_get_semvalue(process);
    if (((t_semaphor *)process->synchronizer)->sem_value < SEM_VALUE_MAX)
		{
			ft_try(
				sem_post(
					&((t_semaphor *)process->synchronizer)->main_semaphor));
		}
}
//ANCHOR - Decrement semaphore
void    ft_decrement_semaphore(t_process *process)
{
    ft_get_semvalue(process);
	if (((t_semaphor *)process->synchronizer)->sem_value > 0)
	{
		ft_try(sem_wait(&((t_semaphor *)process->synchronizer)->main_semaphor));
    }
}

//ANCHOR - 
void    ft_open_semaphore(t_process *process)
{
    ((t_semaphor *)process->synchronizer)->main_semaphor
		= sem_open("/philo_sem", O_CREAT | O_EXCL, 0644, 0);
	((t_semaphor *)process->synchronizer)->forks_semaphor
		= sem_open("/forks_sem", O_CREAT | O_EXCL, 0644,
			process->params.philo_num);
}
//!SECTION