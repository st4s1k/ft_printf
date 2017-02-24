/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgirlea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 18:16:58 by sgirlea           #+#    #+#             */
/*   Updated: 2017/02/23 19:19:19 by sgirlea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char *format, ...)
{
	va_list	arg;
	int		ret;

	ret = 0;
	g_cur = format;
	g_stop = 0;
	va_start(arg, format);
	while (*g_cur)
	{
		g_free = 1;
		g_size = 0;
		g_s = NULL;
		g_n = 0;
		if (!ft_find_fspec(&ret) ||
			!ft_get_format(&arg))
			break ;
		ret += ft_format(&arg);
		++g_cur;
	}
	va_end(arg);
	return (ret);
}
