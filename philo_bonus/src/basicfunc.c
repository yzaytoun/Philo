/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basicfunc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:48:34 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/02/17 19:25:07 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

//SECTION - Basic Functions
//ANCHOR - Print string
void	ft_putstr_fd(const char *s, int fd)
{
	if (!s)
		write(fd, "(null)", 6);
	while (*s)
	{
		if (write(fd, &(*s), 1) < 0)
			return ;
		s++;
	}
}

//ANCHOR - Atoi
long	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long		result;

	if (!str)
		return (0);
	result = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		++i;
	if (str[i] != '\0' && str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
		result = (result * 10) + (str[i++] - '0');
	return (result * sign);
}

//ANCHOR - Is digit string
static int	ft_isstrdigit(const char *str)
{
	int	i;

	if (!str)
		return (FALSE);
	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (FALSE);
		++i;
	}
	return (TRUE);
}

//ANCHOR - Get arguments
t_params	ft_getarguments(int argc, char *argv[])
{
	t_params	params;
	long		input;
	int			count;

	count = 1;
	while (count < argc)
	{
		if (ft_isstrdigit(argv[count]) == FALSE)
			ft_perror("Wrong number format", NULL);
		input = ft_atoi(argv[count]);
		if (input > INT_MAX || input < INT_MIN || input < 0)
			ft_perror("Very Big number", NULL);
		else
			ft_assign_params(&params, count, input);
		++count;
	}
	return (params);
}
//!SECTION
