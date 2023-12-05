/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:19:16 by nsakanou          #+#    #+#             */
/*   Updated: 2023/12/05 18:58:30 by nsakanou         ###   ########.fr       */
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

void	argv_error(void)
{
	ft_printf("argv_error.\n");
	exit(-1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i] || s1[i] == '\0')
			return (((unsigned char)s1[i]) - ((unsigned char)s2[i]));
		i++;
	}
	if (s1[i] != '\0')//juliaaなどを弾くため
		return (1);
	return (0);
}
