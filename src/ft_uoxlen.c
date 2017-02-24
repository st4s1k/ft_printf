/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uoxlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgirlea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 12:08:55 by sgirlea           #+#    #+#             */
/*   Updated: 2017/02/19 12:08:57 by sgirlea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	ft_uoxlen(va_list *parg)
{
	if (g_fmt.len[4])
		return ((intmax_t)va_arg(*parg, size_t));
	if (g_fmt.len[3])
		return ((intmax_t)va_arg(*parg, uintmax_t));
	if (g_fmt.len[1] > 1)
		return ((intmax_t)va_arg(*parg, unsigned long long));
	if (g_fmt.len[1] == 1)
		return ((intmax_t)va_arg(*parg, unsigned long));
	if (g_fmt.len[0] == 1)
		return ((intmax_t)(unsigned short)va_arg(*parg, uint));
	if (g_fmt.len[0] > 1)
		return ((intmax_t)(unsigned char)va_arg(*parg, uint));
	return ((intmax_t)va_arg(*parg, uint));
}
