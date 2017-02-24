/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgirlea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:16:32 by sgirlea           #+#    #+#             */
/*   Updated: 2017/02/06 14:17:31 by sgirlea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *cur;

	if (!dst || !src)
		return (NULL);
	cur = dst;
	while (*src != '\0' && len > 0)
	{
		*cur = *src;
		++cur;
		++src;
		len--;
	}
	*cur = '\0';
	return (dst);
}
