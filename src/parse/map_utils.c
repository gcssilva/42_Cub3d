/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:48:39 by gsilva            #+#    #+#             */
/*   Updated: 2024/05/11 17:57:46 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int		rgb_char(char *s);
int		get_code(char *code, int id);
int		check_rgb(char *code, int id);

int	rgb_char(char *s)
{
	s += 2;
	while (*s)
	{
		if (!ft_isspace(*s) && !ft_isdigit(*s) && *s != ',')
			return (-1);
	}
	return (0);
}

int	get_code(char *code, int id)
{
	int	*rgb;

	if (id == 'F')
		rgb = map()->f_rgb;
	else
		rgb = map()->c_rgb;
	rgb[0] = ft_atoi(code);
	while (*code != ',')
		code++;
	code++;
	rgb[1] = ft_atoi(code);
	while (*code != ',')
		code++;
	code++;
	rgb[2] = ft_atoi(code);
	if (rgb[0] > 255 || rgb[1] > 255 || rgb[2] > 255)
		return (-1);
	return (0);
}

int	check_rgb(char *code, int id)
{
	int	i;
	int	comma;
	int	digit;

	i = -1;
	comma = 0;
	digit = 0;
	while (code[++i])
	{
		if (!ft_isdigit(code[i]) && code[i] != ',')
			return (-1);
		if (code[i] == ',' && ++comma)
		{
			if (!digit || comma > 2 || !code[i + 1])
				return (-1);
			digit = 0;
		}
		else if (ft_isdigit(code[i]) && ++digit)
			if (digit == 4)
				return (-1);
	}
	if (comma != 2)
		return (-1);
	return (get_code(code, id));
}
