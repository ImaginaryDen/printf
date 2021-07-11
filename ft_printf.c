#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	size_t	ret;
	va_list	ap;
	char	*str;
	char	*temp;

	va_start(ap, format);
	ret = 0;
	str = (char *)format;
	while (*str)
	{
		temp = ft_strchr(str, '%');
		if (temp)
		{
			ret += temp - str;
			write(1, str, temp - str);
			str = temp + 2;
			ret += ft_problem(ap, str - 1);
			continue ;
		}
		ret += ft_putstr_fd(str, 1);
		break ;
	}
	va_end(ap);
	return (ret);
}
