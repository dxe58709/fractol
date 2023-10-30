/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 19:47:37 by nsakanou          #+#    #+#             */
/*   Updated: 2023/10/30 18:01:49 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
//pixel
void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

//マウスのボタンイベント（ボタンがクリックされたときなどの操作）を処理するための関数
int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	(void)x;
	(void)y;
	if (vars->mag == 0.0)//後続の拡大縮小操作で 0 除算エラーを回避するため
		vars->mag = 0.000001;
	if (button == 5)//下スクロール
		vars->mag *= 0.8;
	else if (button == 4)//上スクロール
		vars->mag *= 1.2;
	else
		return (0);
	img_put2(vars);
	return (0);
}

void	calculate_mandelbrot_set(t_vars *vars, int row, int col, int max)
{
	double	cre;
	double	cim;
	double	x;
	double	y;
	int		i;

	cre = (col - vars->width / 2.0) / (vars->width / 3) - 1.0;
	cim = (row - vars->height / 2.0) / (vars->height / 3) - 1.0;
	x = 0;
	y = 0;
	i = 0;
	while (x * x + y * y <= 4 && i < max)
	{
		double	tmpx = x * x - y * y + cre;
		y = 2 * x * y + cim;
		x = tmpx;
		mlx_pixel_put(vars->mlx, vars->win, col, row, 0x000000 + i * 100);
		i++;
	}
	if (x * x + y * y <= 4)
		mlx_pixel_put(vars->mlx, vars->win, col, row, 0x000000);
}

int	img_put2(t_vars *vars)
{
	int	height;
	int	width;
	int	row;
	int	col;
	int	max;

	height = 1000;
	width = 1000;
	row = 0;
	col = 0;
	max = 25;
	while (row < height)
	{
		col = 0;
		while (col < width)
		{
			calculate_mandelbrot_set(vars, row, col, max);
			col++;
		}
		row++;
	}
	return (0);
}
