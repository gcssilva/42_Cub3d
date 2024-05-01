/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 19:48:58 by gsilva            #+#    #+#             */
/*   Updated: 2024/05/01 20:13:06 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	vert(int p)
{
	plr()->dir.x = 0;
	plr()->plane.x = 0.66;
	plr()->plane.y = 0;
	if (p == 'N')
		plr()->dir.y = 1;
	else
		plr()->dir.y = -1;
}

void	hor(int p)
{
	plr()->dir.y = 0;
	plr()->plane.x = 0;
	plr()->plane.y = 0.66;
	if (p == 'E')
		plr()->dir.x = 1;
	else
		plr()->dir.x = -1;
}

void	init_vars(void)
{
	if (map()->p == 'N' || map()->p == 'S')
		vert(map()->p);
	else
		hor(map()->p);
	plr()->pos.x = (double)plr()->mapX;
	plr()->pos.y = (double)plr()->mapY;
	plr()->hit = 0;
}
