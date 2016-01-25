/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2100/01/01 00:00:00 by glodenos          #+#    #+#             */
/*   Updated: 2016/01/25 19:59:52 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <stdio.h>
# include "libft.h"
# define SAP(c) (c == '#')
# define EDGE(m, i) (m[i - 1] == '#' || m[i + 1] == '#'|| m[i + 5] == '#' || m[i - 5] == '#')


typedef struct	s_tetrimino
{
	int					id;
	int					used;
	int					signature;
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

void			fillit(int ac, char **av);
void			show_usage(void);
void			show_error(void);
int				check_error1(char *file_name);
int				*get_signatures(void);
char			*get_matrice(char *file_name);
int				get_tetriminos(char *file_name, t_tetrimino **tetri_list);
t_tetrimino		*bc_create_elem(int id, int signature);
void			bc_list_push(t_tetrimino **list, int id, int signature);
void			solve(t_tetrimino *tetri_list);
t_matrice		create_matrice(unsigned int x, unsigned int y);
int				check_fill(int code, t_matrice matrice, t_pos pos);
char			**fill(int code, t_matrice matrice, t_pos pos);
char			**unfill(int code, t_matrice matrice, t_pos pos);

#endif
