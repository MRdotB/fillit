/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2100/01/01 00:00:00 by glodenos          #+#    #+#             */
/*   Updated: 2100/01/01 00:00:00 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("Pas le bn nbr de file\n");	// Change msg err
		return (0);
	}
	if (valid_tet(argv[1]))
		if (load_tet(argv[1]))
		{
			ft_putstr("<=== Algo on ===>\n");	// Change msg err
			// algo
			// print screen
		}
		else
			ft_putstr("Terminos invalid\n");	// Change msg err
	else
		ft_putstr("Fichier erone\n");	// Change msg err
	return (0);
}
