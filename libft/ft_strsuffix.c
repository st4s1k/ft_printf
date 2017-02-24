/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsuffix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgirlea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:16:33 by sgirlea           #+#    #+#             */
/*   Updated: 2017/02/06 14:17:32 by sgirlea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strsuffix(const char *str, const char *suffix)
{
	const char	*str_iter;
	const char	*suffix_iter;

	str_iter = str;
	suffix_iter = suffix;
	while (*str_iter != '\0')
		str_iter++;
	while (*suffix_iter != '\0')
		suffix_iter++;
	while (suffix_iter >= suffix && str_iter >= str &&
			*str_iter == *suffix_iter)
	{
		str_iter--;
		suffix_iter--;
	}
	return (suffix_iter < suffix);
}
