#ifndef SIMPLE_P_H
# define SIMPLE_P_H

# include <stdio.h>
# include <locale.h>
# include <wchar.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include "libft.h"

typedef struct		s_flag
{
	int				len;
	int				lag_dot;
	int				lag_minus;
	int				lag_space;
	int				width;
	int				preci;
    int             sign;
	int				i;
	char			conv;
}					t_flag;

void	zero_struct(t_flag *f);
int     handlers(va_list args, t_flag *f, int pc);
int		no_conv(char fmt, t_flag *f, int pc);
int     parse(const char *fmt, t_flag *f, va_list args);
int     simple_p(const char *fmt, ...);
int		string_width(const char *s, t_flag *f, int len);
int		string_printer(const char *s, t_flag *f, int len);
int		print_width(const char *s, t_flag *f, int len);
int		printer(const char *s, t_flag *f, int len);
int		percent_handler(t_flag *f);
int		dec_format(char *buf, int i, t_flag *f, int len);
char	*dec_to_string(char *buf, int i, long long n, t_flag *f);
int     dec_handler(va_list args, t_flag *f);
int		char_handler(va_list args, t_flag *f);
int		string_handler(va_list args, t_flag *f);
void    get_flag(const char *fmt, t_flag *f);
int		width_digit(const char *fmt, t_flag *f, int i, int flag);
void    precision(const char *fmt, t_flag *f, va_list args, int i);
int		check(const char c, const char *checker);
void	search(const char *fmt, t_flag* f, va_list args, int i);


#endif