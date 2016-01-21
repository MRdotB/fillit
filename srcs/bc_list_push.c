#include "lib.h"

void	bc_list_push(t_tetrimino **list, int id, int signature)
{
	if (*list == NULL)
		*list = bc_create_elem(id, signature);
	else if ((*list)->next == NULL)
		(*list)->next = bc_create_elem(id, signature);
	else
		bc_list_push(&(*list)->next, id, signature);
}
