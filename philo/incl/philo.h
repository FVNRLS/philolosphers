/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 13:12:53 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/12 16:30:35 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <fcntl.h>
# include <sys/time.h>
# include <semaphore.h>

# include "./error.h"

# define LEFT_FORK_BUSY				1
# define RIGHT_FORK_BUSY			2
# define LEFT_FORK_FREE				3
# define RIGHT_FORK_FREE			4

typedef struct s_args
{
	int 	ac;
	char 	**av;
} 		t_args;

typedef struct s_phil
{
	int				n_phil;
	double			t_eat;
	double			t_sleep;
	double			t_think;
	double			t_die;
	pthread_mutex_t fork_left;
	pthread_mutex_t fork_right;

	struct timeval	t_current;
	t_args			*args;
}		t_phil;

//INPUT PARSER
void	parse_input(t_phil *phil);


//TOOLS
int		ft_strlen(char *s);

#endif