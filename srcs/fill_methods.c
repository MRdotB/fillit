/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_methods.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 18:47:04 by bchaleil          #+#    #+#             */
/*   Updated: 2016/01/27 18:17:43 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int		check_fill_ex(t_tetrimino tetrimino, t_matrice matrice, t_pos pos)
{
		if (pos.x >= 0 && pos.y >= 0 && pos.x <= matrice.size_x && pos.y <= matrice.size_y)
		{
			if (ISUPPER(matrice.map[pos.y][pos.x]))
				return (0);
		}
		else
			return (0);

}

int		check_fill(t_tetrimino tetrimino, t_matrice matrice, t_pos pos)
{
	int	tmp;
	int last;
	int d;

	d = 1000;
	last = 0;
	tmp = 0;
	while (d != 0)
	{
		tmp = tetrimino.code / d;
		tetrimino.code %= d;
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
		if (!(check_fill_ex(tetrimino, matrice, pos)))
			return (0);
		last = tmp;
	}
	return (1);
}

char	**fill(t_tetrimino tetrimino, t_matrice matrice, t_pos pos)
{
	int	tmp;
	int last;
	int d;

	d = 1000;
	last = 0;
	tmp = 0;
	while (d != 0)
	{
		tmp = tetrimino.code / d;
		tetrimino.code %= d;
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
		matrice.map[pos.y][pos.x] = tetrimino.id + 65;
		last = tmp;
	}
	return (matrice.map);
}

char	**unfill(t_tetrimino tetrimino, t_matrice matrice, t_pos pos)
{
	int	tmp;
	int last;
	int d;

	d = 1000;
	last = 0;
	tmp = 0;
	while (d != 0)
	{
		tmp = tetrimino.code / d;
		tetrimino.code %= d;
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
