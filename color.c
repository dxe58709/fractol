/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:53:08 by nsakanou          #+#    #+#             */
/*   Updated: 2023/10/31 19:58:17 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_color(t_vars *m, int i, int x, int y)
{
	if (m->color % 5 == 0)
		color_1(m, i, x, y);
	else if (m->color % 5 == 1)
		color_2(m, i, x, y);
	else if (m->color % 5 == 2)
		color_3(m, i, x, y);
	else if (m->color % 5 == 3)
		color_4(m, i, x, y);
	else if (m->color % 5 == 4)
		color_5(m, i, x, y);
}
