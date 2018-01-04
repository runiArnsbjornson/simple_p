#include "../includes/simple_p.h"

void    get_flag(const char *fmt, t_flag *f)
{
	int i;

	i = 1;
    if (*fmt == ' ')
		f->lag_space = 1;
	if (*fmt == '-')
		f->lag_minus = 1;
    if (*fmt == '.')
	{
		f->lag_dot = 1;
		f->preci = 0;
		while (ft_isdigit(fmt[i]) == 1)
		{
			f->preci *= 10;
			f->preci += fmt[i] - '0';
			i++;
		}
		f->preci = f->preci < 0 ? 0 : f->preci;
	}
}

int		width_digit(const char *fmt, t_flag *f, int i, int flag)
{
	if (ft_isdigit(fmt[i]) == 1 && fmt[i - 1] != '.')
	{
		flag = 0;
		f->width = 0;
		while (ft_isdigit(fmt[i]) == 1)
		{
			f->width *= 10;
			f->width += fmt[i] - '0';
			i++;
		}
	}
	return (i);
}

void     precision(const char *fmt, t_flag *f, va_list args, int i)
{
	int flag;

	flag = 0;
	while (fmt[i] && fmt != 0 && i <= f->len)
	{
		i = width_digit(fmt, f, i, flag);
		if (fmt[i] == '*' && fmt[i - 1] != '.')
		{
			flag = 1;
			f->width = va_arg(args, int);
			f->lag_minus = f->width < 0 ? 1 : f->lag_minus;
			f->width = f->width < 0 ? -f->width : f->width;
		}
		if (fmt[i] == '.')
			break ;
		i++;
	}
}

int		check(const char c, const char *checker)
{
	int	i;
	int len;
	
	i = -1;
	len = (int)ft_strlen(checker);
	while (i++ <= len)
	{
		if (c == checker[i])
		{
			return (checker[i]);
		}
	}
	return (0);
}

void	search(const char *fmt, t_flag* f, va_list args, int i)
{
	while (fmt[i] && fmt && check(fmt[i], ".- 0123456789") != 0)
	{
		f->len++;
		i++;
	}
	while (fmt[f->i])
		++f->i;
	f->conv = check(fmt[i], "%idcs");
	precision(fmt, f, args, 1);
	i = 1;
	while (fmt[i] && fmt && i <= f->len)
	{
		get_flag(&fmt[i], f);
		i++;
	}
}
