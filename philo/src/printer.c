/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:52:08 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/14 17:11:39 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//SECTION - Printer
//ANCHOR - Aux error printer
void	ft_perror(char *string)
{
	ft_putstr_fd(string, fd);
	write(1, "\n", 1);
	exit(EXIT_FAILURE);
}

//!SECTION