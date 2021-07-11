#include "ft_printf.h"
#include "libft.h"

static long	ft_pow(int num, int pow_n)
{
	long	result;

	if (pow_n <= 0)
		return (0);
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
	size = ft_pow(10, size);
	if (!n)
		return (write(1, "0", 1));
	while (size != 1)
	{
		size /= 10;
		ft_putchar_fd(n / size + '0', 1);
		n %= size;
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
	while (copy_n && ++size)
		copy_n = copy_n / 16;
	ret = size;
	size = ft_pow(16, size);
	if (!num)
		return (write(1, "0", 1));
	while (size != 1)
	{
		size /= 16;
		ft_putchar_fd(base[num / size], 1);
		num %= size;
	}
	return (ret);
}

int	ft_putchar_hexadecimal_p(unsigned long num)
{
	char			*base;
	unsigned long	size;
	int				ret;
	unsigned long	copy_n;

	base = "0123456789abcdef";
	size = 0;
	copy_n = num;
	while (copy_n)
	{
		size++;
		copy_n = copy_n / 16;
	}
	ret = size;
	size = ft_pow(16, size);
	if (!num)
		return (write(1, "0", 1));
	while (size != 1)
	{
		size /= 16;
		ft_putchar_fd(base[num / size], 1);
		num %= size;
	}
	return (ret);
}
