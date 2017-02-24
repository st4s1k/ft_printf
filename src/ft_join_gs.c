/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_gs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgirlea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 17:35:25 by sgirlea           #+#    #+#             */
/*   Updated: 2017/02/21 17:35:27 by sgirlea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_join_gs(const char *s1, int l1, const char *s2, int l2)
{
	char	*temp;
	int		len[2];

	len[0] = l1;
	len[1] = l2;
	temp = (char *)malloc(sizeof(char) * (len[0] + len[1] + 1));
	temp[len[0] + len[1]] = '\0';
	ft_copy(temp, s1, 0, len[0]);
	ft_copy(temp, s2, len[0], len[1]);
	if (g_free)
		free(g_s);
	g_s = (char *)malloc(sizeof(char) * (len[0] + len[1] + 1));
	g_s[len[0] + len[1]] = '\0';
	ft_copy(g_s, temp, 0, len[0] + len[1]);
	free(temp);
}
