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

int			valid_tet(char *file)	// 19 lines
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
			g_tet = (int*)malloc(sizeof(g_tet) * i);
			return (1);
		}
		if (tmp != '\n')
			return (0);
	}
}

int		load_tet(char *file)
{
	return (0);
}
