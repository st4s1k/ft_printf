/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgirlea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 19:07:12 by sgirlea           #+#    #+#             */
/*   Updated: 2017/02/12 19:07:14 by sgirlea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fwstr(va_list *parg)
{
	wchar_t		*ws;

	if ((ws = va_arg(*parg, wchar_t *)))
	{
		if (!g_stop)
			ft_putwstr(ws);
		return ((int)ft_strlen((char *)ws));
	}
	if (!g_stop)
		ft_putstr("(null)");
	return (6);
}
