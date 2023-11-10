/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:34:48 by nsakanou          #+#    #+#             */
/*   Updated: 2023/11/10 15:24:41 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	vars.height = 800;
	vars.width = 800;
	vars.mag = 4;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 800, 800, "fractol");
	vars.img = mlx_new_image(vars.mlx, vars.width, vars.height);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, \
			&vars.line_length, &vars.endian);
	if (argc == 2 && ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		vars.set_type = MANDEL;
	else if (argc == 4 && ft_strncmp(argv[1], "julia", 5) == 0)
	{
		vars.check_cre = ft_atof(argv[2]);
		vars.check_cim = ft_atof(argv[3]);
		vars.set_type = JULIA;
	}
	else
		argv_error();
	img_put2(&vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_key_hook(vars.win, close_window_esc, &vars);
	mlx_hook(vars.win, 17, 1L << 0, close_window_x, (void *)&vars);
	mlx_loop(vars.mlx);
	exit (0);
}

// __attribute__((destructor))
// static void destructor() {
// 	system("leaks -q fractol");
// }
