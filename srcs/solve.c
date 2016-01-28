/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 11:54:37 by bchaleil          #+#    #+#             */
/*   Updated: 2016/01/28 20:57:21 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static t_pos	return_pos(int x, int y)
{
	t_pos	r;

	r.x = x;
	r.y = y;
	return (r);
}

static t_pos	pos_modulo(t_pos pos, int len)
{
	pos.x = (pos.x + 1) % len;
	if (pos.x == 0)
		pos.y = (pos.y + 1) % len;
	return (pos);
}

static void		display_matrice(t_matrice matrice)
{
	int	y;
	int	x;

	y = 0;
	while (y <= matrice.size_y)
	{
		x = 0;
		while (x <= matrice.size_x)
		{
			ft_putchar(matrice.map[y][x]);
			x++;
		}
		while (x < 4)
		{
			ft_putchar('.');
			x++;
		}
		ft_putchar('\n');
		y++;
	}
	while (y < 4)
	{
		ft_putstr("....\n");
		y++;
	}
}

static char		**recurse(t_matrice matrice, t_tetrimino *lst, t_pos pos)
{
	char	**tmp;

	if (lst == NULL)
		return (matrice.map);
	if ((pos.x == matrice.size_x && pos.y == matrice.size_y))
		return (NULL);
	if (check_fill(*lst, matrice, pos))
	{
		matrice.map = fill(*lst, matrice, pos);
		tmp = recurse(matrice, lst->next, return_pos(0, 0));
		if (tmp == NULL)
		{
			matrice.map = unfill(*lst, matrice, pos);
			return (recurse(matrice, lst, pos_modulo(pos, matrice.size_y + 1)));
		}
		return (tmp);
	}
	return (recurse(matrice, lst, pos_modulo(pos, matrice.size_y + 1)));
}

void			solve(t_tetrimino *lst)
{
	t_matrice		matrice;
	int				len;

	len = 2;
	matrice = create_matrice(len, len);
	while ((matrice.map = recurse(matrice, lst, return_pos(0, 0))) == NULL)
	{
		matrice = create_matrice(len, len);
		len++;
	}
	if (matrice.map)
		display_matrice(matrice);
}
