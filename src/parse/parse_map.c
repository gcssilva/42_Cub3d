/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:19:22 by gsilva            #+#    #+#             */
/*   Updated: 2024/03/22 16:34:03 by gsilva           ###   ########.fr       */
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

