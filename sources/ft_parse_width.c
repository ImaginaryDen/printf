#include "ft_printf.h"

void ft_parse_width(t_printf *item, char **format, va_list *ap)
{
	if (**format == '*')
	{
		item->width = va_arg(*ap, int);
		(*format)++;
		if (item < 0)
		{
			item->minus = 1;
			item->zero = 0;
			item->width *= -1;
		}
	}
	while (ft_isdigit(**format))
	{
		item->width *= 10;
		item->width += **format - '0';
		(*format)++;
	}
}