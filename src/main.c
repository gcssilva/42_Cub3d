/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:31:14 by gsilva            #+#    #+#             */
/*   Updated: 2024/03/21 17:11:04 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	if (!check_ext(argv[1]))
		return (0);
	win = mlx_new_window(mlx, 200, 200, argv[1]);
	while (1)
	{
		continue ;
	}
	return (0);
}
