/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 11:54:37 by bchaleil          #+#    #+#             */
/*   Updated: 2016/02/11 15:16:44 by glodenos         ###   ########.fr       */
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

static void		display_matrix(t_matrix matrix)
{
	int	y;
	int	x;

	y = -1;
	while (++y <= matrix.size_y)
	{
		x = -1;
		while (++x <= matrix.size_x)
			ft_putchar(matrix.map[y][x]);
		ft_putchar('\n');
	}
}

static char		**recurse(t_matrix matrix, t_tet *lst, t_pos pos)
{
	char		**tmp;

	if (lst == NULL)
		return (matrix.map);
	if ((pos.x == matrix.size_x && pos.y == matrix.size_y))
		return (NULL);
	if (check_fill(*lst, matrix, pos))
	{
		matrix.map = fill(lst->code, matrix, pos, lst->id + 65);
		tmp = recurse(matrix, lst->next, return_pos(0, 0));
		if (tmp == NULL)
		{
			matrix.map = fill(lst->code, matrix, pos, '.');
			return (recurse(matrix, lst, pos_modulo(pos, matrix.size_y + 1)));
		}
		return (tmp);
	}
	return (recurse(matrix, lst, pos_modulo(pos, matrix.size_y + 1)));
}

void			solve(t_tet *lst)
{
	t_matrix	matrix;
	int			len;

	len = nk_sqrt(list_count(lst));
	matrix = create_matrix(len, len);
	while ((matrix.map = recurse(matrix, lst, return_pos(0, 0))) == NULL)
	{
		free_matrix(matrix.map, matrix.size_y);
		matrix = create_matrix(len, len);
		len++;
	}
	if (matrix.map)
		display_matrix(matrix);
}
