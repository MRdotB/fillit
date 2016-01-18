/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 15:58:15 by bchaleil          #+#    #+#             */
/*   Updated: 2016/01/18 16:19:36 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	fillit(int ac, char **av)
{
	if (ac != 2)
		return (show_usage());	
	if ((check_error1(av[1])) == 0)
		return (show_error());
	get_tetriminos(av[1]);
}
