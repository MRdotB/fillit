/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 17:21:44 by bchaleil          #+#    #+#             */
/*   Updated: 2016/02/12 17:21:53 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int			list_count(t_tet *lst)
{
	int		i;
	t_tet	*tmp;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int			nk_sqrt(int total)
{
	int		i;

	i = 0;
	while (i * i <= total)
		i++;
	return (i);
}

int			ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void		ft_putchar(char c)
{
	write(1, &c, 1);
}
