#include "lib.h"

char	**fill_matrice(void)
{
	char	**matrice;
	int x;
	int y;

	matrice = create_matrice(10, 10);
	y = 0;
	while (y < 10)
	{
		x = 0;
		while (x < 9)
		{
			matrice[y][x] = '.';
			x++;
		}
		matrice[y][x] = '\0';
		y++;
	}
	return (matrice);
}

void	display_matrice(char **matrice, int y)
{
	int i;

	i = 0;
	while (i < y)
	{
		ft_putstr(matrice[y]);
		ft_putchar('\n');
		i++;
	}
}

int		fill(int code, int x, int y)
{

	return (1);
}

void	solve(t_tetrimino *tetri_list)
{
	char	**matrice;

	matrice = fill_matrice();
	display_matrice(matrice, 9);
	while (tetri_list)
	{
		printf("tetrimino->id = %d\ntetrimino->signature = %d\n", tetri_list->id, tetri_list->signature);
		tetri_list = tetri_list->next;
	}
}
