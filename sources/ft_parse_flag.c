#include "ft_printf.h"

void ft_parse_flag(t_printf *item, char **line)
{
	while (**line == '-' || **line == '0')
	{
		if (**line == '-' && !item->minus)
		{
			item->minus = 1;
			item->zero = 0;
		}
		else if (**line == '0' && !item->minus && !item->zero)
			item->zero = 1;
		(*line)++;
	}
}