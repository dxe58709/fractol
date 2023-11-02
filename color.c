/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:53:08 by nsakanou          #+#    #+#             */
/*   Updated: 2023/11/02 16:39:13 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
//pixel
void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

//color
// カラーマップを定義
int colormap[256] = {
    0x000000, 0xFF0000, 0x00FF00, 0x0000FF, /* 他の色 */
    /* ... 途中省略 ... */
};

void	color_set(t_vars *vars, int col, int row, int result)
{
	int	color;

	if (result < vars->depth)
	{
	    // 計算結果に基づいてカラーマップから色を選択
		color = colormap[result % 256];
	}
	else
		color = 0x000000; // 別の色や背景色を設定
	my_mlx_pixel_put(vars, col, row, color);
}

//color
// void	color_set(t_vars *vars, int i, int x, int y)
// {
// 	int	color;

// 	color = 0x0000;
// 	if (vars->color % 6 == 0 || vars->color % 6 == 3)//2で割れる処理
// 	{
		
// 	}
// 	else if (vars->color % 6 == 1 || vars->color % 6 == 4)
// }

/*
赤: #FF0000 (R: 255, G: 0, B: 0)
緑: #00FF00 (R: 0, G: 255, B: 0)
青: #0000FF (R: 0, G: 0, B: 255)
白: #FFFFFF (R: 255, G: 255, B: 255)
黒: #000000 (R: 0, G: 0, B: 0)
グレー: #808080 (R: 128, G: 128, B: 128)
シアン: #00FFFF (R: 0, G: 255, B: 255)
マゼンタ: #FF00FF (R: 255, G: 0, B: 255)
イエロー: #FFFF00 (R: 255, G: 255, B: 0)
オレンジ: #FFA500 (R: 255, G: 165, B: 0)
*/