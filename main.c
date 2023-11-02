/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:34:48 by nsakanou          #+#    #+#             */
/*   Updated: 2023/11/02 16:40:10 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	t_vars	vars;

	vars.height = 800;
	vars.width = 800;
	vars.depth = 15;
	vars.mag = 4;
	vars.color = 0;

	//MLX（MinilibX）ライブラリを初期化し、mlx 構造体にその初期化されたポインタを代入
	vars.mlx = mlx_init();
	//新しいウィンドウを作成↓800×800ピクセル
	vars.win = mlx_new_window(vars.mlx, 800, 800, "fractol");
	vars.img = mlx_new_image(vars.mlx, vars.width, vars.height);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, \
			&vars.line_length, &vars.endian);
	img_put2(&vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_key_hook(vars.win, close_window_esc, &vars);
	mlx_hook(vars.win, 17, 1L << 0, close_window_x, (void *)&vars);
	mlx_loop(vars.mlx);
	exit (0);
}

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