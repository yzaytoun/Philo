/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:43:09 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/17 20:26:42 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_process	*process;
	t_params	params;

	if (argc >= 5 && argc <= 6)
	{
		params = ft_getarguments(argc, argv);
		process = ft_createprocess(params);
		struct timeval time;
		ft_adjust(&time);
		//ft_run(process);
		ft_freeall(&process);
	}
	else
		ft_perror("Wrong Number of Arguments, 4 minimum");
	return (EXIT_SUCCESS);
}
