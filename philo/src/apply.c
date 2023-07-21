/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:13:03 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/21 17:21:37 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//SECTION - Apply
//ANCHOR - Assign ids
int	ft_assign_ids(t_process *process, int philo_id)
{
	process->philo[philo_id].id = philo_id;
	process->fork[philo_id].id = philo_id;
	return (TRUE);
}

//!SECTION