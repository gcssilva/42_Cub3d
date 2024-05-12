/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:31:25 by gsilva            #+#    #+#             */
/*   Updated: 2024/05/12 01:12:32 by gsilva           ###   ########.fr       */
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
	int		mapx;
	int		mapy;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall;
	double	cam;
	double	perp_wall_dist;
	t_coord	pos;
	t_coord	dir;
	t_coord	plane;
	t_coord	ray_dir;
	t_coord	delta_dist;
	t_coord	side_dist;
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

//parse/ parse_map.c
int		fill_map(char *file);
char	*fill_line(int fd);
int		is_valid_char(int c);
int		parse_map(void);

//parse/ map_utils.c
int		rgb_char(char *s);
int		get_code(char *code, int id);
int		check_rgb(char *code, int id);

//parse/ parse_path.c
int		parse_path(void);
int		inv_path(int c);
int		find_path(int y, int x);

//parse/ parse_el
int		el_filled(void);
int		add_el(char *s, int i, int l);
int		check_el(char *s, int l);
int		fill_el(char *file, int l);
int		aux_el(char *file);

//parse/ parse_utils.c
int		map_lines(int l);
int		check_ext(char *file);
int		ft_isspace(int c);
int		ft_strlen_nl(char *str);
int		error(char *str);

//image/ image.c
void	init_px_data(void);
void	img_px_data(t_img *img, int size);
t_img	*create_img(char *path);
int		check_img(void);
void	create_scene(void);

//game/ utils.c
void	walk_ns(int flag);
void	walk_ew(int flag);
void	rotate(int flag);
t_img	*tex_calc(void);
void	set_scene(t_img *img, int x);

//game/ ray_cast.c
int		main_loop(void);
void	raycast(void);
void	get_pos(int x);
void	step(void);
void	dda(void);

//game/ hooks.c
int		press(int keycode);
int		release(int keycode);
int		key_close(void);

//game/ init_vars.c
void	vert(int p);
void	hor(int p);
void	init_vars(void);
void	start_game(void);
void	paint_scene(void);

//game/ utils2.c
void	set_px(int x, int y, int color);
void	new_px_data(void);
int		*aux_get_add(void);

//game/ close_game.c
void	close_map(void);
void	close_imgs(t_img *img);
void	finish_exec(void);

#endif