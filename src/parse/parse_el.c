/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_el.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:33:45 by gsilva            #+#    #+#             */
/*   Updated: 2024/04/29 16:17:48 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	map_lines(int l);
int	el_filled(void);
int	add_el(char *s, int i, int l);
int	check_el(char *s, int l);
int	fill_el(char *file);

int	map_lines(int l)
{
	map()->lines = l - map()->last_elem;
	return (0);
}

int	el_filled(void)
{
	int	i;

	i = -1;
	while (++i < 6)
	{
		if (!map()->elements[i] || !map()->elements[i][0])
			return (0);
	}
	return (1);
}

int	add_el(char *s, int i, int l)
{
	if (i > 6)
	{
		if (!el_filled())
			return (-1);
		return (0);
	}
	if (i == 6)
		return (0);
	if (map()->elements[i])
		return (-1);
	s += 2;
	while (ft_isspace(*s))
		s++;
	map()->elements[i] = ft_strdup(s);
	map()->elements[i][ft_strlen(s) - 1] = 0;
	map()->last_elem = l;
	return (0);
}

int	check_el(char *s, int l)
{
	int	i;

	i = 10;
	while (ft_isspace(*s))
		*s++;
	if (!ft_strncmp(s, "NO ", 3))
		i = 0;
	else if (!ft_strncmp(s, "SO ", 3))
		i = 1;
	else if (!ft_strncmp(s, "EA ", 3))
		i = 2;
	else if (!ft_strncmp(s, "WE ", 3))
		i = 3;
	else if (!ft_strncmp(s, "F ", 2))
		i = 4;
	else if (!ft_strncmp(s, "C ", 2))
		i = 5;
	else if (*s == 0)
		i = 6;
	return (add_el(s, i, l));
}

int	fill_el(char *file)
{
	char	*line;
	int		fd;
	int		l;

	l = -1;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			if (el_filled())
				return (map_lines(l));
			return (-1);
		}
		if (ft_strlen(line) > map()->max_len)
			map()->max_len = ft_strlen(line);
		if (check_el(line, ++l) == -1)
		{
			free(line);
			return (-1);
		}
	}
	return (0);
}
