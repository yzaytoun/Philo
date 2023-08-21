/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:52:29 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/08/21 20:22:18 by yzaytoun         ###   ########.fr       */
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
