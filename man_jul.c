/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   man_jul.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:07:06 by nsakanou          #+#    #+#             */
/*   Updated: 2023/10/31 18:47:59 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// void	julia_set(double cre, double cim)
// {
// 	t_vars	vars;

// 	vars.height = 500;
// 	vars.width = 500;
// 	vars.depth = 15;
// 	vars.mag = 6;
// 	vars.cre = cre;
// 	vars.cim = cim;
// 	vars.status = JULIA;
// 	vars.x = vars.height / 2;
// 	vars.y = vars.width / 2;
// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, vars.height, vars.width, "fractal");
// 	vars.img = mlx_new_image(vars.mlx, vars.height, vars.width);
// 	vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, \
// 			&vars.line_length, &vars.endian);
// 	img_put2(&vars);
// 	mlx_mouse_hook(vars.win, mouse_hook, &vars);
// 	mlx_key_hook(vars.win, close_window_esc, &vars);
// 	mlx_hook(vars.win, 17, 1L << 0, close_window_x, (void *)&vars);
// 	mlx_loop(vars.mlx);
// 	exit(0);
// }

// void	mandel_set(void)
// {
// 	t_vars	vars;

// 	vars.height = 500;
// 	vars.width = 500;
// 	vars.depth = 15;
// 	vars.mag = 6;
// 	vars.color = 0;
// 	vars.ver = 0;
// 	vars.hor = 0;
// 	vars.cre = -1;
// 	vars.cim = -1;
// 	vars.status = MANDEL;
// 	vars.x = vars.height / 2;
// 	vars.y = vars.width / 2;
// 		//MLX（MinilibX）ライブラリを初期化し、mlx 構造体にその初期化されたポインタを代入
// 	vars.mlx = mlx_init();
// 	//新しいウィンドウを作成
// 	vars.win = mlx_new_window(vars.mlx, vars.height, vars.width, "fractal");
// 	vars.img = mlx_new_image(vars.mlx, vars.height, vars.width);
// 	vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, \
// 			&vars.line_length, &vars.endian);
// 	img_put2(&vars);
// 	mlx_mouse_hook(vars.win, mouse_hook, &vars);
// 	mlx_key_hook(vars.win, close_window_esc, &vars);
// 	mlx_hook(vars.win, 17, 1L << 0, close_window_x, (void *)&vars);
// 	mlx_loop(vars.mlx);
// 	exit(0);
// }
