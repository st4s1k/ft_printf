/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgirlea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:16:34 by sgirlea           #+#    #+#             */
/*   Updated: 2017/02/06 14:16:37 by sgirlea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_countchar(unsigned int nbr, size_t base)
{
	int i;

	i = 0;
	if (nbr == 0)
		return (1);
	else
	{
		while (nbr != 0)
		{
			nbr /= base;
			i++;
		}
		return (i);
	}
}

char			*ft_utoa(unsigned int nbr, char const *base_chr)
{
	char			*buf;
	int				i;
	size_t			base;

	base = ft_strlen(base_chr);
	if ((buf = ft_strnew(ft_countchar(nbr, base))) == NULL)
		return (NULL);
	i = 0;
	if (nbr == 0)
		buf[i++] = '0';
	while (nbr > 0)
	{
		buf[i++] = base_chr[nbr % base];
		nbr /= base;
	}
	buf[i] = '\0';
	ft_strrev(buf);
	return (buf);
}
