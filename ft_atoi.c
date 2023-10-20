/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:55:24 by nsakanou          #+#    #+#             */
/*   Updated: 2023/10/20 17:59:02 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_positiv(const char *str, int *count)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (ft_isdigit(str[i + 1]) == 0)
			exit(1);
		if (str[i] == '-')
			*count *= -1;
		i++;
	}	
	return (i);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	nb;
	int		count;

	i = 0;
	nb = 0;
	count = 1;
	while (ft_isspace(str[i]))
		i++;
	if (ft_positiv(str + i, &count) == 1)
		i++;
	while (ft_isdigit(str[i]))
	{
		if (count == 1 && ((nb > LONG_MAX / 10)
				|| ((nb == LONG_MAX / 10) && (str[i] - '0') > LONG_MAX % 10)))
			return ((int)LONG_MAX);
		else if (count == -1 && ((-nb < LONG_MIN / 10)
				|| ((-nb == LONG_MIN / 10) && -(str[i] - '0') < LONG_MIN % 10)))
			return ((int)LONG_MIN);
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb * count);
}
