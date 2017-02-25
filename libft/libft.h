/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgirlea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:15:22 by sgirlea           #+#    #+#             */
/*   Updated: 2017/02/06 14:15:48 by sgirlea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <sys/types.h>
# include <wchar.h>
# include <inttypes.h>
# define FT_MIN(x, y) (x) < (y) ? (x) : (y)
# define FT_MAX(x, y) (x) > (y) ? (x) : (y)
# define FALSE 0
# define TRUE 1

typedef int8_t		t_bool;

void				*ft_memset(void *dst, int data, size_t len);
void				ft_bzero(void *dst, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t len);
void				*ft_memccpy(void *dst, const void *src, int c, size_t len);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *src, int c, size_t len);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s1);
size_t				ft_wstrlen(const wchar_t *str);
size_t				ft_nstrlen(const char *s1, size_t maxlen);
char				*ft_strdup(const char *s1);
char				*ft_strndup(const char *s, size_t n);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t len);
size_t				ft_strlcat(char *dst, const char *src, size_t len);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t len);
void				ft_strrev(char *s);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t len);
int					ft_atoi(const char *str);
t_bool				ft_isalpha(int chr);
t_bool				ft_isdigit(int chr);
t_bool				ft_isalnum(int chr);
t_bool				ft_isascii(int chr);
t_bool				ft_isprint(int chr);
t_bool				ft_isspace(int chr);
int					ft_toupper(int chr);
int					ft_tolower(int chr);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *s));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t len);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_multistrjoin(int c, ...);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				**ft_strsplitwith(char *s, char *seps, size_t *count);
int					ft_strprefix(const char *str, const char *prefix);
int					ft_strsuffix(const char *str, const char *suffix);
char				*ft_itoa(int n);
char				*ft_itoa_base(uintmax_t num, int8_t base, int8_t ucase);
char				*ft_utoa(unsigned int n, char const *base);
void				ft_putchar(char c);
void				ft_putwchar(wchar_t c);
int					ft_wcharsize(wchar_t chr);
void				ft_putstr(char const *s);
void				ft_putnstr(char const *s, size_t strlen);
void				ft_putwstr(wchar_t const *s);
void				ft_putnwstr(wchar_t const *s, size_t strlen);
void				ft_putendl(char const *s);
void				ft_putnbr(intmax_t n);
void				ft_putnbrbase(uintmax_t n, char *base);
void				ft_putchar_fd(char c, int fd);
void				ft_putwchar_fd(wchar_t c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putnstr_fd(char const *s, size_t strlen, int fd);
void				ft_putwstr_fd(wchar_t const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(intmax_t n, int fd);
void				ft_putnbrbase_fd(uintmax_t n, char *base, int fd);
int					ft_max(int x, int y);
int					ft_min(int x, int y);
typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstlink(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
#endif
