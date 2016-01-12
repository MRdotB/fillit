/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_tet.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2100/01/01 00:00:00 by glodenos          #+#    #+#             */
/*   Updated: 2100/01/01 00:00:00 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int			*g_tet;
int			g_len_tet;

static int	valid_tet_ex(int fd)	// 24 lines
{
	int		d;
	int		i;
	int		k;
	char	tmp;

	d = 0;
	i = 0;
	k = 0;
	while (read(fd, &tmp, 1) || tmp == '.' || tmp == '#' || tmp == '\n')
	{
		if (tmp == '#')
			d++;
		if (d > 4)
			return (0);
		if (i++ == 5)
			return (0);
		if (tmp == '\n')
		{
			i = 0;
			k++;
		}
		if (k == 4 && d == 4)
			return (1);
	}
}

int			valid_tet(char *file)	// 21 lines
{
	int		fd;
	int		i;
	char	tmp;

	i = 1;
	if (!(fd = open(file, O_RDONLY)))
		return (0);
	while (i++)
	{
		if (valid_tet_ex(fd) == 0)
			return (0);
		if (!read(fd, &tmp, 1))
		{
			if(!(g_tet = (int*)malloc(sizeof(g_tet) * i)))
				return (0);
			g_len_tet = i - 1;
			return (1);
		}
		if (tmp != '\n')
			return (0);
	}
}

static int	load_tet_ex(char **tmp)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	return (1);
}

int			load_tet(char *file)	// 20 lines
{
	int		fd;
	int		i;
	int		k;
	char	**tmp;

	k = 0;
	if (!(tmp = (char**)matrix_sqrt(6, 5)))
		return (0);
	if (!(fd = open(file ,O_RDONLY)))
		return (0);
	while (g_len_tet--)
	{
		i = 0;
		while (read(fd, tmp[i], 5) && i < 3)
			i++;
		read(fd, &tmp[i][4], 1);
		if(!(g_tet[k++] = load_tet_ex(tmp)))
			return (0);
	}
	return (1);
}
