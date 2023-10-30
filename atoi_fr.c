/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_fr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:55:24 by nsakanou          #+#    #+#             */
/*   Updated: 2023/10/30 15:56:41 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_positive(const char *str, int *sign)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sign *= -1;
		i++;
	}
	if (ft_isdigit(str[i]) == 0)
		ft_error();
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	nb;
	int		sign;

	i = 0;
	nb = 0;
	sign = 1;
	if (ft_positive(str + i, &sign) == 0)
		i++;
	while (ft_isdigit(str[i]))
	{
		nb = nb * 10 + (str[i] - '0');
		if ((sign == 1 && INT_MAX < nb) || \
			(sign == -1 && INT_MIN > -nb))
			ft_error();
		i++;
	}
	if (!ft_isdigit(str[i]) && str[i] != '\0')
		ft_error();
	return (nb * sign);
}
