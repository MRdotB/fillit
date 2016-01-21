#include "lib.h"

char	**create_matrice(unsigned int x, unsigned int y)
{
	char			**matrice;
	unsigned int	i;

	matrice = (char**)malloc(sizeof(char**) * y);
	i = 0;
	while (i < y)
	{
		matrice[i] = (char*)malloc(sizeof(char*) * (x + 1));
		i++;
	}
	return (matrice);
}
