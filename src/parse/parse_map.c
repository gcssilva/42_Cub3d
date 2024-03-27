/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:19:22 by gsilva            #+#    #+#             */
/*   Updated: 2024/03/27 21:45:07 by gsilva           ###   ########.fr       */
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

int	parse_map(char *file)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	if (fill_el(file) == -1)
		return (-1);
	fd = open(file, O_RDONLY);
	while (i <= map()->l)
	{
		line = get_next_line(fd);
		free(line);
	}
	while (1)
	{
		line
	}
}
