/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2100/01/01 00:00:00 by glodenos          #+#    #+#             */
/*   Updated: 2016/02/12 18:16:16 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# define S(c) (c == '#')
# define EDGE(m, i) (S(m[i - 1]) || S(m[i + 1]) || S(m[i + 5]) || S(m[i - 5]))
# define ISUPPER(c) (c >= 'A' && c <= 'Z')

typedef struct		s_matrix
{
	char			**map;
	int				size_x;
	int				size_y;
}					t_matrix;

typedef struct		s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef struct		s_tet
{
	int				id;
	int				code;
	struct s_tet	*next;
}					t_tet;

int				check_error(char *file);
int				check_fill(t_tet tet, t_matrix matrix, t_pos pos);
t_matrix		create_matrix(unsigned int x, unsigned int y);
char			**fill(int code, t_matrix matrix, t_pos pos, char ascii);
void			free_matrix(char **str, int size_y);
void			ft_putchar(char c);
int				ft_strlen(char *str);
int				*get_codes(void);
char			*get_matrix(char *file);
int				get_tet(char *file_name, t_tet **tetri_list);
int				list_count(t_tet *lst);
int				nk_sqrt(int total);
void			push_list(t_tet **list, int id, int code);
void			show_error(void);
void			show_usage(void);
void			solve(t_tet *tetri_list);
void			free_lst(t_tet *lst);

#endif
