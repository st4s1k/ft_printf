/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgirlea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:35:32 by sgirlea           #+#    #+#             */
/*   Updated: 2017/02/23 19:22:17 by sgirlea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define FSPEC(C) (*ft_strchr("sSpdDioOuUxXcCeEgGaAn%", (C)))

char	ft_get_format(va_list *parg)
{
	ft_bzero(g_fmt.flags, sizeof(char) * 5);
	ft_bzero(g_fmt.len, sizeof(int) * 5);
	g_fmt.width = 0;
	g_fmt.prec = -1;
	while (*g_cur && !FSPEC(*g_cur))
	{
		if (!(ft_is_flag() || ft_is_len() ||
			ft_is_prec(parg) || ft_is_width(parg)))
			break ;
	}
	return (*g_cur);
}
