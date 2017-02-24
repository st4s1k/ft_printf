/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgirlea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:20:04 by sgirlea           #+#    #+#             */
/*   Updated: 2017/01/31 18:21:31 by sgirlea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list *parg)
{
	if (*g_cur == 'o' || *g_cur == 'O' || *g_cur == 'u' || *g_cur == 'U')
		return (ft_fou(parg));
	if (*g_cur == 'i' || *g_cur == 'd' || *g_cur == 'D')
		return (ft_fint(parg));
	if (*g_cur == 'p' || *g_cur == 'x' || *g_cur == 'X')
		return (ft_fhex(parg));
	if (*g_cur == '%' || *g_cur == 'c')
		return (ft_fchar(parg));
	if (*g_cur == 's')
		return (ft_fstr(parg));
	if (*g_cur == 'C')
		return (ft_fwchar(parg));
	if (*g_cur == 'S')
		return (ft_fwstr(parg));
	if (!g_stop)
		ft_putchar(*g_cur);
	return (1);
}
