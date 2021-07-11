/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjamis <tjamis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 15:41:09 by tjamis            #+#    #+#             */
/*   Updated: 2021/05/10 17:26:46 by tjamis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

static size_t	ft_pow(int num, int pow_n)
{
	size_t	result;

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

static int	ft_abs(int c)
{
	if (c < 0)
		return (-c);
	return (c);
}

int	ft_putnbr_fd(int n, int fd)
{
	int		size;
	int		ret;
	int		copy_n;

	size = 0;
	copy_n = n;
	while (copy_n)
	{
		size++;
		copy_n /= 10;
	}
	ret = size;
	size = ft_pow(10, size);
	if (n < 0)
		ret += write(1, "-", 1);
	if (!n)
		ret += write(1, "0", 1);
	while (size != 1)
	{
		size /= 10;
		ft_putchar_fd(ft_abs(n / size) + '0', fd);
		n %= size;
	}
	return (ret);
}
