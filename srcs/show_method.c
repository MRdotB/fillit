/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_method.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 16:11:43 by bchaleil          #+#    #+#             */
/*   Updated: 2016/01/16 16:17:41 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	ft_putstr_err(char *str)
{
	write(2, str, (ft_strlen(str) - 1));
}

void		show_usage(void)
{
	ft_putstr_err("fillit: missing file operand\n");
}

void		show_error(void)
{
	ft_putstr_err("error\n");
}
