/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:52:29 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/02/19 19:18:00 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

//SECTION - Child Processes manager
//ANCHOR - Kill all child processes
int	ft_killprocess(t_process *process, int count)
{
	kill(process->philo[count].pid, SIGKILL);
	return (EXIT_SUCCESS);
}

//ANCHOR - Wait child process
int	ft_wait_childprocess(t_process *process, int count)
{
	waitpid(process->philo[count].pid, &process->catch_status, EXIT_SUCCESS);
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
		ft_perror("FORK", FUNC);
	}
	return (EXIT_SUCCESS);
}

//!SECTION
