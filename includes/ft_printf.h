#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

int	ft_printf(const char *format, ...);

int	ft_problem(va_list ap, char *format);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_putchar_hexadecimal(unsigned int num, int flag);
int	ft_putchar_hexadecimal_p(unsigned long num);
#endif