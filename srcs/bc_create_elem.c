/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bc_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 22:48:31 by bchaleil          #+#    #+#             */
/*   Updated: 2016/01/28 22:48:35 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

t_tetrimino		*bc_create_elem(int id, int code)
{
	t_tetrimino	*tetrimino;

	if (!(tetrimino = malloc(sizeof(t_tetrimino))))
		return (NULL);
	tetrimino->id = id;
	tetrimino->code = code;
	tetrimino->next = NULL;
	return (tetrimino);
}
