/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:57:11 by nsakanou          #+#    #+#             */
/*   Updated: 2023/10/20 19:52:57 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "fractol.h"
// 円を絵画+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++#
// #include <mlx.h>
// #include <stdio.h>

// //構造体の宣言
// typedef struct	s_vars {
// 	void	*mlx;
// 	void	*win;
// }				t_vars;

// //画面を閉じる関数
// int	close(int keycode, t_vars *vars)
// {
// 	(void) keycode;
// 	mlx_destroy_window(vars->mlx, vars->win);
// 	return (0);
// }

// //円を描画する関数
// int	img_put(int keycode, t_vars *vars)
// {
// 	int		x;
// 	int		y;

// 	keycode = 0;
// 	y = 0;
// 	x = 0;
// 	while (x * x + y * y < 1000000)
// 	{
// 		x = 0;
// 		while (x * x + y * y  < 100000)
// 		{
			//対象のウィンドウ、ピクセルのx座標、y座標、および描画する色を受け取ります。
// 			mlx_pixel_put(vars->mlx, vars->win, -x + 500, y + 500, 0x00909000); // 赤色でピクセルを描画
// 			mlx_pixel_put(vars->mlx, vars->win, x + 500, -y + 500, 0x00909000); // 赤色でピクセルを描画
// 			mlx_pixel_put(vars->mlx, vars->win, x + 500, y + 500, 0x00909000); // 赤色でピクセルを描画
// 			mlx_pixel_put(vars->mlx, vars->win, -x + 500, -y + 500, 0x00909000); // 赤色でピクセルを描画
// 			x++;
// 		}
// 		y++;
// 	}
// 	return (0);
// }

// //keyの中身を見て、その中身に応じて何かを実行する関数
// int	key_hook(int keycode, t_vars *vars)
// {
// 	printf("Hello from key_hook!%d\n",keycode);
// 	img_put(keycode, vars);
// 	if (keycode == 53)//esc_keyの場合は画面を閉じるようにする
// 		close(keycode, vars);
// 	return (0);
// }


// int	main(void)
// {
// 	t_vars	vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 1000,1000, "Hello world!");
// 	mlx_key_hook(vars.win, key_hook, &vars);
// 	mlx_loop(vars.mlx);
// }
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++#

//マンデルブロ+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++#
#include <stdlib.h>
#include <mlx.h>
#include <stdio.h>

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		height;
	int		width;
	int		depth;
	int		x;
	int		y;
	double	mag;
}t_vars;

//画面を閉じる関数
int	close(int keycode, t_vars *vars)
{
	(void) keycode;
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

void	img_put2(t_vars *vars)
{
	int	row = 0;
	int	col = 0;
//	printf("Hello from key_hook![%d]\n",vars->mag);

	while (row < vars->height)
	{
		col = 0;
		while (col < vars->width)
		{
			double	cre = (col - vars->width / 2.0) / (vars->width / vars->mag);
			double	cim = (row - vars->height / 2.0) / (vars->height / vars->mag);
			double	x = 0;
			double	y = 0;
			int		i = 0;

			//printf("[cre:%f,cim:%f]\n",cre,cim);
			while(x * x + y * y <= 4 && i < vars->depth)
			{
				double	tmpx = x*x - y *y + cre;
				y = 2 * x * y + cim;
				x = tmpx;
				mlx_pixel_put(vars->mlx, vars->win, col , row ,  0x0 + i * 190);
				i++;
			}
			if (x * x + y * y <= 4)
				mlx_pixel_put(vars->mlx, vars->win, col , row ,  0xe2e627);
			//else
			//	mlx_pixel_put(vars->mlx, vars->win, col, row, 0x00000000);

			col++;
		}
		row++;
	}
}

int	img_put(int keycode, t_vars *vars)
{
	int		x;
	int		y;

	y = 0;
	while (y < keycode * 1000)
	{
		x = 10 * keycode;
		//while (x < 300)
		//{
			mlx_pixel_put(vars->mlx, vars->win, y * y , keycode * y, 0x00FF00); // 赤色でピクセルを描画
		//	x++;
		//}
		y++;
	}
	return (0);
}
//マウスのボタンイベント（ボタンがクリックされたときなどの操作）を処理するための関数
int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	if (button == 5)
		vars->mag += 0.3;
	else if (button == 4)
		vars->mag -= 0.3;
	printf("Hello from mouse_hook![%d][%d][%d][%f]\n", button, x, y, vars->mag);
	img_put2(vars);
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
//	printf("Hello from key_hook!%d\n",keycode);
	vars->mag += 0.3;
	if (keycode == 53)//esc_keyの場合は画面を閉じるようにする
		return(close(keycode, vars));
	img_put2(vars);
	return (0);
}

int	exit_wind(t_vars *vars)
{
	(void)vars;
	exit(0);
}

int	main(void)
{
	t_vars	vars;

	vars.height = 500;
	vars.width = 500;
	vars.depth = 15;
	vars.mag = 6;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "Hello world!");
	img_put2(&vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 1L << 0, exit_wind, (void *)&vars);
	mlx_loop(vars.mlx);
	exit(0);
}