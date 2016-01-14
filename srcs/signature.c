/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signature.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2100/01/01 00:00:00 by glodenos          #+#    #+#             */
/*   Updated: 2100/01/01 00:00:00 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static int	sig_tet_ex(char *tet)	// 18 lines
{
	if (!strcmp(tet, "#.###"))
		return (12);
	else if (!strcmp(tet, "##..##"))
		return (13);
	else if (!strcmp(tet, "#...#...#...#"))
		return (14);
	else if (!strcmp(tet, "####"))
		return (15);
	else if (!strcmp(tet, "#..###"))
		return (16);
	else if (!strcmp(tet, "#...##..#"))
		return (17);
	else if (!strcmp(tet, "###..#"))
		return (18);
	else if (!strcmp(tet, "#..##...#"))
		return (19);
	else
		return (0);
}

int			sig_tet(char *tet)	// 24 lines
{
	if (!strcmp(tet, "#...##...#"))
		return (1);
	else if (!strcmp(tet, "##.##"))
		return (2);
	else if (!strcmp(tet, "#..##..#"))
		return (3);
	else if (!strcmp(tet, "##...##"))
		return (4);
	else if (!strcmp(tet, "#...#..##"))
		return (5);
	else if (!strcmp(tet, "#...###"))
		return (6);
	else if (!strcmp(tet, "##..#...#"))
		return (7);
	else if (!strcmp(tet, "###...#"))
		return (8);
	else if (!strcmp(tet, "#...#...##"))
		return (9);
	else if (!strcmp(tet, "###.#"))
		return (10);
	else if (!strcmp(tet, "##...#...#"))
		return (11);
	else
		return (sig_tet_ex(tet));
} 
