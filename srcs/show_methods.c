/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_methods.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 18:44:46 by bchaleil          #+#    #+#             */
/*   Updated: 2016/01/18 11:10:13 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static void	ft_putstr_err(char *str)
{
	write(2, str, (ft_strlen(str)));
}

void		show_usage(void)
{
	ft_putstr_err("fillit: missing file operand\n");
}

void		show_error(void)
{
	ft_putstr_err("error\n");
}
