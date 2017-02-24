/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgirlea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 19:14:12 by sgirlea           #+#    #+#             */
/*   Updated: 2017/02/19 12:09:37 by sgirlea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define VA_PTR (intmax_t)va_arg(*parg, void *)
#define FT_HEXLEN(parg) ((*g_cur) == ('p') ? VA_PTR : ft_uoxlen(parg))
#define PREFIX_0X (*g_cur == 'X' ? "0X" : "0x")

static void	ft_0x(void)
{
	g_size += 2;
	if (g_fmt.flags[3] && g_fmt.width > g_size)
		ft_process_width(g_size);
	if (g_n || (*g_cur == 'p'))
	{
		if (g_s)
			ft_join_gs(PREFIX_0X, 2, g_s, ft_strlen(g_s));
		else
			g_s = (*g_cur == 'X' ? "0X" : "0x");
	}
	else
		g_size -= 2;
	if (!g_fmt.flags[3] && g_fmt.width > g_size)
		ft_process_width(g_size);
}

int			ft_fhex(va_list *parg)
{
	if ((g_n = FT_HEXLEN(parg)) || *g_cur == 'p' || g_fmt.prec || g_fmt.width)
	{
		g_0x = 0;
		g_s = ft_itoa_base((uintmax_t)g_n, 16, (*g_cur == 'X' ? 1 : 0));
		if (g_fmt.prec > (int)ft_strlen(g_s))
			ft_dioux_prec();
		else if (!g_n && !g_fmt.prec && !g_fmt.flags[4])
			*g_s = '\0';
		g_size = (int)ft_strlen(g_s);
		if (*g_cur == 'p' || g_fmt.flags[4])
			ft_0x();
		else if (g_fmt.width > g_size)
			ft_process_width(g_size);
		if (!g_stop)
			ft_putstr(g_s);
		g_size = ft_strlen(g_s);
		free(g_s);
		return (g_size);
	}
	return (0);
}
