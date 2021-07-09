#include "ft_printf.h"
#include "libft.h"

static long	pow(int num, int pow_n)
{
	long	result;

	result = 1;
	while (pow_n)
	{
		result *= num;
		pow_n--;
	}
	return (result);
}

int	ft_abs(int i)
{
	if (i >= 0)
		return (i);
	return (-i);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int				size;
	int				ret;
	unsigned int	copy_n;

	size = 0;
	copy_n = n;
	while (copy_n)
	{
		size++;
		copy_n /= 10;
	}
	ret = size;
	if (!n)
		ret += write(1, "0", 1);
	while (size)
	{
		ft_putchar_fd(n / pow(10, size - 1) + '0', 1);
		n %= pow(10, size - 1);
		size--;
	}
	return (ret);
}

int	ft_putchar_hexadecimal(unsigned int num, int flag)
{
	char			*base;
	int				size;
	int				ret;
	unsigned long	copy_n;

	base = "0123456789abcdef";
	if (flag)
		base = "0123456789ABCDEF";
	size = 0;
	copy_n = num;
	while (copy_n)
	{
		size++;
		copy_n = copy_n / 16;
	}
	ret = size;
	if (!num)
		ret += write(1, "0", 1);
	while (size)
	{
		ft_putchar_fd(base[num / pow(16, size - 1)], 1);
		num %= pow(16, size - 1);
		size--;
	}
	return (ret);
}

int	ft_putchar_hexadecimal_p(unsigned long num, int flag)
{
	char			*base;
	int				size;
	int				ret;
	unsigned long	copy_n;

	base = "0123456789abcdef";
	if (flag)
		base = "0123456789ABCDEF";
	size = 0;
	copy_n = num;
	while (copy_n)
	{
		size++;
		copy_n = copy_n / 16;
	}
	ret = size;
	if (!num)
		ret += write(1, "0", 1);
	while (size)
	{
		ft_putchar_fd(base[num / pow(16, size - 1)], 1);
		num %= pow(16, size - 1);
		size--;
	}
	return (ret);
}
