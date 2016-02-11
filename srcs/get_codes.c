/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_codes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 17:43:49 by bchaleil          #+#    #+#             */
/*   Updated: 2016/02/11 10:46:49 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int		*get_codes(void)
{
	int	*r;

	if (!(r = (int*)malloc(sizeof(int) * 19 + 1)))
		return (NULL);
	r[0] = 1111;
	r[1] = 1234;
	r[2] = 2212;
	r[3] = 1123;
	r[4] = 1211;
	r[5] = 1233;
	r[6] = 1112;
	r[7] = 1231;
	r[8] = 1222;
	r[9] = 3123;
	r[10] = 1212;
	r[11] = 1122;
	r[12] = 2312;
	r[13] = 2123;
	r[14] = 1121;
	r[15] = 1232;
	r[16] = 2122;
	r[17] = 1223;
	r[18] = 2121;
	r[19] = -1337;
	return (r);
}
