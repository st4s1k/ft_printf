/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgirlea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 21:15:51 by sgirlea           #+#    #+#             */
/*   Updated: 2017/02/20 21:15:54 by sgirlea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*result;
	size_t	len;

	len = ft_strlen(s);
	if (n < len)
		len = n;
	result = (char *)malloc(len + 1);
	if (!result)
		return (0);
	result[len] = '\0';
	return ((char *)ft_memcpy(result, s, len));
}
