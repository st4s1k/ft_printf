#include "libft.h"

size_t	ft_wstrlen(const wchar_t *str)
{
	const wchar_t *origstr;

	origstr = str;
	while (*str != '\0')
		str++;
	return (str - origstr);
}