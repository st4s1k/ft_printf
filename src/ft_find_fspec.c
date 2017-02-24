/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_fspec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgirlea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 12:14:46 by sgirlea           #+#    #+#             */
/*   Updated: 2017/02/19 12:14:48 by sgirlea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_find_fspec(int *pret)
{
	while (*g_cur && *g_cur != '%')
	{
		if (!g_stop)
			ft_putchar(*g_cur);
		++*pret;
		++g_cur;
	}
	if (*g_cur)
		++g_cur;
	return (*g_cur);
}
