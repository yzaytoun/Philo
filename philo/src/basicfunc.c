/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basicfunc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:48:34 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/14 19:50:07 by yzaytoun         ###   ########.fr       */
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

//ANCHOR - Get arguments
t_params	ft_getarguments(int argc, char *argv[])
{
	t_params	params;
	
	params.philo_num = ft_atoi(argv[1]);	
	params.time_to_die = ft_atoi(argv[2]);	
	params.time_to_eat = ft_atoi(argv[3]);	
	params.time_to_sleep = ft_atoi(argv[4]);	
	if (argc == 6)
		params.repetition_num = ft_atoi(argv[5]);
	return (params);
}

//ANCHOR - Philo apply
void	ft_philo_apply(t_philo *philo, void (*f)(t_philo *), int philo_num)
{
	int	count;

	count = 0;
	while (count < philo_num)
	{
		(*f)(&(philo[count]));
		++count;
	}
	
}

//!SECTION