/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetriminos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 15:04:36 by bchaleil          #+#    #+#             */
/*   Updated: 2016/01/18 21:30:38 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static char		*bt_concat(char c, char *str)
{
	char	*r;
	int		i;

	r = (char*)malloc(ft_strlen(str) + 2);
	i = 0;
	while (str[i])
	{
		r[i] = str[i];
		i++;
	}
	r[i] = c;
	i++;
	r[i] = '\0';
	free(str);
	return (r);
}

char			*get_matrice(char *file_name)
{
	int fd;
	char buf;
	char *r;

	r = malloc(1);
	r[0] = '\0';
	fd = open(file_name, O_RDONLY);
	while (read(fd, &buf, 1))
		r = bt_concat(buf, r);
	close(fd);
	return (r);
}

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

t_tetrimino		*get_tetriminos(char *file_name)
{
	int			i;
	int			j;
	int			k;
	int			*sign;
	char		*matrice;
	int			code;
	int			pos;
	t_tetrimino *first;

	i = 0;
	k = 1;
	j = 1;
	code = 0;
	sign = get_signatures();
	matrice = get_matrice(file_name);
	pos		= get_cursor_pos(matrice);
	i		= pos;

	while (matrice[i])
	{
		if (matrice[i] == '#')
		{
			code *= 10;
			code += j;
		}
			j++;
		if (matrice[i] == '\n')
		{
			j = 0;
			i += pos;
		}
		else
			i++;
	}
	printf("\n%d", get_cursor_pos(matrice));
	printf("\n%d", code);
	return (first);
}
