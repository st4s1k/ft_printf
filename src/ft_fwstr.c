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

static void	ft_wcopy(wchar_t *s1, const wchar_t *s2, wint_t start, wint_t end)
{
	wint_t	i;

	i = 0;
	while (i < end)
	{
		s1[start + i] = s2[i];
		++i;
	}
}

static void	ft_wstrprec(wchar_t **pws)
{
	wchar_t	*temp;
	wint_t	len;

	len = (int)ft_wstrlen(*pws);
	temp = (wchar_t *)malloc(sizeof(wchar_t) * (len + 1));
	temp[len] = '\0';
	ft_wcopy(temp, *pws, 0, len);
	*pws = (wchar_t *)malloc(sizeof(wchar_t) * (g_fmt.prec + 1));
	(*pws)[g_fmt.prec] = '\0';
	ft_wcopy(*pws, temp, 0, g_fmt.prec);
	free(temp);
}

int			ft_fwstr(va_list *parg)
{
	wchar_t		*ws;

	if ((ws = va_arg(*parg, wchar_t *)))
	{
		g_free = 0;
		if (g_fmt.prec > -1 && g_fmt.prec < (int)ft_wstrlen(ws))
			ft_wstrprec(&ws);
		if (!g_stop)
			ft_putwstr(ws);
		return ((int)ft_wstrlen(ws));
	}
	if (!g_stop)
		ft_putstr("(null)");
	return (6);
}
