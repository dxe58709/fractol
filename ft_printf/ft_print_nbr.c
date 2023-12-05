/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:09:51 by nsakanou          #+#    #+#             */
/*   Updated: 2023/06/16 14:29:48 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_digits(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count = 1;
	if (n == INT_MIN)
		return (11);
	else if (n < 0)
	{
		count = 1;
		n = -n;
	}		
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

void	ft_putnbr(int n)
{
	int	fd;

	fd = 1;
	if (n >= 0 && n <= 9)
		ft_putchar(fd, n + '0');
	else if (10 <= n)
	{
		ft_putnbr(n / 10);
		ft_putchar(fd, n % 10 + '0');
	}
	else if (n < 0)
	{
		if (n == INT_MIN)
			ft_putstr(fd, "-2147483648");
		else
		{
			ft_putchar(fd, '-');
			ft_putnbr(-n);
		}
	}
}

int	ft_print_nbr(int n)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		ft_putnbr(0);
		count = 1;
	}
	else
	{
		ft_putnbr(n);
		count += count_digits(n);
	}
	return (count);
}
