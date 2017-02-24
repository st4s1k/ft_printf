/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dioux_prec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgirlea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 19:29:26 by sgirlea           #+#    #+#             */
/*   Updated: 2017/02/18 19:29:28 by sgirlea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_dioux_prec(void)
{
	char	*new_str;
	uint	delta;

	delta = g_fmt.prec - (int)ft_strlen(g_s);
	new_str = (char *)malloc(sizeof(char) * (delta + 1));
	new_str[delta] = '\0';
	ft_memset(new_str, '0', delta);
	ft_join_gs(new_str, delta, g_s, (int)ft_strlen(g_s));
	free(new_str);
}
