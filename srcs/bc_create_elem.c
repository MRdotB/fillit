#include "lib.h"

t_tetrimino		*bc_create_elem(int id, int code)
{
	t_tetrimino	*tetrimino;

	if (!(tetrimino = malloc(sizeof(t_tetrimino))))	
		return (NULL);
	tetrimino->id = id;
	tetrimino->used = 0;
	tetrimino->code = code;
	tetrimino->next = NULL;
	return tetrimino;
}
