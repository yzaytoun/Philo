/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:43:09 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/14 19:16:36 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv[])
{
	t_process		*process;

	if (argc <= 5)
	{
		process = ft_createprocess(argc[1]);
		process->thread = /*create thread*/
		/*init mutex*/
		ft_routine(prcoess);
		ft_freeall(&process);
	}
	else
		ft_perror("Wrong Number of Arguments, 4 minimum");
	return (EXIT_SUCCESS);
}