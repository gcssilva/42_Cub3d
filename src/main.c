/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:31:14 by gsilva            #+#    #+#             */
/*   Updated: 2024/04/01 17:16:23 by gsilva           ###   ########.fr       */
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
	int	i;

	if (!check_ext(argv[1]))
		ft_printf("Invalid map file extension\n");
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
