/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 16:28:34 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/12 17:05:00 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

//ERROR CODES:
# define INVALID_NUMBER_OF_ARGUMENTS 	1
# define INVALID_NUMBER_OF_PHILOSOPHERS 2

void	print_error_exit(int	error_key);

#endif
