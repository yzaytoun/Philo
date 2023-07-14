/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basicfunc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:48:34 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/14 16:52:34 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//SECTION - Basic Functions
//ANCHOR - Print string
void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, &(*s), 1);
		s++;
	}
}

//!SECTION