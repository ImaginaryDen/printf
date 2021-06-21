#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	int i;

	i = 0;
	while (format[i])
		write(1, &format[i++], 1);
	return (1);
}