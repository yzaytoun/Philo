/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:43:09 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/22 11:26:24 by yzaytoun         ###   ########.fr       */
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
		if (ft_run(process) == EXIT_FAILURE)
		{
			ft_freeall(&process);
			ft_putstr_fd("Thread Died\n", STDOUT_FILENO);
			return (EXIT_SUCCESS);
		}
		ft_freeall(&process);
	}
	else
		ft_perror("Wrong Number of Arguments \U0001F92F, 4 minimum");
	return (EXIT_SUCCESS);
}
