/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:40:06 by nsakanou          #+#    #+#             */
/*   Updated: 2023/12/05 15:44:25 by nsakanou         ###   ########.fr       */
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
	int			set_type;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			height;
	int			width;
	double		mag;
	double		cre;
	double		cim;
	double		check_cre;
	double		check_cim;
}t_vars;

# define MANDEL 1
# define JULIA 2

int		ft_isdigit(int c);
int		ft_isspace(int c);
void	ft_error(void);
void	argv_error(void);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

double	ft_atof(const char *str);

int		close_window_esc(int keycode, t_vars *vars);
int		close_window_x(t_vars *vars);

int		img_put2(t_vars *vars);
int		mouse_hook(int button, int x, int y, t_vars *vars);
void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color);
#endif
