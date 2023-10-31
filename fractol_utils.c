/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:19:16 by nsakanou          #+#    #+#             */
/*   Updated: 2023/10/31 16:00:28 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

void	ft_error(void)
{
	ft_printf("error.\n");
	exit(-1);
}

void	memory_error(void)
{
	ft_printf("Memory allocation failed.\n");
	exit(-1);
}
