/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:19:37 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/07/13 20:51:17 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H		/*Philo.h*/
# define PHILO_H

# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

/*Macros*/
# define TRUE 1
# define FALSE !TRUE

typedef struct s_status
{
	int	died;
	int	eat;
	int	wait;
}				t_status;

typedef struct s_mutex
{
	pthread	thread;
}				t_mutex;

typedef struct s_philo
{
	t_status	update_status;
	t_mutex		mutex;
}				t_philo;


/*Functions*/

#endif		/*End Philo.h*/