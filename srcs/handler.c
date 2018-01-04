#include "../includes/simple_p.h"

int		dec_format(char *buf, int i, t_flag *f, int len)
{
	len = ft_strlen(&buf[i]);
	if (f->sign == -1)
	{
		if (f->preci == len)
			buf[--i] = '-';
		else
			buf[--i] = '-';
    }
	if (f->lag_space)
	{
		if (f->preci == len)
			buf[--i] = ' ';
		else
			buf[--i] = ' ';
	}
	return (i);
}

char	*dec_to_string(char *buf, int i, long long n, t_flag *f)
{
	buf[--i] = 0;
	if (n == 0)
	{
		if (f->lag_dot == 1 && f->preci == 0)
			return (&buf[i]);
		buf[--i] = '0';
		if (f->lag_space)
			buf[--i] = '0';
	}
	f->sign = n < 0 ? -1 : 1;
	if (n > 0)
		n = -n;
	while (n)
	{
		buf[--i] = -(n % 10) + '0';
		n /= 10;
	}
	i = dec_format(buf, i, f, 0);
	return (&buf[i]);
}

int     dec_handler(va_list args, t_flag *f)
{
	long long	n;
	char		*s;
	char		buf[32 + f->width + f->preci];

    n = va_arg(args, long long);
	s = dec_to_string(buf, 32 + f->width + f->preci, n, f);
	return (printer(s, f, ft_strlen(s)));
}

int		char_handler(va_list args, t_flag *f)
{
	char	scr[2];

	scr[0] = (char)va_arg(args, int);
	scr[1] = 0;
	return (printer(scr, f, 1));
}

int		string_handler(va_list args, t_flag *f)
{
	char	*s;

    s = (char *)va_arg(args, char *);
    if (s != NULL)
        return (printer(s, f, ft_strlen(s)));
	f->width += f->lag_space == 1 ? 1 : 0;
	return (printer("(null)", f, 6));
}