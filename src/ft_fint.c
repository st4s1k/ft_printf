/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgirlea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 19:14:03 by sgirlea           #+#    #+#             */
/*   Updated: 2017/02/18 19:14:06 by sgirlea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define QPREFIX (g_n < 0 || g_fmt.flags[1] || g_fmt.flags[2])

static void		ft_int_prefix(char pr)
{
	char	*temp;
	int		len;

	len = ft_strlen(g_s);
	temp = (char *)malloc(sizeof(char) * (len + 1));
	temp[len] = '\0';
	ft_copy(temp, g_s, 0, len);
	free(g_s);
	g_s = (char *)malloc(sizeof(char) * (len + 2));
	g_s[0] = pr;
	g_s[len + 1] = '\0';
	ft_copy(g_s, temp, 1, len + 1);
	free(temp);
}

static intmax_t	ft_intlen(va_list *parg)
{
	if (*g_cur == 'D')
		return ((intmax_t)va_arg(*parg, long));
	if (g_fmt.len[4])
		return ((intmax_t)va_arg(*parg, size_t));
	if (g_fmt.len[3])
		return (va_arg(*parg, intmax_t));
	if (g_fmt.len[1] > 1)
		return ((intmax_t)va_arg(*parg, long long));
	if (g_fmt.len[1] == 1)
		return ((intmax_t)va_arg(*parg, long));
	if (g_fmt.len[0] == 1)
		return ((intmax_t)(short)va_arg(*parg, int));
	if (g_fmt.len[0] > 1)
		return ((intmax_t)(char)va_arg(*parg, int));
	return ((intmax_t)va_arg(*parg, int));
}

int				ft_fint(va_list *parg)
{
	if ((g_n = ft_intlen(parg)) || g_fmt.prec || g_fmt.width)
	{
		g_s = ft_itoa_base((uintmax_t)(g_n < 0 ? -g_n : g_n), 10, 0);
		if (g_fmt.prec > (int)ft_strlen(g_s) && !(g_fmt.flags[3] = '\0'))
			ft_dioux_prec();
		else if (!g_n && !g_fmt.prec)
			*g_s = '\0';
		g_size += (QPREFIX ? (int)ft_strlen(g_s) + 1 : (int)ft_strlen(g_s));
		if (g_fmt.flags[3] && g_fmt.width > g_size)
			ft_process_width(g_size);
		if (g_n < 0)
			ft_int_prefix('-');
		else if (g_fmt.flags[1])
			ft_int_prefix('+');
		else if (g_fmt.flags[2])
			ft_int_prefix(' ');
		if (!g_fmt.flags[3] && g_fmt.width > g_size)
			ft_process_width(g_size);
		if (!g_stop)
			ft_putstr(g_s);
		g_size = ft_strlen(g_s);
		free(g_s);
		return (g_size);
	}
	return (0);
}
