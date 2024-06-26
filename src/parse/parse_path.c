/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:54:00 by gsilva            #+#    #+#             */
/*   Updated: 2024/05/12 01:09:37 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	parse_path(void);
int	inv_path(int c);
int	find_path(int y, int x);

int	parse_path(void)
{
	int	i;
	int	j;

	i = -1;
	while (map()->map[++i])
	{
		j = -1;
		while (map()->map[i][++j])
		{
			if (map()->map[i][j] == '0' || map()->map[i][j] == 'W'
				|| map()->map[i][j] == 'E'
				|| map()->map[i][j] == 'N' || map()->map[i][j] == 'S')
				if (find_path(i, j) == -1)
					return (error("Map is not close"));
		}
	}
	return (0);
}

int	inv_path(int c)
{
	if ((c >= 9 && c <= 12) || c == 32 || !c)
		return (1);
	return (0);
}

int	find_path(int y, int x)
{
	if (y == 0 || x == 0 || y == (map()->lines - 1)
		|| x == (map()->max_len - 1))
		return (-1);
	if (inv_path(map()->map[y - 1][x]) || inv_path(map()->map[y][x - 1])
		|| inv_path(map()->map[y + 1][x]) || inv_path(map()->map[y][x + 1]))
		return (-1);
	return (0);
}
