/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tet.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 15:04:36 by bchaleil          #+#    #+#             */
/*   Updated: 2016/02/29 11:03:55 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static int		get_colone_y(char *matrix)
{
	int		i;
	int		r;
	int		ret;

	i = -1;
	r = 0;
	ret = 1337;
	while (++i < 20)
	{
		if (matrix[i] == '#')
		{
			if (r == 0)
				return (0);
			if (r < ret)
				ret = r;
			while (matrix[i] != '\n')
				i++;
		}
		r++;
		if (matrix[i] == '\n')
			r = 0;
	}
	return (ret);
}

static int		edge_count(char *matrix, int i)
{
	int	c;

	c = 0;
	if (matrix[i - 1] == '#')
		c++;
	if (matrix[i + 1] == '#')
		c++;
	if (matrix[i - 5] == '#')
		c++;
	if (matrix[i + 5] == '#')
		c++;
	return (c);
}

static int		get_code(char *matrix, int code, int count)
{
	int	pos;
	int i;
	int j;

	pos = get_colone_y(matrix);
	i = pos - 1;
	j = 1;
	while (++i < 20)
	{
		if (matrix[i] == '#' && EDGE(matrix, i))
		{
			count += edge_count(matrix, i);
			code *= 10;
			code += j;
		}
		j++;
		if (matrix[i] == '\n')
		{
			j = 1;
			i += pos;
		}
	}
	return (count < 5) ? (0) : (code);
}

static int		valid_tet(int code)
{
	int	*codes;
	int i;

	codes = get_codes();
	i = 0;
	while (codes[i] != -1337)
	{
		if (codes[i++] == code)
		{
			free(codes);
			return (1);
		}
	}
	free(codes);
	return (0);
}

int				get_tet(char *file_name, t_tet **tetri_list)
{
	char		*matrix;
	int			tet_count;
	int			i;
	int			code;

	matrix = get_matrix(file_name);
	tet_count = ((ft_strlen(matrix) + 1) / 21);
	if (tet_count == 0)
		return (0);
	i = 0;
	while (i < tet_count)
	{
		code = get_code(matrix + (21 * i), 0, 0);
		if (valid_tet(code))
			push_list(tetri_list, i, code);
		else
			return (0);
		i++;
	}
	return (1);
}
