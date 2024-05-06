/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:55:36 by gsilva            #+#    #+#             */
/*   Updated: 2024/05/06 19:42:19 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	walk_ns(int flag);
void	walk_ew(int flag);
void	rotate(int flag);

void	walk_ns(int flag)
{
	t_coord pos;

	if (flag == 1)
	{
		pos.x = plr()->pos.x + plr()->dir.x * 0.05;
		pos.y = plr()->pos.y + plr()->dir.y * 0.05;
	}
	else
	{
		pos.x = plr()->pos.x - plr()->dir.x * 0.05;
		pos.y = plr()->pos.y - plr()->dir.y * 0.05;
	}
	if (map()->map[(int)floor(pos.y)][(int)floor(pos.x)] == '1')
		return ;
	if (map()->map[(int)(plr()->pos.y + plr()->dir.y * 0.05)][(int)plr()->pos.x] != '1')
		plr()->pos.y += plr()->dir.y * 0.05 * flag;
	if (map()->map[(int)plr()->pos.y][(int)(plr()->pos.x + plr()->dir.x * 0.05)] != '1')
		plr()->pos.x += plr()->dir.x * 0.05 * flag;
}

void	walk_ew(int flag)
{
	t_coord pos;

	if (flag == 1)
	{
		pos.x = plr()->pos.x + plr()->plane.x * 0.05;
		pos.y = plr()->pos.y + plr()->plane.y * 0.05;
	}
	else
	{
		pos.x = plr()->pos.x - plr()->plane.x * 0.05;
		pos.y = plr()->pos.y - plr()->plane.y * 0.05;
	}
	if (map()->map[(int)floor(pos.y)][(int)floor(pos.x)] == '1')
		return ;
	if (map()->map[(int)(plr()->pos.y + plr()->plane.y * 0.05)][(int)plr()->pos.x] != '1')
		plr()->pos.y += plr()->plane.y * 0.05 * flag;
	if (map()->map[(int)plr()->pos.y][(int)(plr()->pos.x + plr()->plane.x * 0.05)] != '1')
		plr()->pos.x += plr()->plane.x * 0.05 * flag;
}

void	rotate(int flag)
{
	double	tmp_dir;
	double	tmp_plane;

	tmp_dir = plr()->dir.x;
	tmp_plane = plr()->plane.x;
	plr()->dir.x = plr()->dir.x * cos(flag * 0.04) - plr()->dir.y * sin(flag * 0.04);
	plr()->dir.y = tmp_dir * sin(flag * 0.04) + plr()->dir.y * cos(flag * 0.04);
	plr()->plane.x = plr()->plane.x * cos(flag * 0.04) - plr()->plane.y * sin(flag * 0.04);
	plr()->plane.y = tmp_plane * sin(flag * 0.04) + plr()->plane.y * cos(flag * 0.04);
}

void	tex_calc(void)
{
	plr()->lineHeight = (int)(640 / plr()->perpWallDist);
	plr()->drawStart = -plr()->lineHeight / 2 + 640 / 2;
	if (plr()->drawStart < 0)
		plr()->drawStart = 0;
	plr()->drawEnd = plr()->lineHeight / 2 + 640 / 2;
	if (plr()->drawEnd >= 640)
		plr()->drawEnd = 640 - 1;
	if (plr()->side == 0)
		plr()->wall = plr()->pos.y + plr()->perpWallDist * plr()->rayDir.y;
	else
		plr()->wall = plr()->pos.x + plr()->perpWallDist * plr()->rayDir.x;
	plr()->wall -= floor(plr()->wall);
}
