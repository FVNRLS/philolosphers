/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulator_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:39:15 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/20 15:49:22 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo_bonus.h"

static void	check_if_sated(t_phil *phil)
{
	if (phil->data->min_meals == 0)
		phil->sated = false;
	if (phil->meals >= phil->data->min_meals)
		phil->sated = true;
}

static void	simulate(t_phil *phil)
{
	if (phil->id % 2 == 0)
		ft_usleep(phil, (phil->data->t_eat / 2));
	while (phil->died == false)
	{
		take_forks(phil);
		eat(phil);
		phil->meals++;
		check_if_sated(phil);
		if (phil->sated == true)
			exit(PHIL_SATED);
		ph_sleep(phil);
		think(phil);
		check_death(phil);
	}
//	print_status(phil, PHIL_DIED);
}

static void	init_start_params(t_phil *phil)
{
	phil->t_last_eat = 0;
	phil->meals = 0;
	get_current_time(phil);
	phil->t_start = phil->t_current;
	phil->died = false;
	phil->sated = false;
}

static void	run_procs(t_phil *phil)
{
	int i;

	i = 0;
	init_start_params(phil);
	while (i < phil->data->n_phil)
	{
		phil->id = i + 1;
		phil->proc = fork();
		if (phil->proc < 0)
		{
			kill(0, SIGQUIT);
			print_error(FORK_ERROR);
			exit(EXIT_FAILURE);
		}
		else if (phil->proc == 0)
			simulate(phil);
		i++;
	}

}

void	run_simulation(t_data *data)
{
	t_phil	phil;

	phil.data = data;
	run_procs(&phil);
	watch_phils(&phil);
}