/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:31:25 by gsilva            #+#    #+#             */
/*   Updated: 2024/04/02 14:45:30 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft.h"
# include "../mlx/mlx.h"

typedef struct s_map
{
	char	*elements[7];
	char	**map;
	int		last_elem;
	int		lines;
	int		max_len;
	int		p;
}	t_map;

t_map	*map(void);

//parse_map
int		check_ext(char *file);
int		ft_isspace(int c);
int		fill_map(char *file);
int		parse_map(void);
int		is_valid_char(int c);

//map_utils
char	*fill_line(int fd);

//parse_path
int		parse_path(void);
int		find_path(int y, int x);

//parse_el
int		map_lines(int l);
int		el_filled(void);
int		add_el(char *s, int i, int l);
int		check_el(char *s, int l);
int		fill_el(char *file);

#endif