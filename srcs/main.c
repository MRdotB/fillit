/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2100/01/01 00:00:00 by glodenos          #+#    #+#             */
/*   Updated: 2016/02/12 16:13:58 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include <stdio.h>

static void	fillit(int ac, char **av)
{
	t_tet	*tet_list;

	if (ac != 2)
		return (show_usage());
	if ((check_error(av[1])) == 0)
		return (show_error());
	if ((get_tet(av[1], &tet_list)) == 0)
		return (show_error());
	solve(tet_list);
}

int			main(int ac, char **av)
{
	fillit(ac, av);
	return (0);
}
