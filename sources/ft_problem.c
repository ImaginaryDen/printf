#include "ft_printf.h"

int	put_str(va_list ap)
{
	int		ret;
	char	*str;

	str = va_arg(ap, char *);
	if (!str)
	{
		write (1, "(null)", 6);
		return (6);
	}
	ret = ft_strlen(str);
	write (1, str, ret);
	return (ret);
}

int	ft_problem(va_list ap, char *format)
{
	int		ret;
	char	ch;

	ret = 0;
	if (*format == 'c')
	{
		ch = va_arg(ap, int);
		ret = write(1, &ch, 1);
	}
	else if (*format == 's')
		return (put_str(ap));
	else if (*format == 'd' || *format == 'i')
		ret = ft_putnbr_fd(va_arg(ap, int), 1);
	else if (*format == 'u')
		ret = ft_putnbr_unsigned(va_arg(ap, unsigned int));
	else if (*format == 'x' || *format == 'X')
		ret = ft_putchar_hexadecimal(va_arg(ap, int), *format == 'X');
	else if (*format == 'p')
	{
		ret = ft_putstr_fd("0x", 1);
		ret += ft_putchar_hexadecimal_p(va_arg(ap, unsigned long));
	}
	else if (*format == '%')
		ret = write(1, format, 1);
	return (ret);
}
