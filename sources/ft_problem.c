#include "ft_printf.h"

int ft_problem(va_list ap, char **format)
{
	char *str;
	int ret;

	ret = 0;
	(*format)++;
	if (**format == 'c')
		ret = write(1, va_arg(ap, int *), 1);
	else if (**format == 's')
	{
		str = va_arg(ap, char *);
		ret = ft_strlen(str);
		write (1, str, ret);
	}
	else if (**format == 'd' || **format == 'i')
		ret = ft_putnbr_fd(va_arg(ap, int), 1);
	else if (**format == 'u')
		ret = ft_putnbr_unsigned(va_arg(ap, unsigned int));
	else if(**format == 'x' || **format == 'X')
		ret = ft_putchar_hexadecimal(va_arg(ap, int), **format == 'X');
	else if(**format == 'p')
	{
		ret = ft_putstr_fd("0x",1);
		ret += ft_putchar_hexadecimal_p(va_arg(ap, unsigned long), 0);
	}else if(**format == '%')
		ret = write(1,*format, 1);
	return (ret);
}