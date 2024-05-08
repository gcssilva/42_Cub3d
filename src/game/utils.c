/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:55:36 by gsilva            #+#    #+#             */
/*   Updated: 2024/05/08 17:39:55 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	walk_ns(int flag);
void	walk_ew(int flag);
void	rotate(int flag);
t_img	*tex_calc(void);
void	set_scene(t_img *img, int x);

void	walk_ns(int flag)
{
	t_coord pos;

	if (flag == 1)
	{
		if (map()->map[(int)plr()->pos.y][(int)(plr()->pos.x + plr()->dir.x * 0.005)] != '1')
			plr()->pos.x += plr()->dir.x * 0.005;
		if (map()->map[(int)(plr()->pos.y + plr()->dir.y * 0.005)][(int)plr()->pos.x] != '1')
			plr()->pos.y += plr()->dir.y * 0.005;
	}
	else
	{
		if (map()->map[(int)plr()->pos.y][(int)(plr()->pos.x - plr()->dir.x * 0.005)] != '1')
			plr()->pos.x -= plr()->dir.x * 0.005;
		if (map()->map[(int)(plr()->pos.y - plr()->dir.y * 0.005)][(int)plr()->pos.x] != '1')
			plr()->pos.y -= plr()->dir.y * 0.005;
	}
}

void	walk_ew(int flag)
{
	t_coord pos;

	if (flag == 1)
	{
		if (map()->map[(int)plr()->pos.y][(int)(plr()->pos.x + plr()->plane.x * 0.05)] != '1')
			plr()->pos.x += plr()->plane.x * 0.05;
		if (map()->map[(int)(plr()->pos.y + plr()->plane.y * 0.05)][(int)plr()->pos.x] != '1')
			plr()->pos.y += plr()->plane.y * 0.05;
	}
	else
	{
		if (map()->map[(int)plr()->pos.y][(int)(plr()->pos.x - plr()->plane.x * 0.05)] != '1')
			plr()->pos.x -= plr()->plane.x * 0.05;
		if (map()->map[(int)(plr()->pos.y - plr()->plane.y * 0.05)][(int)plr()->pos.x] != '1')
			plr()->pos.y -= plr()->plane.y * 0.05;
	}
}

void	rotate(int flag)
{
	double	tmp_dir;
	double	tmp_plane;

	tmp_dir = plr()->dir.x;
	tmp_plane = plr()->plane.x;
	plr()->dir.x = plr()->dir.x * cos(flag * 0.03) - plr()->dir.y * sin(flag * 0.03);
	plr()->dir.y = tmp_dir * sin(flag * 0.03) + plr()->dir.y * cos(flag * 0.03);
	plr()->plane.x = plr()->plane.x * cos(flag * 0.03) - plr()->plane.y * sin(flag * 0.03);
	plr()->plane.y = tmp_plane * sin(flag * 0.03) + plr()->plane.y * cos(flag * 0.03);
}

t_img	*tex_calc(void)
{
	plr()->lineHeight = (int)(480 / plr()->perpWallDist);
	plr()->drawStart = -plr()->lineHeight / 2 + 480 / 2;
	if (plr()->drawStart < 0)
		plr()->drawStart = 0;
	plr()->drawEnd = plr()->lineHeight / 2 + 480 / 2;
	if (plr()->drawEnd >= 480)
		plr()->drawEnd = 480 - 1;
	if (plr()->side == 0)
		plr()->wall = plr()->pos.y + plr()->perpWallDist * plr()->rayDir.y;
	else
		plr()->wall = plr()->pos.x + plr()->perpWallDist * plr()->rayDir.x;
	plr()->wall -= floor(plr()->wall);
	if (plr()->side && plr()->rayDir.y <= 0)
		return (mlx()->n);
	if (plr()->side && plr()->rayDir.y > 0)
		return (mlx()->s);
	if (!plr()->side && plr()->rayDir.x >= 0)
		return (mlx()->e);
	if (!plr()->side && plr()->rayDir.x < 0)
		return (mlx()->w);
	return (NULL);
}

void	set_scene(t_img *img, int x)
{
	int	y;
	
	img->x = (int)(plr()->wall * img->w);
	if ((!plr()->side && plr()->rayDir.x < 0) || (plr()->side && plr()->rayDir.y > 0))
		img->x = img->w - img->x - 1;
	img->step = 1.0 * img->w / plr()->lineHeight;
	img->pos = (plr()->drawStart - 480 / 2 + plr()->lineHeight / 2) * img->step;
	y = plr()->drawStart;
	while (y < plr()->drawEnd)
	{
		img->y = (int)img->pos & (img->w - 1);
		img->pos += img->step;
		if (img->px_data[img->w * img->y + img->x] > 0)
			win()->px_data[y][x] = img->px_data[img->w * img->y + img->x];
		y++;
	}
}
