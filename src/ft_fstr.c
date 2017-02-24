/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgirlea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 21:16:30 by sgirlea           #+#    #+#             */
/*   Updated: 2017/02/20 21:16:32 by sgirlea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_strprec(void)
{
	char	*temp;
	int		len;

	len = (int)ft_strlen(g_s);
	temp = (char *)malloc(sizeof(char) * (len + 1));
	temp[len] = '\0';
	ft_copy(temp, g_s, 0, len);
	g_s = (char *)malloc(sizeof(char) * (g_fmt.prec + 1));
	g_s[g_fmt.prec] = '\0';
	ft_copy(g_s, temp, 0, g_fmt.prec);
	free(temp);
}

int			ft_fstr(va_list *parg)
{
	if ((g_s = va_arg(*parg, char *)))
	{
		g_free = 0;
		if (g_fmt.prec > -1 && g_fmt.prec < (int)ft_strlen(g_s))
			ft_strprec();
		if (g_fmt.width > (int)ft_strlen(g_s))
		{
			ft_process_width((int)ft_strlen(g_s));
			if (!g_stop)
				ft_putstr(g_s);
			free(g_s);
		}
		else if (!g_stop)
			ft_putstr(g_s);
		return ((int)ft_strlen(g_s));
	}
	if (!g_stop)
		ft_putstr("(null)");
	return (6);
}
