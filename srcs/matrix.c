/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 14:43:36 by bchaleil          #+#    #+#             */
/*   Updated: 2016/02/11 12:58:59 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void				free_matrix(char **map, int size_y)
{
	(void)size_y;
	map = NULL;
}

static	t_matrix	fill_matrix(t_matrix matrix)
{
	int				x;
	int				y;

	y = -1;
	while (++y <= matrix.size_y)
	{
		x = -1;
		while (++x <= matrix.size_x)
			matrix.map[y][x] = '.';
	}
	return (matrix);
}

t_matrix			create_matrix(unsigned int x, unsigned int y)
{
	t_matrix		matrix;
	char			**map;
	unsigned int	i;

	i = 0;
	map = (char**)malloc(sizeof(char**) * y);
	while (i < y)
	{
		map[i] = (char*)malloc(sizeof(char*) * (x));
		i++;
	}
	matrix.map = map;
	matrix.size_x = x - 1;
	matrix.size_y = y - 1;
	return (fill_matrix(matrix));
}
