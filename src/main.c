/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:31:14 by gsilva            #+#    #+#             */
/*   Updated: 2024/04/23 15:52:38 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

t_mlx	*mlx(void)
{
	static t_mlx	_mlx;

	return (&_mlx);
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
	if (fill_map(argv[1]) == -1)
		ft_printf("Invalid map\n");
	else
	{
		i = -1;
		while (map()->map[++i])
			ft_printf("%s", map()->map[i]);
	}
	ft_printf("\n");
	return (0);
}
