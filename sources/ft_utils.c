#include "ft_printf.h"

static int	pow(int num, int pow_n)
{
	int	result;

	result = 1;
	while (pow_n)
	{
		result *= num;
		pow_n--;
	}
	return (result);
}

void	ft_putnbr_unsigned(unsigned int n)
{
	int				size;
	unsigned int	copy_n;

	//write(1,"aa",2);
	size = 0;
	copy_n = n;
	while (copy_n)
	{
		size++;
		copy_n /= 10;
	}
	if (!n)
		ft_putchar_fd('0', 1);
	while (size)
	{
		ft_putchar_fd(n / pow(10, size - 1) + '0', 1);
		n %= pow(10, size - 1);
		size--;
	}
}