/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgirlea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:20:05 by sgirlea           #+#    #+#             */
/*   Updated: 2017/02/12 19:08:09 by sgirlea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define UDIGITS "0123456789ABCDEF"
#define LDIGITS "0123456789abcdef"

char	*ft_itoa_base(uintmax_t num, int8_t base, int8_t ucase)
{
	char	*digits;
	char	buffer[100];
	char	*ptr;
	size_t	len;

	len = 0;
	if (ucase)
		digits = UDIGITS;
	else
		digits = LDIGITS;
	while (TRUE)
	{
		buffer[len] = digits[num % base];
		buffer[len + 1] = '\0';
		++len;
		num /= base;
		if (!num)
			break ;
	}
	ptr = ft_strdup(buffer);
	ft_strrev(ptr);
	return (ptr);
}
