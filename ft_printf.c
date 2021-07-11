#include "ft_printf.h"

// int	ft_printf(const char *format, ...)
// {
// 	int		i;
// 	size_t	ret;
// 	va_list	ap;
// 	char	*str;

// 	va_start(ap, format);
// 	i = 0;
// 	ret = 0;
// 	str = (char *)format;
// 	while (*str)
// 	{
// 		if (*str == '%')
// 		{
// 			ret += ft_problem(ap, &str);
// 		}
// 		else
// 			ret += write(1, str, 1);
// 		str++;
// 	}
// 	va_end(ap);
// 	return (ret);
// }

int	ft_printf(const char *format, ...)
{
	int		i;
	size_t	ret;
	va_list	ap;
	char	*str;
	char	*temp;

	va_start(ap, format);
	i = 0;
	ret = 0;
	str = (char *)format;
	while (*str)
	{
		temp = ft_strchr(str, '%');
		if(temp)
		{
			ret += temp - str;
			write(1, str, temp - str);
			str = temp;
			ret += ft_problem(ap, &str);
			str++;
			continue;
		}
		ret += ft_putstr_fd(str, 1);
		break;
	}
	va_end(ap);
	return (ret);
}