/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgirlea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 19:06:55 by sgirlea           #+#    #+#             */
/*   Updated: 2017/02/12 19:06:57 by sgirlea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fchar(va_list *parg)
{
	char	chr[2];

	chr[0] = (*g_cur == 'c' ? va_arg(*parg, int) : '%');
	chr[1] = '\0';
	if (!g_stop && g_fmt.width > 1)
	{
		g_s = ft_strdup(chr);
		ft_process_width(1);
		ft_putstr(g_s);
		free(g_s);
		if (!chr[0])
			g_stop = 1;
	}
	else
		ft_putchar(chr[0]);
	return (g_fmt.width > 1 ? g_fmt.width : 1);
}
