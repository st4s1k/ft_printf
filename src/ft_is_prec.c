/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgirlea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:44:14 by sgirlea           #+#    #+#             */
/*   Updated: 2017/02/23 17:44:15 by sgirlea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_is_prec(va_list *parg)
{
	if (*g_cur == '.')
	{
		while (*g_cur == '.')
			++g_cur;
		if (*g_cur == '*')
		{
			g_fmt.prec = va_arg(*parg, int);
			while (*g_cur == '*')
				++g_cur;
		}
		else if (IS_NBR)
		{
			g_fmt.prec = ft_atoi(g_cur);
			ft_skip_nbr();
		}
		else
			g_fmt.prec = 0;
		return (1);
	}
	return (0);
}
