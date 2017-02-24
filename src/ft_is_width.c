/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgirlea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:52:16 by sgirlea           #+#    #+#             */
/*   Updated: 2017/02/23 17:52:19 by sgirlea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_is_width(va_list *parg)
{
	if (*g_cur == '*')
	{
		g_fmt.width = va_arg(*parg, int);
		if (g_fmt.width < 0)
		{
			g_fmt.width = -g_fmt.width;
			g_fmt.flags[0] = '-';
		}
		while (*g_cur == '*')
			++g_cur;
	}
	else if (IS_NBR)
	{
		g_fmt.width = ft_atoi(g_cur);
		ft_skip_nbr();
	}
	else
		return (0);
	return (1);
}
