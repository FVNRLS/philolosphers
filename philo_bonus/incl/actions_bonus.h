/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:15:15 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/19 11:43:46 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef ACTIONS_H
# define ACTIONS_H

# include "structs_bonus.h"

//STATES
# define FORK_TAKEN		1
# define IS_EATING		2
# define IS_SLEEPING	3
# define IS_THINKING	4
# define PHIL_DIED		5
# define FREE			6


//PHILOSOPHERS ACTIONS
void	take_forks(t_phil *phil);
void	eat(t_phil *phil);
void	ph_sleep(t_phil *phil);
void	think(t_phil *phil);
void	print_status(t_phil *phil, int status);

#endif