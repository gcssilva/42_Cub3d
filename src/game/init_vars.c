/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 19:48:58 by gsilva            #+#    #+#             */
/*   Updated: 2024/05/12 01:21:48 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	vert(int p);
void	hor(int p);
void	init_vars(void);
void	start_game(void);
void	paint_scene(void);

void	vert(int p)
{
	plr()->dir.x = 0;
	plr()->plane.y = 0;
	if (p == 'N')
	{
		plr()->dir.y = -1;
		plr()->plane.x = -0.66;
	}
	else
	{
		plr()->dir.y = 1;
		plr()->plane.x = 0.66;
	}
}

void	hor(int p)
{
	plr()->dir.y = 0;
	plr()->plane.x = 0;
	if (p == 'E')
	{
		plr()->dir.x = -1;
		plr()->plane.y = 0.66;
	}
	else
	{
		plr()->dir.x = 1;
		plr()->plane.y = -0.66;
	}
}

void	init_vars(void)
{
	(mlx()->win) = mlx_new_window(mlx()->mlx, 640, 480, "cub3d");
	win()->img = (t_img *)malloc(sizeof(t_img));
	(win()->img->img) = mlx_new_image(mlx()->mlx, 640, 480);
	win()->img->addr = aux_get_add();
	if (map()->p == 'N' || map()->p == 'S')
		vert(map()->p);
	else
		hor(map()->p);
	plr()->pos.x = plr()->mapx + 0.5;
	plr()->pos.y = plr()->mapy + 0.5;
}

void	start_game(void)
{
	init_vars();
	mlx_hook(mlx()->win, KeyPress, KeyPressMask, press, mlx()->win);
	mlx_hook(mlx()->win, KeyRelease, KeyReleaseMask, release, mlx()->win);
	mlx_loop_hook(mlx()->mlx, main_loop, mlx()->win);
	mlx_hook(mlx()->win, 17, 0, key_close, &mlx()->win);
	mlx_loop(mlx()->mlx);
}

void	paint_scene(void)
{
	int	y;
	int	x;

	y = -1;
	while (++y < 480)
	{
		x = -1;
		while (++x < 640)
		{
			if (win()->px_data[y][x] > 0)
				set_px(x, y, win()->px_data[y][x]);
			else if (y < 240)
				set_px(x, y, map()->c_rgb[0] * 65536 \
						+ map()->c_rgb[1] * 256 + map()->c_rgb[2]);
			else
				set_px(x, y, map()->f_rgb[0] * 65536 \
						+ map()->f_rgb[1] * 256 + map()->f_rgb[2]);
		}
	}
	mlx_put_image_to_window(mlx()->mlx, mlx()->win, win()->img->img, 0, 0);
}
