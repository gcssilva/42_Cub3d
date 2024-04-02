/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:19:22 by gsilva            #+#    #+#             */
/*   Updated: 2024/04/02 14:49:25 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	check_ext(char *file)
{
	if (ft_strlen(file) < 5)
		return (0);
	file += ft_strlen(file) - 4;
	if (!ft_strncmp(file, ".cub", 5))
		return (1);
	return (0);
}

int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 12) || c == 32)
		return (1);
	return (0);
}

int	fill_map(char *file)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	if (fill_el(file) == -1)
		return (-1);
	fd = open(file, O_RDONLY);
	while (i++ <= map()->last_elem)
	{
		line = get_next_line(fd);
		free(line);
	}
	map()->map = (char **)malloc(sizeof(char *) * (map()->lines + 1));
	i = -1;
	while (++i <= map()->lines)
		map()->map[i] = fill_line(fd);
	map()->map[i] = NULL;
	close(fd);
	map()->p = 0;
	return (parse_map());
}

int	is_valid_char(int c)
{
	if (c != '1' && c != '0' && c != 'W' && c != 'E'
		&& c != 'N' && c != 'S' && !ft_isspace(c))
		return (0);
	if (c == 'W' || c == 'E' || c == 'N' || c == 'S')
	{
		if (map()->p != 0)
			return (0);
		map()->p = c;
	}
	return (1);
}

int	parse_map(void)
{
	int	i;
	int	j;

	i = -1;
	while (map()->map[++i])
	{
		j = -1;
		while (map()->map[i][++j])
		{
			if (!is_valid_char(map()->map[i][j]))
				return (-1);
		}
	}
	if (map()->p == 0)
		return (-1);
	return (parse_path());
}
