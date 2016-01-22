#include "lib.h"

t_matrice	create_matrice(unsigned int x, unsigned int y)
{
	t_matrice		matrice;	
	char			**map;
	unsigned int	i;

	map = (char**)malloc(sizeof(char**) * y);
	i = 0;
	while (i < y)
	{
		map[i] = (char*)malloc(sizeof(char*) * (x));
		i++;
	}
	matrice.map = map;
	matrice.size_x = x - 1;
	matrice.size_y = y - 1;
	return (matrice);
}
