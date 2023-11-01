/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:40:06 by nsakanou          #+#    #+#             */
/*   Updated: 2023/11/01 15:50:01 by nsakanou         ###   ########.fr       */
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
# include <float.h>

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	char		*status;
	int			bits_per_pixel;
	int			line_length;
	int			height;
	int			width;
	int			depth;
	int			color;
	double		mag;
	double		x;
	double		y;
	double		cre;
	double		cim;
}t_vars;


# define MANDEL 1
# define JULIA 2

int		ft_isdigit(int c);
int		ft_isspace(int c);
void	ft_error(void);
void	memory_error(void);

double	ft_atof(const char *str);

int		close_window_esc(int keycode, t_vars *vars);
int		close_window_x(t_vars *vars);

int		img_put2(t_vars *vars);
int		mouse_hook(int button, int x, int y, t_vars *vars);

#endif
