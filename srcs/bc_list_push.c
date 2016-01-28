/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bc_list_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil </var/mail/bchaleil>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 21:55:45 by bchaleil          #+#    #+#             */
/*   Updated: 2016/01/28 21:56:55 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lib.h"

void	bc_list_push(t_tetrimino **list, int id, int code)
{
	if (*list == NULL)
		*list = bc_create_elem(id, code);
	else if ((*list)->next == NULL)
		(*list)->next = bc_create_elem(id, code);
	else
		bc_list_push(&(*list)->next, id, code);
}
