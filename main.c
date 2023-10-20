/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:34:48 by nsakanou          #+#    #+#             */
/*   Updated: 2023/10/20 19:39:24 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	t_vars	vars;

	vars.height = 500;
	vars.width = 500;
	vars.depth = 15;
	vars.mag = 6;

	//MLX（MinilibX）ライブラリを初期化し、mlx 構造体にその初期化されたポインタを代入
	vars.mlx = mlx_init();
	//新しいウィンドウを作成↓800×600ピクセル
	vars.win = mlx_new_window(vars.mlx, 800, 600, "fractol");
	//esc終了
	mlx_key_hook(vars.win, key_hook, &vars);
	//x終了
	mlx_hook(vars.win, 17, 1L << 0, close_window, (void *)&vars);
	mlx_loop(vars.mlx);
	return (0);
}

	// int	x = 0;
	// int	y = 0;

	// mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	// img.img = mlx_new_image(mlx, 1920, 1080);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	// 							&img.endian);
	// while (x < 500)
	// {
	// 	y = 0;
	// 	while (y < 500)
	// 	{
	// 		my_mlx_pixel_put(&img, x, y, 0x0000000FF);
	// 		y++;
	// 	}
	// 	x++;
	// }
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);