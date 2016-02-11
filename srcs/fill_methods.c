/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_methods.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 18:47:04 by bchaleil          #+#    #+#             */
/*   Updated: 2016/02/11 14:10:56 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static int	valid_pos(t_matrix matrix, t_pos pos)
{
	if (pos.x >= 0 && pos.y >= 0 &&
			pos.x <= matrix.size_x && pos.y <= matrix.size_y)
	{
		if (ISUPPER(matrix.map[pos.y][pos.x]))
			return (0);
		return (1);
	}
	else
		return (0);
}

int			check_fill(t_tet tet, t_matrix matrix, t_pos pos)
{
	int	tmp;
	int last;
	int d;

	d = 1000;
	last = 0;
	while (d != 0)
	{
		tmp = tet.code / d;
		tet.code %= d;
		d /= 10;
		if (last == tmp && last != 0)
			pos.y++;
		else if (last > tmp && last != 0)
		{
			pos.x += tmp - last;
			pos.y++;
		}
		else if (last < tmp && last != 0)
			pos.x -= last - tmp;
		if (!(valid_pos(matrix, pos)))
			return (0);
		last = tmp;
	}
	return (1);
}

char		**fill(int code, t_matrix matrix, t_pos pos, char ascii)
{
	int		tmp;
	int		last;
	int		d;

	d = 1000;
	last = 0;
	tmp = 0;
	while (d != 0)
	{
		tmp = code / d;
		code %= d;
		d /= 10;
		if (last == tmp && last != 0)
			pos.y++;
		else if (last > tmp && last != 0)
		{
			pos.x += tmp - last;
			pos.y++;
		}
		else if (last < tmp && last != 0)
			pos.x -= last - tmp;
		matrix.map[pos.y][pos.x] = ascii;
		last = tmp;
	}
	return (matrix.map);
}
