/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjamis <tjamis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:53:29 by tjamis            #+#    #+#             */
/*   Updated: 2021/05/05 14:55:17 by tjamis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	size;

	if (!s)
		return (0);
	size = ft_strlen(s);
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
	return (size);
}
