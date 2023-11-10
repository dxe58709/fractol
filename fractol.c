/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 19:47:37 by nsakanou          #+#    #+#             */
/*   Updated: 2023/11/10 18:01:02 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	(void)x;
	(void)y;
	if (vars->mag == 0.0)
		vars->mag = 0.000001;
	if (button == 5)
		vars->mag *= 0.8;
	else if (button == 4)
		vars->mag *= 1.2;
	else
		return (0);
	img_put2(vars);
	return (0);
}

unsigned int	check_mandel(t_vars *vars, int col, int row)
{
	double	x;
	double	y;
	int		i;
	double	tmp;

	x = 0.0;
	y = 0.0;
	i = 0;
	vars->cre = (col - vars->width / 2.0) / (vars->width / vars->mag);
	vars->cim = (row - vars->height / 2.0) / (vars->height / vars->mag);
	while (x * x + y * y <= 4 && i < 200)
	{
		tmp = x * x - y * y + vars->cre;
		y = 2 * x * y + vars->cim;
		x = tmp;
		i++;
	}
	return (0x9900cc + i * 100);
}

unsigned int	check_julia(t_vars *vars, int col, int row)
{
	double	x;
	double	y;
	int		i;
	double	tmp;

	x = (col - vars->width / 2.0) / (vars->width / vars->mag);
	y = (row - vars->height / 2.0) / (vars->height / vars->mag);
	i = 0;
	vars->cre = vars->check_cre;
	vars->cim = -(vars->check_cim);
	while (x * x + y * y <= 4 && i < 200)
	{
		tmp = x * x - y * y + vars->cre;
		y = 2 * x * y + vars->cim;
		x = tmp;
		i++;
	}
	return (0x9900cc + i * 100);
}

int	img_put2(t_vars *vars)
{
	int	col;
	int	row;
	int	color;

	vars->height = 800;
	vars->width = 800;
	row = 0;
	while (row < vars->height)
	{
		col = 0;
		while (col < vars->width)
		{
			if (vars->set_type == MANDEL)
				color = check_mandel(vars, col, row);
			else if (vars->set_type == JULIA)
				color = check_julia(vars, col, row);
			my_mlx_pixel_put(vars, col, row, color);
			col++;
		}
		row++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	return (0);
}
