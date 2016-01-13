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

// Signature Topologique des pièces
# define A "#...##...#"
# define B "##.##"
# define C "#..##..#"
# define D "##...##"
# define E "#...#..##"
# define F "#...###"
# define G "##..#...#"
# define H "###...#"
# define I "#...#...##"
# define J "###.#"
# define K "##...#...#"
# define L "#.###"
# define M "##..##"
# define N "#...#...#...#"
# define O "####"

int		load_tet(char *file);
int		valid_tet(char *file);

#endif
