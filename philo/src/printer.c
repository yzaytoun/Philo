/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:52:08 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/08/05 11:48:54 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//SECTION - Printer
//ANCHOR - Aux error printer
void	ft_perror(char *string)
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
void	ft_printstatus(t_philo philo)
{
	printf("[\U0001F570 %ld] -> philo %d ", philo.timer, philo.id);
	ft_print_status(philo.laststatus);
}

//!SECTION