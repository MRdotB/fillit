/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 17:19:07 by bchaleil          #+#    #+#             */
/*   Updated: 2016/01/18 11:09:15 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int		check_error1_ex(int	fd, char buf)
{
	int count;
	int sharp;

	count = 0;
	sharp = 0;
	while (read(fd, &buf, 1))
	{
		sharp = (buf == '#') ? sharp + 1 : sharp + 0;
		if (++count % 5 == 0)
		{
			if (buf != '\n')
				return (0);
		}
		else
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
	return (1);
}

int		check_error1(char *file_name)
{
	int	fd;
	char buf;

	buf = 0;
	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (0);
	if (check_error1_ex(fd, buf) == 0)
		return (0);
	return ((close(fd) == -1)) ? 0 : 1;
}
