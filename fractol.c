/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 19:47:37 by nsakanou          #+#    #+#             */
/*   Updated: 2023/11/07 19:51:18 by nsakanou         ###   ########.fr       */
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
	if (vars->mag == 0.0)
		vars->mag = 0.000001;
	if (button == 5)//下スクロール
		vars->mag *= 0.8;
	else if (button == 4)//上スクロール
		vars->mag *= 1.2;
	else
		return (0);
	img_put2(vars, vars->set_type);
	return (0);
}
//col（列）: 複素数平面上で横方向
//row（行）: 複素数平面上で縦方向
//cre; 定数Cの実部(x方向)
//cim; 定数Cの虚部(y方向)
//複素数Zの実部（x）と虚部（`y）
//i; 反復回数

// unsigned int	check_mandel(t_vars *vars, int col, int row)
// {
// 	double	x;
// 	double	y;
// 	int		i;
// 	double	tmp;

// 	x = 0.0;
// 	y = 0.0;
// 	i = 0;
// 	vars->cre = (col - vars->width / 2.0) / (vars->width / vars->mag);
// 	vars->cim = (row - vars->height / 2.0) / (vars->height / vars->mag);
// 	while (x * x + y * y <= 4 && i < 200)//円の内部かどうか
// 	{
// 		tmp = x * x - y * y + vars->cre;
// 		y = 2 * x * y + vars->cim;
// 		x = tmp;
// 		i++;
// 	}
// 	if (x * x + y * y > 4)
// 	{
// 		if (1 < i)
// 			return (0x9900cc + i * 100);
// 		else
// 			return (0x9900cc);
// 	}
// 	else
// 		return (0x000000);
// }

// unsigned int	check_julia(t_vars *vars, int col, int row)
// {
// 	double	x;
// 	double	y;
// 	int		i;
// 	double	tmp;

// 	x = (col - vars->width / 2.0) / (vars->width / vars->mag);
// 	y = (row - vars->height / 2.0) / (vars->height / vars->mag);
// 	i = 0;
// 	vars->cre = -0.7;// ジュリア集合の特定の初期値
// 	vars->cim = 0.2;// ジュリア集合の特定の初期値
// 	while (x * x + y * y <= 4 && i < 200)
// 	{
// 		tmp = x * x - y * y + vars->cre;
// 		y = 2 * x * y + vars->cim;
// 		x = tmp;
// 		i++;
// 		// printf("DEBUG [%s]{%d}: %f, %f, %d, %d, %d\n", __func__, __LINE__, y, x, col, row, i);
// 	}
// 	if (x * x + y * y > 4)
// 	{
// 		if (1 < i)
// 			return (0x9900cc + i * 100);
// 		else
// 			return (0x9900cc);
// 	}
// 	else
// 		return (0x000000);
// }
// int	img_put2(t_vars *vars)
// {
// 	int	col;
// 	int	row;
// 	int	color;

// 	vars->height = 800;
// 	vars->width = 800;
// 	row = 0;
// 	while (row < vars->height)
// 	{
// 		col = 0;
// 		while (col < vars->width)
// 		{
// 			// color = check_mandel(vars, col, row);
// 			// color = check_julia(vars, col, row);
// 			my_mlx_pixel_put(vars, col, row, color);
// 			col++;
// 		}
// 		row++;
// 	}
// 	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
// 	return (0);
// }

void	ft_calculation(t_vars *vars, int col, int row, int set_type)
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
	while (x * x + y * y <= 4 && i < 200)//円の内部かどうか
	{
		tmp = x * x - y * y + vars->cre;
		y = 2 * x * y + vars->cim;
		x = tmp;
		i++;
	}
	if (set_type == MANDEL)
		my_mlx_pixel_put(vars, col, row, 0x9900cc + i * 100);
	else if (set_type == JULIA)
		my_mlx_pixel_put(vars, col, row, 0x9900cc + i * 100);
}

int	img_put2(t_vars *vars, int set_type)
{
	int	col;
	int	row;

	vars->height = 800;
	vars->width = 800;
	row = 0;
	while (row < vars->height)
	{
		col = 0;
		while (col < vars->width)
		{
			ft_calculation(vars, col, row, set_type);
			col++;
		}
		row++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	return (0);
}
