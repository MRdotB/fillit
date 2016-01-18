/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 17:19:07 by bchaleil          #+#    #+#             */
/*   Updated: 2016/01/17 17:37:13 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	check_error1(char *file_name)
{
	int	fd;
	int	count;
	char buf;

	count = 0;
	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (show_error());
	while (read(fd, &buf, 1))
	{
		if (++count % 5 == 0)
		{
			if (buf != '\n')
				return (show_error());
		}
		else
			if (buf != '.' && buf != '#')
				return (show_error());
		if (count == 20)
			count = -1;
	}
	if ((close(fd) == -1))
		return (show_error());
	return (1);
}
