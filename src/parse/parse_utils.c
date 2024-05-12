/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:12:41 by mneves-l          #+#    #+#             */
/*   Updated: 2024/05/10 14:00:38 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	map_lines(int l);
int	check_ext(char *file);
int	ft_isspace(int c);
int	ft_strlen_nl(char *str);
int	error(char *str);

int	map_lines(int l)
{
	map()->lines = l - map()->last_elem;
	return (0);
}

int	check_ext(char *file)
{
	if (ft_strlen(file) < 5)
		return (0);
	file += ft_strlen(file) - 4;
	if (!ft_strncmp(file, ".cub\0", 5))
		return (1);
	return (0);
}

int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 12) || c == 32)
		return (1);
	return (0);
}

int	ft_strlen_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	error(char *str)
{
	ft_putendl_fd("Error:", 2);
	ft_putendl_fd(str, 2);
	return (-1);
}
