/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:06:30 by nsakanou          #+#    #+#             */
/*   Updated: 2023/10/30 17:47:08 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
//esc
int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

//x
int	close_window(t_vars *vars)
{
	(void)vars;
	exit(0);
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
