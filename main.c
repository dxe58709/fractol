/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:34:48 by nsakanou          #+#    #+#             */
/*   Updated: 2023/10/31 19:47:29 by nsakanou         ###   ########.fr       */
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
	mlx_key_hook(vars.win, close_window_esc, &vars);
	//x終了
	mlx_hook(vars.win, 17, 1L << 0, close_window_x, (void *)&vars);
	mlx_loop(vars.mlx);
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	t_vars	vars;

// 	if (check_args(argc, argv) && init_fractal(argv, &vars.f) && init_mlx(&vars))
// 	{
// 		mlx_loop_hook(vars.mlx, draw_and_put_image, &vars);
// 		mlx_key_hook(vars.win, close_window_esc, &vars);
// 		mlx_hook(vars.win, 17, 1L << 0, close_window_x, (void *)&vars);
// 		mlx_mouse_hook(vars.win, mouse_hook, &vars);
// 		mlx_loop(vars.mlx);
// 		return (finalized_with_success(&vars));
// 	}
// 	return (ERROR);
// }

//メモリリーク
// __attribute__((destructor))
// static void destructor() {
// 	system("leaks -q fractol");
// }


// int	main(int argc, char **argv)
// {
// 	int		i;
// 	double	cre;
// 	double	cim;
// 	int		check_cim;
// 	int		check_cre;

// 	i = 0;
// 	if (argc == 2 && argv[1][0] == 'm' && argv[1][1] == '\0')
// 		mandel_set();
// 	else if (argc == 4 && argv[1][0] == 'j' && argv[1][1] == '\0')
// 	{
// 		check_cre = ft_atof(argv[2], &cre);
// 		check_cim = ft_atof(argv[3], &cim);
// 		if (check_cre == 0 || check_cim == 0)
// 			return (error_massage());
// 		julia_set(cre, cim);
// 	}
// 	return (error_massage());
// }