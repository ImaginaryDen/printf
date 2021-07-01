#include "ft_printf.h"

void init_item(t_printf *item)
{
	item->precision = 0;
	item->minus = 0;
	item->zero = 0;
	item->width = 0;
}

t_printf ft_parse(char **format, va_list *ap)
{
	t_printf item;

	init_item(&item);
	ft_parse_flag(&item, format);
	ft_parse_width(&item, format, ap);
	return (item);
}