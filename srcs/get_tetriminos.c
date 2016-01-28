/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetriminos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 15:04:36 by bchaleil          #+#    #+#             */
/*   Updated: 2016/01/28 20:59:49 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static int		get_cursor_pos(char *matrice)
{
	int		i;
	int		r;
	int		ret;

	i = 0;
	r = 0;
	ret = 1337;
	while (i < 20)
	{
		if (matrice[i] == '#')
		{
			if (r == 0)
				return (0);
			if (r < ret)
				ret = r;
			while (matrice[i] != '\n')
				i++;
		}
		r++;
		if (matrice[i] == '\n')
			r = 0;
		i++;
	}
	return (ret);
}

static int		get_code(char *matrice)
{
	int	pos;
	int i;
	int j;
	int code;

	pos = get_cursor_pos(matrice);
	i = pos;
	j = 1;
	code = 0;
	while (i < 20)
	{
		if (matrice[i] == '#' && EDGE(matrice, i))
		{
			code *= 10;
			code += j;
		}
		j++;
		if (matrice[i] == '\n')
		{
			j = 1;
			i += pos;
		}
		i++;
	}
	return (code);
}

static int		valid_tetramino(int code)
{
	int	*codes;
	int i;

	codes = get_codes();
	i = 0;
	while (codes[i] != -1337)
		if (codes[i++] == code)
			return (1);
	return (0);
}

int				get_tetriminos(char *file_name, t_tetrimino **tetri_list)
{
	char		*matrice;
	int			tetraminos_count;
	int			i;
	int			code;

	matrice = get_matrice(file_name);
	tetraminos_count = ((ft_strlen(matrice) + 1) / 21);
	i = 0;
	while (i < tetraminos_count)
	{
		code = get_code(matrice + (21 * i));
		if (valid_tetramino(code))
			bc_list_push(tetri_list, i, code);
		else
			return (0);
		i++;
	}
	return (1);
}
