/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 19:31:10 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/19 17:27:08 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo_bonus.h"

void	check_phil_num(t_data *data)
{
	data->n_phil = (int)ft_atol(data->args->av[1]);
	if (data->n_phil < 1)
	{
		print_error(INVALID_NUMBER_OF_PHILOSOPHERS);
		exit(EXIT_FAILURE);
	}
}

/*
 * Takes input time value in milliseconds.
 * */
void	check_time_to_die(t_data *data)
{
	data->t_die = ft_atol(data->args->av[2]);
	if (data->t_die < 1)
	{
		print_error(INVALID_TIME_TO_DIE);
		exit(EXIT_FAILURE);
	}
}

void	check_time_to_eat(t_data *data)
{
	data->t_eat = ft_atol(data->args->av[3]);
	if (data->t_eat < 1)
	{
		print_error(INVALID_TIME_TO_EAT);
		exit(EXIT_FAILURE);
	}
}

void	check_time_to_sleep(t_data *data)
{
	data->t_sleep = ft_atol(data->args->av[4]);
	if (data->t_sleep < 1)
	{
		print_error(INVALID_TIME_TO_SLEEP);
		exit(EXIT_FAILURE);
	}
}

void	check_number_times_eat(t_data *data)
{
	data->min_meals = ft_atol(data->args->av[5]);
	if (data->min_meals < 1)
	{
		print_error(INVALID_NUMBER_TIMES_EAT);
		exit(EXIT_FAILURE);
	}
}
