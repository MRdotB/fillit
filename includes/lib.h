/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2100/01/01 00:00:00 by glodenos          #+#    #+#             */
/*   Updated: 2016/01/18 15:01:39 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H
# include <fcntl.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <stdio.h>

void	fillit(int ac, char **av);
void	show_usage(void);
void	show_error(void);
int		check_error1(char *file_name);
int		*get_signatures(void);

typedef struct	s_tetrimino
{
	int					id;
	int					used;
	int					signature;
	struct s_tetrimino	*next;
}				t_tetrimino;

#endif
