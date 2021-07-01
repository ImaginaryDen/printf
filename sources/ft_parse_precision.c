#include "ft_printf.h"

void	ft_parse_precision(t_printf *item, char **format, va_list *ap)
{
	if (**format == '.')
	{
		(*format)++;
		if (**format == '*')
		{
			item->precision = va_arg(*ap, int);
			(*format_str)++;
			return ;
		}
		while (ft_isdigit(**format))
		{
			
		}
	}
}