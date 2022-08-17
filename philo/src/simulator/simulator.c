/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:39:15 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/17 16:48:30 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo.h"

static void	*simulate(void *arg)
{
	t_phil	*phil;

	phil = arg;

	if (phil->id % 2 == 0)
		ft_usleep(phil->data->t_eat / 2);
	while (true)
	{
		check_phil_died(phil);
		take_forks(phil);
		eat(phil);
		ph_sleep(phil);
		think(phil);
		check_phil_died(phil);
	}
}

static bool join_threads(t_phil *phil, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_phil)
	{
		if (pthread_join(phil->thread[i], NULL) != 0)
			return (false);
		i++;
	}
	return (true);
}

static bool	start_threads(t_phil *phil, t_data *data)
{
	int i;

	phil->thread = malloc((sizeof(pthread_t) * data->n_phil));
	i = 0;
	while (i < data->n_phil)
	{
		if (pthread_create(&phil->thread[i], NULL, &simulate, (void *)&phil[i]) != 0)
			return (false);
		i++;
	}
	return (true);
}

static void	init_phils(t_phil *phil, t_data *data)
{
	int i;

	i = 0;
	while (i < data->n_phil)
	{
		phil[i].data = data;
		phil[i].id = i + 1;
		phil[i].fork_left = phil[i].id;
		if (phil[i].id == data->n_phil)
			phil[i].fork_right = 1;
		else
			phil[i].fork_right = phil[i].id + 1;
		phil[i].data->died = false;
		i++;
	}
}

int	start_simulation(t_data *data)
{
	t_phil 		*phil;

	bool	threads_started;
	bool	threads_joined;

	phil = malloc(sizeof(t_phil) * data->n_phil);
	if (!phil)
		return (EXIT_FAILURE);
	init_phils(phil, data);
	threads_started = start_threads(phil, data);
	if (threads_started == false)
	{
		free(phil->thread);
		phil->thread = NULL;
		return (EXIT_FAILURE);
	}
	threads_joined = join_threads(phil, data);
	if (threads_joined == false)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}