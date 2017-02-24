/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgirlea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:53:31 by sgirlea           #+#    #+#             */
/*   Updated: 2017/02/23 17:53:33 by sgirlea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_is_flag(void)
{
	if (*g_cur == '-')
		g_fmt.flags[0] = '-';
	else if (*g_cur == '+')
		g_fmt.flags[1] = '+';
	else if (*g_cur == ' ')
		g_fmt.flags[2] = ' ';
	else if (*g_cur == '0')
		g_fmt.flags[3] = '0';
	else if (*g_cur == '#')
		g_fmt.flags[4] = '#';
	else
		return (0);
	++g_cur;
	return (1);
}
