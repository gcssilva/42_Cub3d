/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:31:25 by gsilva            #+#    #+#             */
/*   Updated: 2024/03/22 16:40:32 by gsilva           ###   ########.fr       */
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
}	t_map;

t_map	*map(void);

//parse_map
int		check_ext(char *file);
int		ft_isspace(int c);

//parse_el
int		el_filled(void);
int		add_el(char *s, int i);
int		check_el(char *s);
int		fill_el(char *file);

#endif