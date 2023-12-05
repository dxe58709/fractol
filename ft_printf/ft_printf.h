/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:10:11 by nsakanou          #+#    #+#             */
/*   Updated: 2023/10/11 16:37:02 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>
# include <stdlib.h>

ssize_t	ft_putchar(int fd, char c);
ssize_t	ft_putstr(int fd, const char *str);
int		ft_print_unbr(int fd, unsigned int n);
int		ft_print_nbr(int n);
int		ft_print_hex(unsigned int n, const char format);
int		ft_ptr(const void *ptr);
int		ft_printf(const char *fmt, ...);

#endif
