/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:55:24 by nsakanou          #+#    #+#             */
/*   Updated: 2023/10/31 15:51:27 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	skip_sp_sign(const char *str, int *sign)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sign *= -1;
		i++;
	}
	return (i);
}

static double	read_integer(const char *str, int *i)
{
	double	nb;

	nb = 0;
	while (str[*i] && ft_isdigit(str[*i]) && str[*i] != '.')
	{
		nb = nb * 10.0 + (str[*i] - '0');
		(*i)++;
	}
	return (nb);
}

static double	read_decimals(const char *str, int *i)
{
	double	decimals;
	double	nb;

	decimals = 0.1;
	nb = read_integer(str, i);
	if (str[*i] == '.')
	{
		(*i)++;
		while (str[*i] && ft_isdigit(str[*i]))
		{
			nb = nb + ((str[*i] - '0') * decimals);
			decimals *= 0.1;
			(*i)++;
		}
	}
	return (nb);
}

double	ft_atof(const char *str)
{
	int		i;
	int		sign;
	double	nb;

	sign = 1;
	i = skip_sp_sign(str, &sign);
	nb = read_decimals(str, &i);
	if (nb < -DBL_MAX)
		ft_error();
	if (nb > DBL_MAX)
		ft_error();
	if (!ft_isdigit(str[i]) && str[i])
		ft_error();
	return (nb * sign);
}
