/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:10:03 by nsakanou          #+#    #+#             */
/*   Updated: 2023/10/11 16:45:07 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_judge_format(int fd, const char *fmt, va_list ap, ssize_t count)
{
	ssize_t	i;

	i = 0;
	if (fmt[i] == '%')
		count += ft_putchar(fd, fmt[i]);
	else if (fmt[i] == 'c')
		count += ft_putchar(fd, va_arg(ap, int));
	else if (fmt[i] == 's')
		count += ft_putstr(fd, va_arg(ap, const char *));
	else if (fmt[i] == 'u')
		count += ft_print_unbr(fd, va_arg(ap, unsigned int));
	else if (fmt[i] == 'x' || fmt[i] == 'X')
		count += ft_print_hex(va_arg(ap, unsigned int), *fmt);
	else if (fmt[i] == 'd' || fmt[i] == 'i')
		count += ft_print_nbr(va_arg(ap, int));
	else if (fmt[i] == 'p')
		count += ft_ptr(va_arg(ap, void *));
	return (count);
}

int	fmt_count(int fd, const char *fmt, va_list ap)
{
	ssize_t	i;
	ssize_t	count;

	i = 0;
	count = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			i++;
			count = ft_judge_format(fd, &fmt[i], ap, count);
			if (!ft_judge_format(fd, &fmt[i], ap, count))
				exit(1);
		}
		else
			count += ft_putchar(fd, fmt[i]);
		i++;
	}
	return (count);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	ssize_t	count;

	va_start(ap, fmt);
	count = fmt_count(STDOUT_FILENO, fmt, ap);
	va_end(ap);
	return (count);
}
