/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 15:58:15 by bchaleil          #+#    #+#             */
/*   Updated: 2016/01/16 19:43:56 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	fillit(int ac, char **av)
{
	if (ac != 2)
		return (show_usage());	
	int	fd;
	int	count;
	char buf;
	count = 0;
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (show_error());
	count = 0;
	while (read(fd, &buf, 1))
	{
		if (buf != '.' && buf != '#' && buf != '\n')
			return (show_error());
		count++;
		if (count % 5 == 0)
			if (buf != '\n')
				return (show_error());
		if (count == 20)
			count = -1;
	}
}
