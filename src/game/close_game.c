/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:20:57 by gsilva            #+#    #+#             */
/*   Updated: 2024/05/12 01:08:40 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	close_map(void);
void	close_imgs(t_img *img);
void	finish_exec(void);

void	close_map(void)
{
	int	i;

	i = -1;
	while (++i < 6)
	{
		if (map()->elements[i])
			free(map()->elements[i]);
	}
	i = -1;
	while (map()->map && map()->map[++i])
		free(map()->map[i]);
	if (map()->map)
		free(map()->map);
}

void	close_imgs(t_img *img)
{
	if (img)
	{
		free(img->px_data);
		free(img);
	}
}

void	finish_exec(void)
{
	int	i;

	close_map();
	close_imgs(mlx()->n);
	close_imgs(mlx()->s);
	close_imgs(mlx()->e);
	close_imgs(mlx()->w);
	if (win()->img)
	{
		mlx_destroy_image(mlx()->mlx, win()->img->img);
		free(win()->img);
		i = -1;
		while (++i < 480)
			free(win()->px_data[i]);
		free(win()->px_data);
	}
	if (mlx()->win)
		mlx_destroy_window(mlx()->mlx, mlx()->win);
	mlx_destroy_display(mlx()->mlx);
	free(mlx()->mlx);
}
