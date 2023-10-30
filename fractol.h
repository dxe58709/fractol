/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:40:06 by nsakanou          #+#    #+#             */
/*   Updated: 2023/10/30 18:03:35 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "ft_printf.h"
# include <mlx.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stddef.h>
# include <libc.h>
# include <string.h>
# include <stdio.h>
# include <ctype.h>
# include <stdbool.h>

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		height;
	int		width;
	int		depth;
	double	x;
	double	y;
	double	mag;
}t_vars;

# define MANDEL 1
# define JULIA 2

int		ft_isdigit(int c);
int		ft_isspace(int c);
void	ft_error(void);
void	memory_error(void);

int		ft_atoi(const char *str);

int		key_hook(int keycode, t_vars *vars);
int		close_window(t_vars *vars);

int		img_put2(t_vars *vars);
int		mouse_hook(int button, int x, int y, t_vars *vars);

#endif
