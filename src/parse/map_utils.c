/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:48:39 by gsilva            #+#    #+#             */
/*   Updated: 2024/04/02 14:49:11 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

char	*fill_line(int fd)
{
	char	*line;
	char	*get_line;
	int		i;

	line = (char *)ft_calloc(sizeof(char), (map()->max_len + 1));
	get_line = get_next_line(fd);
	if (!get_line)
		return (NULL);
	i = -1;
	while (get_line[++i])
		line[i] = get_line[i];
	free(get_line);
	return (line);
}