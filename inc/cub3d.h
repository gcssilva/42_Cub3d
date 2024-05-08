/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:31:25 by gsilva            #+#    #+#             */
/*   Updated: 2024/05/08 13:30:18 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <math.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "libft.h"
# include "../mlx/mlx.h"

typedef struct s_keys
{
	int	w;
	int	s;
	int	d;
	int	a;
	int	l;
	int	r;
}	t_keys;

typedef struct s_coord
{
	double	x;
	double	y;
}	t_coord;

typedef struct s_plr
{
	t_keys	key;
	int		mapX;
	int		mapY;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	double	wall;
	double	cam;
	double	perpWallDist;
	t_coord	pos;
	t_coord	dir;
	t_coord	plane;
	t_coord	rayDir;
	t_coord	deltaDist;
	t_coord	sideDist;
}	t_plr;

typedef struct s_img
{
	int		w;
	int		*addr;
	int		*px_data;
	int		bpp;
	int		line_len;
	int		endian;
	int		x;
	int		y;
	double	step;
	double	pos;
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
	t_img	**tex;
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

t_plr	*plr(void);
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

//utils.c
void	walk_ns(int flag);
void	walk_ew(int flag);
void	rotate(int flag);
t_img	*tex_calc(void);
void	set_scene(t_img *img, int x);

//ray_cast.c
int		main_loop(void);
void	raycast(void);
void	get_pos(int x);
void	step(void);
void	dda(void);

//hooks.c
int		press(int keycode);
int		release(int keycode);

//init_vars.c
void	vert(int p);
void	hor(int p);
void	init_vars(void);
void	start_game(void);
void	paint_scene(void);

//utils2.c
void	set_px(int x, int y, int color);
void	new_px_data(void);

#endif