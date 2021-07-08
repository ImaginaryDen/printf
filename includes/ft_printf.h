#ifndef FT_PRINTF_H
#define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct	s_print                       
{
	int	precision;
	int zero;
	int minus;
	int width;
} t_printf;

int ft_printf(const char *format, ...);

t_printf ft_parse(char **format, va_list *ap);
void	ft_parse_flag(t_printf *item, char **line);
void	ft_parse_width(t_printf *item, char **format, va_list *ap);
void	ft_parse_precision(t_printf *item, char **format_str, va_list *ap);
int		ft_problem(va_list ap, char **format);
void	ft_putnbr_unsigned(unsigned int n);

#endif