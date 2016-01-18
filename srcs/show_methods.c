/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_methods.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 18:44:46 by bchaleil          #+#    #+#             */
/*   Updated: 2016/01/17 18:14:38 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	ft_putstr_err(char *str)
{
	write(2, str, (ft_strlen(str)));
}

void		show_usage(void)
{
	ft_putstr_err("fillit: missing file operand\n");
}

int		show_error(void)
{
	ft_putstr_err("error\n");
	return (0);
}
