/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:08:01 by nsakanou          #+#    #+#             */
/*   Updated: 2023/11/01 14:04:11 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// unsigned int	check_color_j(t_vars *vars, double zre, double zim)
// {
// 	int		i;
// 	double	tmp;

// 	i = 0;
// 	while (zre * zre + zim * zim <= 4 && i < vars->depth)
// 	{
// 		tmp = zre * zre - zim * zim + vars->cre;
// 		zim = 2 * zre * zim + vars->cim;
// 		zre = tmp;
// 		i++;
// 	}
// 	if (zre * zre + zim * zim > 4)
// 	{
// 		if (1 < i)
// 			return (0x1234567890 + i * 190 + vars->color);
// 		else
// 			return (0x0);
// 	}
// 	else
// 		return (0xe2e627 + vars->color);
// }
