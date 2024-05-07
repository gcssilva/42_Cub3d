/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:56:41 by gsilva            #+#    #+#             */
/*   Updated: 2024/05/07 20:37:47 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	set_px(int i, int j, int color);
void	new_px_data(void);

void	set_px(int i, int j, int color)
{
	int	px;

	px = j * (win()->img->line_len / 4) + i;
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
	win()->px_data = NULL;
	win()->px_data = ft_calloc(481, sizeof(int *));
	i = -1;
	while (++i < 480)
		win()->px_data[i] = ft_calloc(641, sizeof(int));
}
