/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:31:14 by gsilva            #+#    #+#             */
/*   Updated: 2024/03/22 16:45:07 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

t_map	*map(void)
{
	static t_map	_map;

	return (&_map);
}

int	main(int argc, char **argv)
{
	if (!check_ext(argv[1]))
		ft_printf("Invalid map file extension\n");
	if (fill_el(argv[1]) == -1)
		ft_printf("Invalid map elements\n");
	else
		ft_printf("Map ok\n");
	return (0);
}
