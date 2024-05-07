/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:31:14 by gsilva            #+#    #+#             */
/*   Updated: 2024/05/07 16:33:36 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

t_plr	*plr(void)
{
	static t_plr	_plr;

	return (&_plr);
}

t_mlx	*mlx(void)
{
	static t_mlx	_mlx;

	return (&_mlx);
}

t_win	*win(void)
{
	static t_win	_win;

	return (&_win);
}

t_map	*map(void)
{
	static t_map	_map;

	return (&_map);
}

int	main(int argc, char **argv)
{
	int	i;

	if (!check_ext(argv[1]))
	{
		ft_printf("Invalid map file extension\n");
		return (0);
	}
	mlx()->mlx = mlx_init();
	if (fill_map(argv[1]) == -1)
		ft_printf("Invalid map\n");
	else
	{
		start_game();
	}
	ft_printf("\n");
	return (0);
}
