/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:28:30 by nsakanou          #+#    #+#             */
/*   Updated: 2023/11/06 20:03:50 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	check_args(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 2 && ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		check_mandel();
	else if (argc == 4 && ft_strncmp(argv[1], "julia", 5) == 0)
		check_julia();
	else
		argv_error();
}
