/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:30:21 by gsilva            #+#    #+#             */
/*   Updated: 2024/05/08 17:37:25 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int		main_loop(void);
void	raycast(void);
void	get_pos(int x);
void	step(void);
void	dda(void);

int	main_loop(void)
{
	if (plr()->key.w)
		walk_ns(1);
	if (plr()->key.s)
		walk_ns(-1);
	if (plr()->key.d)
		walk_ew(1);
	if (plr()->key.a)
		walk_ew(-1);
	if (plr()->key.r)
		rotate(-1);
	if (plr()->key.l)
		rotate(1);
	raycast();
}

void	raycast(void)
{
	int	x;
	t_img	*img;

	x = -1;
	new_px_data();
	while (++x < 640)
	{
		get_pos(x);
		step();
		dda();
		img = tex_calc();
		set_scene(img, x);
	}
	paint_scene();
}

void	get_pos(int x)
{
	plr()->cam = 2 * x / (double)640 - 1;
	plr()->rayDir.x = plr()->dir.x + plr()->plane.x * plr()->cam;
	plr()->rayDir.y = plr()->dir.y + plr()->plane.y * plr()->cam;
	plr()->mapX = (int)plr()->pos.x;
	plr()->mapY = (int)plr()->pos.y;
	plr()->deltaDist.x = fabs(1 / plr()->rayDir.x);
	plr()->deltaDist.y = fabs(1 / plr()->rayDir.y);
	plr()->hit = 0;
}

void	step(void)
{
	if (plr()->rayDir.x < 0)
	{
		plr()->stepX = -1;
		plr()->sideDist.x = (plr()->pos.x - plr()->mapX) * plr()->deltaDist.x;
	}
	else
	{
		plr()->stepX = 1;
		plr()->sideDist.x = (plr()->mapX + 1.0 - plr()->pos.x) * plr()->deltaDist.x;
	}
	if (plr()->rayDir.y < 0)
	{
		plr()->stepY = -1;
		plr()->sideDist.y = (plr()->pos.y - plr()->mapY) * plr()->deltaDist.y;
	}
	else
	{
		plr()->stepY = 1;
		plr()->sideDist.y = (plr()->mapY + 1.0 - plr()->pos.y) * plr()->deltaDist.y;
	}
}

void	dda(void)
{
	while (plr()->hit == 0)
	{
		if (plr()->sideDist.x < plr()->sideDist.y)
		{
			plr()->sideDist.x += plr()->deltaDist.x;
			plr()->mapX += plr()->stepX;
			plr()->side = 0;
		}
		else
		{
			plr()->sideDist.y += plr()->deltaDist.y;
			plr()->mapY += plr()->stepY;
			plr()->side = 1;
		}
		if (map()->map[plr()->mapY][plr()->mapX] == '1')
			plr()->hit = 1;
	}
	if (plr()->side == 0)
		plr()->perpWallDist = plr()->sideDist.x - plr()->deltaDist.x;
	else
		plr()->perpWallDist = plr()->sideDist.y - plr()->deltaDist.y;
	if (plr()->perpWallDist < 0.0001)
		plr()->perpWallDist = 0.0001;
}
