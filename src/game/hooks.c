/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:18:22 by gsilva            #+#    #+#             */
/*   Updated: 2024/05/11 18:39:43 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	press(int keycode);
int	release(int keycode);
int	key_close(void);

int	press(int keycode)
{
	if (keycode == XK_Escape)
	{
		finish_exec();
		exit (0);
	}
	if (keycode == XK_w)
		plr()->key.w = 1;
	if (keycode == XK_a)
		plr()->key.a = 1;
	if (keycode == XK_s)
		plr()->key.s = 1;
	if (keycode == XK_d)
		plr()->key.d = 1;
	if (keycode == XK_Left)
		plr()->key.l = 1;
	if (keycode == XK_Right)
		plr()->key.r = 1;
	return (0);
}

int	release(int keycode)
{
	if (keycode == XK_w)
		plr()->key.w = 0;
	if (keycode == XK_a)
		plr()->key.a = 0;
	if (keycode == XK_s)
		plr()->key.s = 0;
	if (keycode == XK_d)
		plr()->key.d = 0;
	if (keycode == XK_Left)
		plr()->key.l = 0;
	if (keycode == XK_Right)
		plr()->key.r = 0;
	return (0);
}

int	key_close(void)
{
	finish_exec();
	exit(0);
}
