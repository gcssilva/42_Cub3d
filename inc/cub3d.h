/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:31:25 by gsilva            #+#    #+#             */
/*   Updated: 2024/04/29 14:48:52 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft.h"
# include "../mlx/mlx.h"

typedef struct s_img
{
	int		w;
	int		*addr;
	int		*px_data;
	int		bpp;
	int		line_len;
	int		endian;
	void	*img;
}	t_img;

typedef struct s_map
{
	char	*elements[7];
	char	**map;
	int		last_elem;
	int		lines;
	int		max_len;
	int		p;
	int		c_rgb[3];
	int		f_rgb[3];
}	t_map;

typedef struct s_win
{
	int		**px_data;
	t_img	*img;
}	t_win;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_img	*n;
	t_img	*s;
	t_img	*e;
	t_img	*w;
}	t_mlx;

t_win	*win(void);
t_mlx	*mlx(void);
t_map	*map(void);

//parse_map
int		check_ext(char *file);
int		ft_isspace(int c);
int		fill_map(char *file);
int		is_valid_char(int c);
int		parse_map(void);

//map_utils
char	*fill_line(int fd);
int		rgb_char(char *s);
int		get_code(char *code, int id);
int		check_rgb(char *code, int id);

//parse_path
int		parse_path(void);
int		inv_path(int c);
int		find_path(int y, int x);

//parse_el
int		map_lines(int l);
int		el_filled(void);
int		add_el(char *s, int i, int l);
int		check_el(char *s, int l);
int		fill_el(char *file);

//image.c
void	init_px_data(void);
void	img_px_data(t_img *img, int size);
t_img	*create_img(char *path);
int		check_img(void);
void	create_scene(void);

#endif