#include "ft_printf.h"

int ft_problem(va_list ap, char **format)
{
	char *str;

	(*format)++;
	if (**format == 'c')
		write(1, va_arg(ap, int *), 1);
	else if (**format == 's')
	{
		str = va_arg(ap, char *);
		write (1, str, ft_strlen(str));
	}
	else if (**format == 'd' || **format == 'i')
		ft_putnbr_fd(va_arg(ap, int), 1);
	else if (**format == 'u')
		ft_putnbr_unsigned(va_arg(ap, unsigned int));
	//write(1,"\nproblem\n",9);
	return (2);
}