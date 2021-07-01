#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	int i;
	size_t ret;
	va_list ap;

	va_start(ap, format);
	i = 0;
	ret = 0;
	while (format[i])
	{
		if (format[i] == '%')
			ret += ft_problem();
		else
			ret += write(1, format[i], 1);
		i++;
	}
	va_end(ap);
	return (ret);
}