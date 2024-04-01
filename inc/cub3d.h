/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:31:25 by gsilva            #+#    #+#             */
/*   Updated: 2024/04/01 17:43:35 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft.h"

typedef struct s_map
{
	char	*elements[7];
	char	**map;
	int		l;
	int		lines;
	int		p;
}	t_map;

t_map	*map(void);

//parse_map
int		check_ext(char *file);
int		ft_isspace(int c);
int		fill_map(char *file);
int		parse_map(void);
int		is_valid_char(int c);

//parse_el
int		map_lines(int l);
int		el_filled(void);
int		add_el(char *s, int i, int l);
int		check_el(char *s, int l);
int		fill_el(char *file);

#endif