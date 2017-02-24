/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_width.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgirlea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 19:14:51 by sgirlea           #+#    #+#             */
/*   Updated: 2017/02/23 19:22:30 by sgirlea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define SC (*g_cur == 's' || *g_cur == 'S' || *g_cur == 'c' || *g_cur == 'C')
#define QHEX (*g_cur == 'x' || *g_cur == 'X')
#define Q0X ((QHEX && g_fmt.flags[4]) || *g_cur == 'p')
#define QZERO (!g_fmt.flags[0] && g_fmt.flags[3] && (!g_fmt.flags[4] || QHEX))

void	ft_process_width(int len)
{
	char	*new_str;
	uint	delta;

	delta = g_fmt.width - len;
	new_str = (char *)malloc(sizeof(char) * (delta + 1));
	new_str[delta] = '\0';
	ft_memset(new_str, (QZERO ? '0' : ' '), delta);
	if (g_fmt.flags[0])
		ft_join_gs(g_s, (SC ? len : ft_strlen(g_s)), new_str, delta);
	else
	{
		ft_join_gs(new_str, delta, g_s, (SC ? len : ft_strlen(g_s)));
		if (g_fmt.flags[3] && !g_fmt.flags[4] &&
			g_fmt.prec > 0 && g_fmt.width > g_fmt.prec)
		{
			delta = g_fmt.width - g_fmt.prec;
			if (g_fmt.prec < len)
				delta -= len - g_fmt.prec;
			ft_memset(g_s, ' ', delta);
		}
	}
	free(new_str);
}
