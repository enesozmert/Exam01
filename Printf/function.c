// #include "header.h"

// size_t ft_strlen(const char *str)
// {
// 	size_t i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }

// int    ft_numbase(long num, char *base)
// {
// 	int len;
// 	int base_len;

// 	base_len = (int)ft_strlen(base);
//     if (num >= base_len)
//         ft_numbase((num / base_len), base);
//     len += write(1, &base[num % base_len], 1);
// 	return (len);
// }

// int ft_print_s(va_list arg)
// {
// 	int i;
// 	char *s;

// 	i = 0;
// 	s = va_arg(arg, char *);
// 	while (s[i])
// 	{
// 		write(1, &s[i], 1);
// 		i++;
// 	}
// 	return (i);
// }

// int ft_print_d(va_list arg)
// {
// 	int len;
// 	long num;
// 	char *base;

// 	len = 0;
// 	base = "0123456789";
// 	num = va_arg(arg, long);
// 	len += ft_numbase(num, base);
// 	return (len);
// }

// int ft_print_x(va_list arg)
// {
// 	int len;
// 	long num;
// 	char *base;

// 	len = 0;
// 	base = "0123456789abcdef";
// 	num = va_arg(arg, long);
// 	len += ft_numbase(num, base);
// 	return (len);
// }

// int ft_print_ux(va_list arg)
// {
// 	int len;
// 	long num;
// 	char *base;

// 	len = 0;
// 	base = "0123456789abcdef";
// 	num = va_arg(arg, long);
// 	len += ft_numbase(num, base);
// 	return (len);
// }
