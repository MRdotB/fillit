/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrice.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 14:43:36 by bchaleil          #+#    #+#             */
/*   Updated: 2016/01/28 21:05:46 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static t_matrice	fill_matrice(t_matrice matrice)
{
	int x;
	int y;

	y = 0;
	while (y <= matrice.size_y)
	{
		x = 0;
		while (x <= matrice.size_x)
		{
			matrice.map[y][x] = '.';
			x++;
		}
		y++;
	}
	return (matrice);
}

t_matrice			create_matrice(unsigned int x, unsigned int y)
{
	t_matrice		matrice;
	char			**map;
	unsigned int	i;

	map = (char**)malloc(sizeof(char**) * y);
	i = 0;
	while (i < y)
	{
		map[i] = (char*)malloc(sizeof(char*) * (x));
		i++;
	}
	matrice.map = map;
	matrice.size_x = x - 1;
	matrice.size_y = y - 1;
	return (fill_matrice(matrice));
}
