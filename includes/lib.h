/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2100/01/01 00:00:00 by glodenos          #+#    #+#             */
/*   Updated: 2100/01/01 00:00:00 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H
# include <fcntl.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# define BH		 1
# define BV 	 2
# define LL_A	 3
# define LL_B	 4
# define LL_C	 5
# define LL_D	 6
# define LR_A	 7
# define LR_B	 8
# define LR_C	 9
# define LR_D	10
# define S		11
# define T_A	12
# define T_B	13
# define T_C	14
# define T_D	15
# define ZR_A	16
# define ZR_B	17
# define ZR_C	18
# define ZR_D	19
# define ZL_A	20
# define ZL_B	21
# define ZL_C	22
# define ZL_D	23

#include <stdio.h>

int		load_tet(char *file);
int		valid_tet(char *file);

#endif
