/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:30:21 by gsilva            #+#    #+#             */
/*   Updated: 2024/05/12 01:17:23 by gsilva           ###   ########.fr       */
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
	return (0);
}

void	raycast(void)
{
	int		x;
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
	plr()->ray_dir.x = plr()->dir.x + plr()->plane.x * plr()->cam;
	plr()->ray_dir.y = plr()->dir.y + plr()->plane.y * plr()->cam;
	plr()->mapx = (int)plr()->pos.x;
	plr()->mapy = (int)plr()->pos.y;
	plr()->delta_dist.x = fabs(1 / plr()->ray_dir.x);
	plr()->delta_dist.y = fabs(1 / plr()->ray_dir.y);
	plr()->hit = 0;
}

void	step(void)
{
	if (plr()->ray_dir.x < 0)
	{
		plr()->stepx = -1;
		plr()->side_dist.x = (plr()->pos.x - plr()->mapx) * plr()->delta_dist.x;
	}
	else
	{
		plr()->stepx = 1;
		plr()->side_dist.x = (plr()->mapx + 1.0 \
		- plr()->pos.x) * plr()->delta_dist.x;
	}
	if (plr()->ray_dir.y < 0)
	{
		plr()->stepy = -1;
		plr()->side_dist.y = (plr()->pos.y - plr()->mapy) * plr()->delta_dist.y;
	}
	else
	{
		plr()->stepy = 1;
		plr()->side_dist.y = (plr()->mapy + 1.0 - plr()->pos.y) \
		* plr()->delta_dist.y;
	}
}

void	dda(void)
{
	while (plr()->hit == 0)
	{
		if (plr()->side_dist.x < plr()->side_dist.y)
		{
			plr()->side_dist.x += plr()->delta_dist.x;
			plr()->mapx += plr()->stepx;
			plr()->side = 0;
		}
		else
		{
			plr()->side_dist.y += plr()->delta_dist.y;
			plr()->mapy += plr()->stepy;
			plr()->side = 1;
		}
		if (map()->map[plr()->mapy][plr()->mapx] == '1')
			plr()->hit = 1;
	}
	if (plr()->side == 0)
		plr()->perp_wall_dist = plr()->side_dist.x - plr()->delta_dist.x;
	else
		plr()->perp_wall_dist = plr()->side_dist.y - plr()->delta_dist.y;
	if (plr()->perp_wall_dist < 0.0001)
		plr()->perp_wall_dist = 0.0001;
}
