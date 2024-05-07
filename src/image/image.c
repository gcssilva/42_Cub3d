/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:37:48 by gsilva            #+#    #+#             */
/*   Updated: 2024/05/07 20:12:19 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	init_px_data(void);
void	img_px_data(t_img *img, int size);
t_img	*create_img(char *path);
int		check_img(void);
void	create_scene(void);

void	init_px_data(void)
{
	int	i;
	
	i = -1;
	win()->px_data = ft_calloc(641, sizeof(int *));
	while (++i < 640)
		win()->px_data[i] = ft_calloc(641, sizeof(int));
}

void	img_px_data(t_img *img, int size)
{
	int	x;
	int	y;

	img->px_data = ft_calloc(1, sizeof(int) * size * size);
	y = -1;
	while (++y < size)
	{
		x = -1;
		while (++x < size)
			img->px_data[y * size + x] = img->addr[y * size + x];
	}
}

t_img	*create_img(char *path)
{
	int		size;
	void	*mlx_img;
	t_img	*img;

	size = 64;
	mlx_img = mlx_xpm_file_to_image(mlx()->mlx, path, &size, &size);
	if (!mlx_img)
		return (0);
	img = (t_img *)malloc(sizeof(t_img));
	img->addr = (int *)mlx_get_data_addr(mlx_img, &img->bpp, &img->line_len, &img->endian);
	img_px_data(img, size);
	img->w = size;
	return (img);
}

int	check_img(void)
{
	mlx()->n = create_img(map()->elements[0]);
	mlx()->s = create_img(map()->elements[1]);
	mlx()->e = create_img(map()->elements[2]);
	mlx()->w = create_img(map()->elements[3]);
	if (!mlx()->n || !mlx()->s || !mlx()->e || !mlx()->w)
		return (-1);
	return (0);
}

void	create_scene(void)
{
	win()->img->img = mlx_new_image(mlx()->mlx, 640, 640);
	win()->img->addr = (int *)mlx_get_data_addr(win()->img->img, &win()->img->bpp, &win()->img->line_len, &win()->img->endian);
	win()->img->w = 640;
}
