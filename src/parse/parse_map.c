/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:19:22 by gsilva            #+#    #+#             */
/*   Updated: 2024/03/21 17:03:44 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	check_ext(char *file)
{
	if (ft_strlen(file) < 5)
		return (0);
	*file += ft_strlen(file) - 4;
	if (!ft_strncmp(file, ".cub", 5))
		return (1);
	return (0);
}

int	read_map(char *file)
{
	char	*line;
	int		fd;

	fd = open(file, O_WRONLY);
	if (fd < 0)
		return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
	}
}
