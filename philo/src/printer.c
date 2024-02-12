/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:52:08 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/02/12 19:01:29 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//SECTION - Printer
//ANCHOR - Aux error printer
void	ft_perror(const char *string)
{
	ft_putstr_fd(string, STDERR_FILENO);
	write(1, "\n", 1);
	exit(EXIT_FAILURE);
}

//ANCHOR - Print Action
static void	ft_print_status(int laststatus)
{
	if (laststatus == 0)
		return ;
	if (laststatus == EATING)
		printf("is eating \U0001F35D \n");
	else if (laststatus == TAKEN_FORK)
		printf("has taken a fork \U0001F374 \n");
	else if (laststatus == SLEEPING)
		printf("is sleeping \U0001F634 \n");
	else if (laststatus == THINKING)
		printf("is thinking \U0001F9D0 \n");
	else if (laststatus == DIED)
		printf("died \U0001F480 \n");
	else if (laststatus == STARTED)
		printf("Thread Started !!! \n");
}

//ANCHOR - Print laststatus
void	ft_printstatus(t_process *process, t_philo *philo)
{
	long	current_time;

	current_time = ft_get_current_time();
	printf("[\U0001F570 %ld] -> philo %d ",
		current_time - process->params.start_time, philo->id);
	ft_print_status(philo->laststatus);
}

//ANCHOR - Print Philo
void	print_philo(t_philo philo)
{
	printf("Summary \n------------ \n");
	printf("philo.id = %d\n", philo.id);
	printf("philo.timer = %lu\n", philo.timer);
	printf("philo.last_eat_time = %lu\n", philo.last_eat_time);
	ft_print_status(philo.laststatus);
	printf("philo.leftfork.id = %d\n", philo.left_fork.id);
	printf("philo.leftfork.is_used = %d\n", philo.left_fork.is_used);
	printf("philo.rightfork.id = %d\n", philo.right_fork.id);
	printf("philo.rightfork.is_used = %d\n", philo.right_fork.is_used);

	printf("Data \n------------ \n");
	printf("philo.data.eat_count = %d\n", philo.data.eat_count);
	printf("philo.data.sleep_count = %d\n", philo.data.sleep_count);
	printf("philo.data.think_count = %d\n", philo.data.think_count);
}

//!SECTION