/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 17:19:07 by bchaleil          #+#    #+#             */
/*   Updated: 2016/02/26 19:14:49 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void			show_error(void)
{
	write(1, "error\n", 6);
}

void			show_usage(void)
{
	write(2, "fillit: missing file operand\n", 29);
}

static int		check_error_ex(int fd, char buf, int count, int sharp)
{
	while (read(fd, &buf, 1))
	{
		sharp += (buf == '#') ? 1 : 0;
		if (++count % 5 == 0)
			if (buf != '\n')
				return (0);
		if (count % 5 != 0)
			if (buf != '.' && buf != '#')
				return (0);
		if (count == 20)
		{
			if (sharp != 4)
				return (0);
			count = -1;
			sharp = 0;
		}
	}
	if (count != -1)
		return (0);
	return (1);
}

int				check_error(char *file)
{
	int		fd;
	char	buf;

	buf = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (0);
	if (check_error_ex(fd, buf, 0, 0) == 0)
		return (0);
	return ((close(fd) == -1)) ? 0 : 1;
}
