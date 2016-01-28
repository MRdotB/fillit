/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_matrice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 14:59:30 by bchaleil          #+#    #+#             */
/*   Updated: 2016/01/28 21:00:58 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static char		*bt_concat(char c, char *str)
{
	char	*r;
	int		i;

	r = (char*)malloc(sizeof(char) * ft_strlen(str) + 2);
	if (r == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		r[i] = str[i];
		i++;
	}
	r[i++] = c;
	r[i] = '\0';
	free(str);
	return (r);
}

char			*get_matrice(char *file_name)
{
	int		fd;
	char	buf;
	char	*r;

	r = (char*)malloc(sizeof(char) * 1);
	if (r == NULL)
		return (NULL);
	r[0] = '\0';
	fd = open(file_name, O_RDONLY);
	while (read(fd, &buf, 1))
		r = bt_concat(buf, r);
	close(fd);
	return (r);
}
