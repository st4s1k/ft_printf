/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fwchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgirlea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 21:16:54 by sgirlea           #+#    #+#             */
/*   Updated: 2017/02/20 21:17:16 by sgirlea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fwchar(va_list *parg)
{
	wint_t	wi[2];

	wi[0] = va_arg(*parg, wint_t);
	wi[1] = 0;
	if (!g_stop && g_fmt.width > 1)
	{
		g_s = ft_strdup((char *)wi);
		ft_process_width(ft_wcharsize(wi[0]));
		ft_putstr(g_s);
		free(g_s);
		if (!wi[0])
			g_stop = 1;
	}
	else
		ft_putwchar(wi[0]);
	return (g_fmt.width > 1 ? g_fmt.width : ft_wcharsize(wi[0]));
}
