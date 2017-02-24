/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgirlea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:34:06 by sgirlea           #+#    #+#             */
/*   Updated: 2017/02/23 17:34:08 by sgirlea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_is_len(void)
{
	if (*g_cur == 'h')
		g_fmt.len[0] = (*(g_cur - 1) == 'h' ? 2 : 1);
	else if (*g_cur == 'l')
		g_fmt.len[1] = (*(g_cur - 1) == 'l' ? 2 : 1);
	else if (*g_cur == 'L')
		g_fmt.len[2] = 1;
	else if (*g_cur == 'j')
		g_fmt.len[3] = 1;
	else if (*g_cur == 'z')
		g_fmt.len[4] = 1;
	else
		return (0);
	++g_cur;
	return (1);
}
