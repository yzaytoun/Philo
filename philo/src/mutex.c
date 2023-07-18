/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:51:51 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/18 20:35:41 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//SECTION - Mutex
//ANCHOR - Unlock mutex
void	ft_check(int status)
{
	if (status)
	{
		ft_perror("pthread_mutex_unlock");
		pthread_exit(NULL);
	}
	else
		return ;
}

//!SECTION
