/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:52:29 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/08/19 17:37:12 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

//SECTION - Child Processes manager
static void	ft_evaluatestatus(int status)
{
	int	exitstatus;

	if (WIFEXITED(status))
	{
		exitstatus = WEXITSTATUS(status);
		if (exitstatus != 0)
		{
			printf("Child Existed with status -> %d\n", exitstatus);
			ft_perror(__func__);
		}
	}
}

//ANCHOR - Wait child process
int	ft_wait_childprocess(t_process *process, int count)
{
	ft_try(
		waitpid(process->philo[count].pid, &process->catch_status,
			EXIT_SUCCESS)
		);
	ft_evaluatestatus(process->catch_status);
	return (EXIT_SUCCESS);
}

//ANCHOR - Create Process
int	ft_create_childprocess(t_process *process, int count)
{
	process->philo[count].pid = fork();
	if (process->philo[count].pid == 0)
		process->main_loop;
	else if (process->philo[count].pid < 0)
	{
		ft_try(sem_close(((t_semaphor *)process->synchronizer)->semaphor));
		ft_try(sem_unlink(((t_semaphor *)process->synchronizer)->semaphor));
		ft_perror(__func__);
	}
	return (EXIT_SUCCESS);
}

//!SECTION
