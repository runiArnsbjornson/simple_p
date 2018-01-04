/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 18:32:18 by jdebladi          #+#    #+#             */
/*   Updated: 2017/09/14 10:15:33 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <float.h>
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>

# define BUFF_SIZE 32
# define TCLN "\e[1;1H\e[2J"
# define CLN "\033[K"
# define BOL "\033[01m"
# define FAI "\033[02m"
# define ITA "\033[03m"
# define UDL "\033[04m"
# define BLK "\033[30m"
# define RED "\033[31m"
# define GRN "\033[32m"
# define YEL "\033[33m"
# define BLU "\033[34m"
# define MAG "\033[35m"
# define CYA "\033[36m"
# define WHT "\033[37m"
# define BBLK "\033[40m"
# define BRED "\033[41m"
# define BGRN "\033[42m"
# define BYEL "\033[43m"
# define BBLU "\033[44m"
# define BMAG "\033[45m"
# define BCYN "\033[46m"
# define BWHT "\033[47m"
# define OVR "\033[53m"
# define RES "\033[00m"

# define FT_MIN(a, b)	(a < b ? a : b)
# define FT_MAX(a, b)	(a > b ? b : a)
# define FT_ABS(a)		(a < 0 ? -a : a)
# define FT_TODIGIT(c)	(c - '0')

typedef struct		s_q
{
	long			n;
	struct s_q		*next;
}					t_q;

typedef struct		s_queue
{
	t_q		*first;
}					t_queue;

typedef struct		s_lst
{
	long			fd;
	char			*temp;
	char			*cara;
	struct s_lst	*next;
	struct s_lst	*start;
}					t_lst;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** convert func
*/
long long			ft_atoll(const char *ptr);
long				ft_atol(const char *nptr);
int					ft_atoi(const char *str);
char				*ft_ftoa(long double n, int precision);
char				*ft_itoa_base(long long n, int base);
char				*ft_itoa(int n);
int					ft_tolower(int c);
int					ft_toupper(int c);
long				ft_strtol(const char *nptr);
/*
** math func
*/
unsigned long long	ft_pwr(int nb, int power);
long long			ft_lpwr(long long nb, int pwr);
int					ft_sqrt(int n);
/*
** is* func
*/
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isinf(double x);
int					ft_islower(int c);
int					ft_isnan(double x);
int					ft_isprime(unsigned long long nb);
int					ft_isprint(int c);
int					ft_isspace(int c);
int					ft_isupper(int c);
/*
** list func
*/
int					ft_dequeue(t_queue *q);
void				ft_enqueue(t_queue *q, int new);
int					ft_lstlen(t_list **alst);
void				ft_lstfree(t_list **alst);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstaddend(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_putlist(t_list **alst);
/*
** memory func
*/
void				ft_bzero(void *s, size_t n);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
/*
** display func
*/
void				ft_put_error(char *str);
int					ft_printf(const char *format, ...);
void				ft_putchar_fd(int c, int fd);
void				ft_putchar(int c);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr(int n);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putstr(char const *str);
void				ft_puttab_fd(char **tab, int fd);
void				ft_puttab(char **tab);
void				ft_putnbrendl(int n);
void				ft_putnbrendl_fd(int n, int fd);
void				ft_putinttab(int **tab, int col);
/*
** str func
*/
void				ft_occurence(int n, char **argv);
int					ft_bool_strchr(const char *s, int c);
char				*ft_replace(const char *s, const char *o, const char *new);
char				**ft_split(char *str);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strccpy(const char *src, int c);
void				ft_strdel(char **as);
char				*ft_strdup(const char *src);
int					ft_strequ(char const *s1, char const *s2);
int					ft_stris(const char *s, int (*f)(int));
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *str);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnjoin(int nbr, ...);
char				*ft_strnstr(const char *big, const char *littl, size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strrealloc(char *s, size_t size);
char				*ft_strrev(char *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
int					**ft_inttab(int col, int line);
void				ft_inttabdel(int **tab, int size);
char				**ft_tab(size_t col, size_t line);
void				ft_tabdel(char **tab);
/*
** wchar func
*/
int					ft_wcbytesize(wchar_t wc);
int					ft_wcsbytelen(wchar_t *wc);
int					ft_wcscmp(const wchar_t *s1, const wchar_t *s2);
size_t				ft_wcslen(const wchar_t *s);
int					ft_wcsnbytelen(const wchar_t *s, size_t n);
int					ft_wcsnlen(const wchar_t *s, size_t n);
/*
**	read func
*/
int					gnl(const int fd, char **line);
int					ft_gnl(const int fd, char **line);
int					get_next_line(const int fd, char **line);

#endif
