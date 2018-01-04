#include "../includes/simple_p.h"

void	zero_struct(t_flag *f)
{
	f->len = 0;
	f->lag_dot = 0;
	f->lag_minus = 0;
	f->lag_space = 0;
	f->width = 0;
	f->preci = 0;
	f->sign = 0;
	f->i = 1;
	f->conv = 0;
}

int     handlers(va_list args, t_flag *f, int pc)
{
	if (f->conv == 'd' || f->conv == 'i')
		pc += dec_handler(args, f);
	else if (f->conv == 'c')
		pc += char_handler(args, f);
	else if (f->conv == 's')
		pc += string_handler(args, f);
	else if (f->conv == '%')
		pc += percent_handler(f);
	return (pc);
}

int		no_conv(char fmt, t_flag *f, int pc)
{
	int		j;
	char	buf[2 + f->width];

	j = 2 + f->width;
	buf[--j] = 0;
	if (f->conv == 0)
	{
		buf[--j] = fmt;
		pc += printer(&buf[j], f, ft_strlen(&buf[j]));
		zero_struct(f);
	}
	else
	{
		write(1, &fmt, 1);
		++pc;
	}
	return (pc);
}

int     parse(const char *fmt, t_flag *f, va_list args)
{
	int pc;
	int i;

	pc = 0;
	i = 0;
	while (fmt[i] && fmt)
	{
		if (fmt[i] == '%')
		{
			zero_struct(f);
			search(&fmt[i], f, args, 1);
			if (f->conv == 0 && f->i == 1)
				return (pc);
			f->len = f->conv == 0 ? f->len - 1 : f->len;
			pc += handlers(args, f, 0);
			i += f->len + 1;
		}
		else
			pc += no_conv(fmt[i], f, 0);
		i++;
	}
	return (pc);
}

int     simple_p(const char *fmt, ...)
{
	va_list args;
	t_flag  f;
	int     char_written;

	char_written = 0;
	zero_struct(&f);
	va_start(args, fmt);
	char_written += parse(fmt, &f, args);
	va_end(args);
	return (char_written);
}
