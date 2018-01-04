#include "../includes/simple_p.h"

int		string_width(const char *s, t_flag *f, int len)
{
	int pc;

	pc = 0;
	len = f->preci < len ? f->preci : len;
	while (f->width > len)
	{
		write(1, " ", 1);
		--f->width;
		++pc;
	}
	write(1, s, len);
	pc += len;
	return (pc);
}

int		string_printer(const char *s, t_flag *f, int len)
{
	int pc;

	pc = 0;
	if (f->lag_minus)
	{
		len = f->preci < len ? f->preci : len;
		write(1, s, len);
		pc += len;
		while (f->width > pc)
		{
			write(1, " ", 1);
			++pc;
		}
	}
	else
		pc += string_width(s, f, len);
	return (pc);
}

int		print_width(const char *s, t_flag *f, int len)
{
	int pc;

	pc = 0;
	while (f->width && f->width > len)
	{
		write(1, " ", 1);
		--f->width;
		++pc;
	}
	write(1, s, len);
	pc += len;
	return (pc);
}

int		printer(const char *s, t_flag *f, int len)
{
	int pc;

	pc = 0;
	if (f->lag_dot && (f->conv == 's'))
		pc += string_printer(s, f, len);
	else
	{
		if (f->lag_minus)
		{
			write(1, s, len);
			pc += len;
			while (f->width > pc)
			{
				write(1, " ", 1);
				++pc;
			}
		}
		else
			pc += print_width(s, f, len);
	}
	return (pc);
}

int		percent_handler(t_flag *f)
{
	int		i;
	char	buf[2 + f->width];

	i = 2 + f->width;
	buf[--i] = 0;
	buf[--i] = '%';
	f->preci = 0;
	return (printer(&buf[i], f, ft_strlen(&buf[i])));
}