/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:52:29 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/08/24 19:33:11 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

//SECTION - Child Processes manager
//ANCHOR - Catch status
static void	ft_catch_childstatus(t_process *process)
{
	if (process->catch_status == DIED)
	{
		ft_close_semaphore(process);
		ft_apply(process, ft_killprocess, APPLY_NO_LOCK);
		ft_freeall(&process);
		ft_perror("Process Died");
	}
}

//ANCHOR - Kill all child processes
int	ft_killprocess(t_process *process, int count)
{
	kill(process->philo[count].pid, SIGKILL);
	return (EXIT_SUCCESS);
}

//ANCHOR - Evaluate status
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
	if (
		waitpid(
			process->philo[count].pid, (int *) &process->catch_status,
			EXIT_SUCCESS) < 0)
	{
		ft_close_semaphore(process);
		ft_freeall(&process);
		ft_perror("Waitpid");
	}
	ft_evaluatestatus(process->catch_status);
	ft_catch_childstatus(process);
	return (EXIT_SUCCESS);
}

//ANCHOR - Create Process
int	ft_create_childprocess(t_process *process, int count)
{
	process->philo[count].process = process;
	process->philo[count].pid = fork();
	if (process->philo[count].pid == 0)
		process->main_loop(&process->philo[count]);
	else if (process->philo[count].pid < 0)
	{
		ft_close_semaphore(process);
		ft_freeall(&process);
		ft_perror(__func__);
	}
	return (EXIT_SUCCESS);
}

//!SECTION
