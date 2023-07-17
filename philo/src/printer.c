/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:52:08 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/17 20:32:52 by yzaytoun         ###   ########.fr       */
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
static void	ft_print_action(int action)
{
	if (action == EATING)
		printf("is eating");
	else if (action == TAKEN_FORK)
		printf("has taken a fork");
	else if (action == SLEEPING)
		printf("is sleeping");
	else if (action == THINKING)
		printf("is thinking");
	else if (action == DIED)
		printf("died");
}

//ANCHOR - Print status
void	ft_printstatus(struct timeval time, int philo_id, int action)
{
	printf("%ld : %d -> philo %d\n", time.tv_sec, time.tv_usec, philo_id);
	ft_print_action(action);
}

//!SECTION