/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_methods.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 18:47:04 by bchaleil          #+#    #+#             */
/*   Updated: 2016/01/25 20:30:02 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int		check_fill(int code, t_matrice matrice, t_pos pos)
{
	int	tmp;
	int last;
	int d;

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
		if (pos.x >= 0 && pos.y >= 0 && pos.x < matrice.size_x && pos.y < matrice.size_y)
		{
			if (matrice.map[pos.y][pos.x] == '#')
				return (0);
		}
		else
			return (0);
		last = tmp;
	}
	return (1);
}

char	**fill(int code, t_matrice matrice, t_pos pos)
{
	int	tmp;
	int last;
	int d;

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
		matrice.map[pos.y][pos.x] = '#';
		last = tmp;
	}
	return (matrice.map);
}

char	**unfill(int code, t_matrice matrice, t_pos pos)
{
	int	tmp;
	int last;
	int d;

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
		matrice.map[pos.y][pos.x] = '.';
		last = tmp;
	}
	return (matrice.map);
}
