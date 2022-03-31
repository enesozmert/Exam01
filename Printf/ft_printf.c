#include <unistd.h>
#include "stdarg.h"
#include <stdio.h>
#include <string.h>

typedef struct s_convert
{
	char	*name;
	int		(*f)(va_list);
}	t_operators;

int ft_strlen(const char *str)
{
	int i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int ft_baselen(int value)
{
	int i;

	i = 0;
	if (value == 0)
		return (1);
	if (value < 0)
		i++;
	while (value != 0)
	{
		i++;
		value /= 10;
	}
	return (i);
}

int ft_baselenlong(long value)
{
	int i;

	i = 0;
	if (value == 0)
		return (1);
	if (value < 0)
		i++;
	while (value != 0)
	{
		i++;
		value /= 16;
	}
	return (i);
}

void ft_basenum(long value, char *base)
{
	int len;

	if (value < 0)
		value *= -1;
	len = ft_strlen(base);
	if (value >= len)
		ft_basenum(value / len, base);
	write(1, &base[value % len], 1); 
}

int ft_print_s(va_list values)
{
	int		i;
	int		len;
	char	*s = va_arg(values, char *);;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	if (s != 0)
	{
		while (s[i])
		{
			write(1, &s[i], 1);
			i++;
		}
	}
	len = ft_strlen(s);
	return (len);
}

int ft_print_d(va_list values)
{
	int len;
	int num;
	char *base;

	base = "0123456789";
	num = va_arg(values, int);
	if (num == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (num < 0)
		write(1, "-", 1);
	len = ft_baselen(num);
	ft_basenum(num, base);
	return (len);
}

int ft_print_x(va_list values)
{
	int len;
	long num;
	char *base;

	base = "0123456789abcdef";
	num = va_arg(values, long);
	if (num < 0)
		write(1, "-", 1);
	len = ft_baselenlong(num);
	ft_basenum(num, base);
	return (len);
}

int	parser(const char *text, t_operators _operators[], va_list values)
{
	int	i;
	int	j;
	int	counter_values;

	i = 0;
	counter_values = 0;
	while (i < ft_strlen(text))
	{
		j = 0;
		if (text[i] == '%')
		{
			while (_operators[j].name != NULL)
			{
				if (_operators[j].name[0] == text[i + 1])
					counter_values += _operators[j].f(values);
				j++;
			}
			i++;
		}
		else
		{
			write(1, &text[i], 1);
			counter_values++;
		}
		i++;
	}
	return (counter_values);
}

int ft_printf(const char *str, ...)
{
	int counter_values;
	va_list values;
	t_operators _operators[4];
	_operators[0] = (t_operators){"s", ft_print_s};
	_operators[1] = (t_operators){"d", ft_print_d};
	_operators[2] = (t_operators){"x", ft_print_x};
	_operators[3] = (t_operators){NULL, NULL};
	va_start(values, str);
	parser(str, _operators, values);
	va_end(values);

	return (counter_values);
}

int main()
{
	//char b[] = "enes";
	ft_printf("%d %s",1111,"enessss");
}