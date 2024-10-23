/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:58:16 by crocha-s          #+#    #+#             */
/*   Updated: 2024/10/23 16:26:57 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/mlx/mlx.h"
# include "../lib/mlx/mlx_int.h"
# include "../lib/libft/libft.h"
# include <assert.h>
# include <stdbool.h>
# include <math.h>

# define BUFF 50
# define NBR_TEXTURES 4
# define DIRECTIONS "NO,SO,EA,WE"
# define COLOR_PLACE "F ,C "
# define WIDTH 800
# define HEIGHT 600
# define SPRITE_SIZE 64
# define SPEED 20
# define ROTATION_SPEED 20
# define BUFFER_DISTANCE 0.1

# define PI 3.14159265358

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363

# define NO 0
# define SO 1
# define EA 2
# define WE 3
# define F 	4
# define C 	5

# define SPEED 0.025

typedef struct s_coord
{
	double	x;
	double	y;
}	t_coord;

typedef struct s_dda
{
	double		camera_x;
	t_coord		ray_dir;
	t_coord		delta_dist;
	t_coord		side_dist;
	t_coord		map_pos;
	t_coord		step;
	int			hit;
	int			side;
	double		perp_wall_dist;
}	t_dda;

typedef struct s_plane
{
	t_coord		pos;
	double		angle;
}	t_plane;

typedef struct s_player
{
	char	fov; // field of view
	t_coord	dir;
	t_plane	plane;
	t_coord movement;
	double	move_speed;
	double	rot_speed;
	int		img_index;
	double	hit_dist;
	double	hit_x;
	int		pitch;
	t_coord	pos;
	double		angle;
	int			int_pos_x;
	int			int_pos_y;
}	t_player;

typedef struct s_map
{
	char	**map_matrix;
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	int		floor[3];
	int		ceiling[3];
	int		f_color;
	int		c_color;
	int		n_lines;
	int		width;
}	t_map;

typedef struct s_image
{
	void		*img_ptr;
	char		*address;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_image;

typedef struct s_render
{
	t_image		image;
	int			height;
	int			width;
	int			index;
}	t_render;

typedef struct s_img_info
{
	double		line_height;
	int			draw_start;
	int			draw_end;
	double		pos_texture;
	double		scale;
	int			tex_x;
}	t_img_info;

typedef struct s_rays
{
	t_coord		direction;
	t_coord		delta;
	t_coord		intersection;
	t_coord		map_mov;
	bool		hit_vertical;
	double		perp_wall_dist;
}	t_rays;

typedef struct s_game
{
	char		*file;
	t_map		*map;
	t_player	*player;
}	t_game;

int		check_and_parse(t_game *game, char **path);
int		convert_data_map(t_game *game, char *temp_raw_map);
int		check_tex_path(t_game *game, char **path);
int		parse_map_matrix(char** map_line, t_game *game);
int		flood_fill(char **map_line, t_game *game);
char	getchr(const char *s, int c);
void		free_structs(t_game *game);
void	free_arr(char **arr);
int		ft_print_err(char *err);
void	player_direction(t_game *game);
void	free_arr(char **arr);
int		arr_len(char **arr);
#endif
