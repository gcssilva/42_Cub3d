/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:56:41 by gsilva            #+#    #+#             */
/*   Updated: 2024/05/10 13:51:09 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	set_px(int x, int y, int color);
void	new_px_data(void);
int		*aux_get_add(void);

void	set_px(int x, int y, int color)
{
	int	px;

	px = y * (win()->img->line_len / 4) + x;
	win()->img->addr[px] = color;
}

void	new_px_data(void)
{
	int	i;

	i = -1;
	while (win()->px_data && win()->px_data[++i])
		free(win()->px_data[i]);
	if (win()->px_data)
		free(win()->px_data);
	(win()->px_data) = NULL;
	(win()->px_data) = ft_calloc(481, sizeof(int *));
	i = -1;
	while (++i < 480)
		(win()->px_data[i]) = ft_calloc(641, sizeof(int));
}

int	*aux_get_add(void)
{
	return ((int *)mlx_get_data_addr(win()->img->img, \
		&win()->img->bpp, &win()->img->line_len, &win()->img->endian));
}
