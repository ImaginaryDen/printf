#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	int i;
	size_t ret;
	va_list ap;
	char *str;

	va_start(ap, format);
	i = 0;
	ret = 0;
	str = (char *)format; 
	while (*str)
	{
		if (*str == '%')
		{
			ret += ft_problem(ap, &str);
		}
		else
			ret += write(1, str, 1);
		str++;
	}
	va_end(ap);
	return (ret);
}