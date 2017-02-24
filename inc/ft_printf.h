/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgirlea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:20:05 by sgirlea           #+#    #+#             */
/*   Updated: 2017/01/31 18:21:36 by sgirlea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <inttypes.h>
# include "libft.h"

# define RESET "\033[0m"
# define BOLD_ON "\x1B[1m"
# define ITALIC_ON "\x1B[3m"
# define UNDERLINE_ON "\x1B[4m"
# define INVERSE_ON "\x1B[7m"
# define STRIKETHROUGH_ON "\x1B[9m"
# define BOLD_OFF "\x1B[22m"
# define ITALIC_OFF "\x1B[23m"
# define UNDERLINE_OFF "\x1B[24m"
# define INVERSE_OFF "\x1B[27m"
# define STRIKETHROUGH_OFF "\x1B[29m"
# define FG_BLACK "\x1B[30m"
# define FG_RED "\x1B[31m"
# define FG_GREEN "\x1B[32m"
# define FG_YELLOW "\x1B[33m"
# define FG_BLUE "\x1B[34m"
# define FG_MAGNETA "\x1B[35m"
# define FG_CYAN "\x1B[36m"
# define FG_WHITE "\x1B[37m"
# define FG_DEFAULT "\x1B[39m"
# define BG_BLACK "\x1B[40m"
# define BG_RED "\x1B[41m"
# define BG_GREEN "\x1B[42m"
# define BG_YELLOW "\x1B[43m"
# define BG_BLUE "\x1B[44m"
# define BG_MAGNETA "\x1B[45m"
# define BG_CYAN "\x1B[46m"
# define BG_WHITE "\x1B[47m"
# define BG_DEFAULT "\x1B[49m"
# define NEG_DGT (*g_cur == '-' && ft_isdigit(*(g_cur + 1)))
# define POS_DGT (*g_cur == '+' && ft_isdigit(*(g_cur + 1)))
# define IS_NBR (ft_isdigit(*g_cur) || NEG_DGT || POS_DGT)

void		ft_skip_nbr(void);
void		ft_join_gs(const char *s1, int l1, const char *s2, int l2);
void		ft_copy(char *s1, const char *s2, int start, int end);
char		ft_find_fspec(int *pret);
char		ft_is_flag(void);
char		ft_is_len(void);
char		ft_is_prec(va_list *parg);
char		ft_is_width(va_list *parg);
char		ft_get_format(va_list *parg);
void		ft_process_width(int len);
void		ft_dioux_prec(void);
intmax_t	ft_uoxlen(va_list *parg);
int			ft_fou(va_list *parg);
int			ft_fint(va_list *parg);
int			ft_fhex(va_list *parg);
int			ft_fchar(va_list *parg);
int			ft_fstr(va_list *parg);
int			ft_fwchar(va_list *parg);
int			ft_fwstr(va_list *parg);
int			ft_format(va_list *parg);
int			ft_printf(char *format, ...);
struct		s_fmt
{
	char	flags[5];
	int		width;
	int		prec;
	int		len[5];
}			g_fmt;
intmax_t	g_n;
int			g_size;
short		g_stop;
char		g_free;
char		*g_cur;
char		*g_s;
char		g_0x;

#endif
