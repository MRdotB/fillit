/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2100/01/01 00:00:00 by glodenos          #+#    #+#             */
/*   Updated: 2016/01/29 01:17:47 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# define EDGE(m, i) (m[i - 1] == '#' || m[i + 1] == '#'|| m[i + 5] == '#' || m[i - 5] == '#')
# define ISUPPER(c) (c >= 'A' && c <= 'Z')
# define ISLOWER(c) (c >= 'a' && c <= 'z')
# define ISALPHA(c) (ISLOWER(c) || ISUPPER(c))

typedef struct	s_tetrimino
{
	int					id;
	int					code;
	struct s_tetrimino	*next;
}				t_tetrimino;

typedef struct	s_pos
{
	int	x;
	int	y;
}				t_pos;

typedef struct	s_matrice
{
	char	**map;
	int		size_x;
	int		size_y;
}				t_matrice;

int				ft_strlen(char *str);
void			ft_putchar(char c);
void			ft_putstr(char *str);
void			fillit(int ac, char **av);
void			show_usage(void);
void			show_error(void);
int				check_error1(char *file_name);
int				*get_codes(void);
char			*get_matrice(char *file_name);
int				get_tetriminos(char *file_name, t_tetrimino **tetri_list);
t_tetrimino		*bc_create_elem(int id, int signature);
void			bc_list_push(t_tetrimino **list, int id, int signature);
void			solve(t_tetrimino *tetri_list);
t_matrice		create_matrice(unsigned int x, unsigned int y);
int				check_fill(t_tetrimino tetrimino, t_matrice matrice, t_pos pos);
char			**fill(t_tetrimino tetrimino, t_matrice matrice, t_pos pos);
char			**unfill(t_tetrimino tetrimino, t_matrice matrice, t_pos pos);

#endif
