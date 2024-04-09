/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:37:48 by gsilva            #+#    #+#             */
/*   Updated: 2024/04/09 16:37:38 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	create_img(void)
{
	int	size;

	size = 64;
	mlx()->mlx = mlx_init();
	mlx()->no_tex = mlx_xpm_file_to_image(mlx()->mlx, map()->elements[0], &size, &size);
	mlx()->so_tex = mlx_xpm_file_to_image(mlx()->mlx, map()->elements[1], &size, &size);
	mlx()->ea_tex = mlx_xpm_file_to_image(mlx()->mlx, map()->elements[2], &size, &size);
	mlx()->we_tex = mlx_xpm_file_to_image(mlx()->mlx, map()->elements[3], &size, &size);
}

int	check_img(void)
{
	create_img();
	if (!mlx()->no_tex || !mlx()->so_tex || !mlx()->ea_tex || !mlx()->we_tex)
		return (-1);
	return (0);
}
