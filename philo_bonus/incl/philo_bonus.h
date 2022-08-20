/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 13:12:53 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/20 13:12:01 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "./actions_bonus.h"
# include "./error_bonus.h"
# include "./tools_bonus.h"

# define RIGHTS	0644

//INPUT PARSER
void 	parse_input(t_data *data);
void	check_phil_num(t_data *data);
void	check_time_to_die(t_data *data);
void	check_time_to_eat(t_data *data);
void	check_time_to_sleep(t_data *data);
void	check_number_times_eat(t_data *data);

//SIMULATION FUNCTIONS
void	run_simulation(t_data *data);
void	watch_phils(t_phil *phil);
void	get_time_diff(t_phil *phil);
void	get_current_time(t_phil *phil);

//SEMAPHORES (FORKS) CONTROLLER
int		init_semaphores(t_data *data);
void	destroy_semaphores(t_data *data);

#endif
