/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:09:43 by nsakanou          #+#    #+#             */
/*   Updated: 2023/06/16 14:26:07 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_hex(unsigned int n)
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

void	ft_puthex(unsigned int n, const char fmt)
{
	int	fd;

	fd = 1;
	if (n < 16)
	{
		if (n < 10)
			ft_putchar(fd, n + '0');
		else if (fmt == 'x')
			ft_putchar(fd, 'a' + (n - 10));
		else if (fmt == 'X')
			ft_putchar(fd, 'A' + (n - 10));
	}
	else
	{
		ft_puthex(n / 16, fmt);
		ft_puthex(n % 16, fmt);
	}
}

int	ft_print_hex(unsigned int n, const char fmt)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		ft_puthex(n, fmt);
		count = 1;
	}
	else
	{
		ft_puthex(n, fmt);
		count += count_hex(n);
	}
	return (count);
}
