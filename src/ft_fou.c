/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fou.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgirlea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 21:25:23 by sgirlea           #+#    #+#             */
/*   Updated: 2017/02/18 21:25:25 by sgirlea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define BASE ((*g_cur) == ('o') || (*g_cur) == ('O') ? 8 : 10)

int	ft_fou(va_list *parg)
{
	if (*g_cur < 'a')
		g_fmt.len[1] = 1;
	if ((g_n = ft_uoxlen(parg)) ||
		g_fmt.flags[4] || g_fmt.prec || g_fmt.width)
	{
		g_s = ft_itoa_base((uintmax_t)g_n, BASE, 0);
		if (g_n && g_fmt.flags[4] && (*g_cur == 'o' || *g_cur == 'O'))
			g_fmt.prec = (int)ft_strlen(g_s) + 1;
		if (g_fmt.prec > (int)ft_strlen(g_s))
			ft_dioux_prec();
		else if (!g_n && !g_fmt.prec && !g_fmt.flags[4])
			*g_s = '\0';
		if (g_fmt.width > (int)ft_strlen(g_s))
			ft_process_width((int)ft_strlen(g_s));
		if (!g_stop)
			ft_putstr(g_s);
		g_size = ft_strlen(g_s);
		free(g_s);
		return (g_size);
	}
	return (0);
}
