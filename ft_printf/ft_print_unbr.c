/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:09:55 by nsakanou          #+#    #+#             */
/*   Updated: 2023/06/16 14:26:26 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_udigits(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count = 1;
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

void	ft_putunbr(int fd, unsigned int n)
{
	if (n <= 9)
		ft_putchar(fd, n + '0');
	else if (10 <= n)
	{
		ft_putunbr(fd, n / 10);
		ft_putchar(fd, n % 10 + '0');
	}
}

int	ft_print_unbr(int fd, unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		ft_putunbr(fd, 0);
		count = 1;
	}
	else
	{
		ft_putunbr(fd, n);
		count += count_udigits(n);
	}
	return (count);
}
