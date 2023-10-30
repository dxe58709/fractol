/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:34:48 by nsakanou          #+#    #+#             */
/*   Updated: 2023/10/30 18:03:10 by nsakanou         ###   ########.fr       */
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
	vars.win = mlx_new_window(vars.mlx, 800, 800, "fractol");
	img_put2(&vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	//esc終了
	mlx_key_hook(vars.win, key_hook, &vars);
	//x終了
	mlx_hook(vars.win, 17, 1L << 0, close_window, (void *)&vars);
	mlx_loop(vars.mlx);
	return (0);
}

//メモリリーク
// __attribute__((destructor))
// static void destructor() {
// 	system("leaks -q fractol");
// }