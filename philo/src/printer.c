/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:52:08 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/21 18:06:24 by yzaytoun         ###   ########.fr       */
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
static void	ft_print_status(int status)
{
	if (status == EATING)
		ft_putstr_fd("is eating \U0001F35D", STDOUT_FILENO);
	else if (status == TAKEN_FORK)
		ft_putstr_fd("has taken a fork \U0001F374", STDOUT_FILENO);
	else if (status == SLEEPING)
		ft_putstr_fd("is sleeping \U0001F634", STDOUT_FILENO);
	else if (status == THINKING)
		ft_putstr_fd("is thinking \U0001F9D0", STDOUT_FILENO);
	else if (status == DIED)
		ft_putstr_fd("died \U0001F480", STDOUT_FILENO);
}

//ANCHOR - Print status
void	ft_printstatus(t_philo philo)
{
	ft_printtime();
	printf(" -> philo %d\t", philo.id);
	ft_print_status(philo.status);
}

//!SECTION