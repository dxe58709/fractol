/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:10:15 by nsakanou          #+#    #+#             */
/*   Updated: 2023/06/16 14:28:55 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_ptr(uintptr_t n)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		count++;
		n /= 16;
	}
	return (count);
}

void	ptr_puthex(int fd, uintptr_t n)
{
	fd = 1;
	if (n < 16)
	{
		if (n < 10)
			ft_putchar(fd, n + '0');
		else
			ft_putchar(fd, 'a' + (n - 10));
	}
	else
	{
		ptr_puthex(fd, n / 16);
		ptr_puthex(fd, n % 16);
	}
}

int	ft_ptr(const void *ptr)
{
	int			count;
	int			fd;

	fd = 1;
	count = 0;
	count += ft_putstr(fd, "0x");
	if (ptr == NULL)
		count += ft_putchar(fd, '0');
	else
	{
		ptr_puthex(fd, (uintptr_t)ptr);
		count += count_ptr((uintptr_t)ptr);
	}
	return (count);
}
