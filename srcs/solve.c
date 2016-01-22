/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 11:54:37 by bchaleil          #+#    #+#             */
/*   Updated: 2016/01/22 18:15:50 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	**fill_matrice(t_matrice matrice)
{
	int x;
	int y;

	y = 0;
	while (y < matrice.size_y)
	{
		x = 0;
		while (x < matrice.size_x)
		{
			matrice.map[y][x] = '.';
			x++;
		}
		y++;
	}
	return (matrice.map);
}

static	t_pos	return_pos(int x, int y)
{
	t_pos	r;

	r.x = x;
	r.y = y;
	return (r);
}

void	display_matrice(t_matrice matrice)
{
	int	y;
	int x;

	y = 0;
	while (y < matrice.size_y)
	{
		x = 0;
		while (x < matrice.size_x)
		{
			ft_putchar(matrice.map[y][x]);	
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}

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
		if (pos.x >= 0 && pos.y >= 0 && pos.x <= matrice.size_x && pos.y <= matrice.size_y)
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
int		square_size(t_matrice matrice)
{
	int x;
	int y;
	int	r;

	x = matrice.size_x;
	y = matrice.size_y;
	while (x >= 0 && y >= 0)
	{
		r = x;
		while (x >= 0)
		{
			if (matrice.map[y][x] == '#')
				return (r);
			x--;
		}
		x = r - 1;
		while (y >= 0)
		{
			if (matrice.map[y][x] == '#')
				return (r);
			y--;
		}
		y = r;
		r = x;
	}
	return (0);
}

t_pos	find_next(int best, t_matrice matrice, int code)
{
	
	if (check_fill(code, matrice, pos))
	{
		fill(code, matrice, pos);
	}
}


int		recurse_solve(t_matrice	matrice, t_tetrimino **tetri_list, t_pos pos)
{
	t_tetrimino *list;

	list = *tetri_list;
	if (list == NULL)
	{
		display_matrice(matrice);
		printf("%d\n", square_size(matrice));
		return (1);
	}
	if (check_fill(list->signature, matrice, pos))
	{
		fill(list->signature, matrice, pos);
		list->used = 1;
		return (recurse_solve(matrice, &(list->next), return_pos(pos.x + 1, pos.y)));
	}
	else
	{
		recurse_solve(matrice, &list, return_pos(pos.x + 1, pos.y));
	}
}

void	solve(t_tetrimino *tetri_list)
{
	t_matrice		matrice;	

	matrice = create_matrice(10, 10);
	matrice.map = fill_matrice(matrice);
	recurse_solve(matrice, &tetri_list, return_pos(0, 0));
}
