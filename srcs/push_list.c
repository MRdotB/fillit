/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 22:48:48 by bchaleil          #+#    #+#             */
/*   Updated: 2016/02/10 15:57:43 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static t_tet	*new_elem(int id, int code)
{
	t_tet		*tet;

	if (!(tet = malloc(sizeof(t_tet))))
		return (NULL);
	tet->id = id;
	tet->code = code;
	tet->next = NULL;
	return (tet);
}

void			push_list(t_tet **lst, int id, int code)
{
	if (*lst == NULL)
		*lst = new_elem(id, code);
	else if ((*lst)->next == NULL)
		(*lst)->next = new_elem(id, code);
	else
		push_list(&(*lst)->next, id, code);
}
