/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaltas <mmaltas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:29:57 by gperez-b          #+#    #+#             */
/*   Updated: 2024/10/28 14:26:02 by mmaltas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "./mlx/include/MLX42/MLX42.h"
# include "libft.h"

# define WIDTH	1280
# define HEIGHT	960
# define MOVE_SPEED 0.08
# define ROTATE_SPEED 0.05

# define BLACK  0x00000000
# define BLUE   0x00FF0000
# define GREEN  0x0000FF00
# define RED    0x000000FF
# define WHITE  0x00FFFFFF

# define ESC		256
# define LEFT		263
# define RIGHT		262
# define DOWN		264
# define UP			265
# define WKEY		87
# define SKEY		83
# define AKEY		65
# define DKEY		68



typedef struct 
{
    int				x;
    int				y;
    mouse_key_t 	button;
    action_t 		action;
    modifier_key_t	mods;
} mouse_event_t;

typedef struct s_ray
{
	float	x;
	float	y;
	int		map_x;
	int		map_y;
	float	angle;
	float	length;
	char	direction;
	int		wall_height;
	int		hit;
	int		hit_x;
	float	dir_x;
	float	dir_y;
	int		side;
	float	side_x;
	float	side_y;
	float	delta_x;
	float	delta_y;
} t_ray;

typedef struct s_coor
{
	float x;
	float y;
	float angle;
} t_coor;

typedef struct s_cub
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_texture_t	*tex_n;
	mlx_texture_t	*tex_s;
	mlx_texture_t	*tex_e;
	mlx_texture_t	*tex_w;
	char			**map;
	int				map_width;
	int				map_height;
	int				tile_size;
	int				color_f;
	int				color_c;
	t_coor			player;
	float			fov_angle;
	t_ray			*ray;
	int	ignore;
}	t_cub;

typedef struct s_line
{
	int	x0;
	int	y0;
	int		ray_x;
	int		ray_y;
	float	dx;
	float	dy;
	float	angle;
} t_line;

typedef struct s_flags
{
	char	player;
	int		close_wall;
	int		empty_line;
	int		finish_map;
	int		init_map;
}	t_flags;

typedef struct s_parse
{
	char			*tex_n;
	char			*tex_s;
	char			*tex_e;
	char			*tex_w;
	int				color_c[3];
	int				color_f[3];
	int				map_width;
	int				map_height;
	char			player;
	int				position[2];
	char			**map;
	t_flags			*flags;
}	t_parse;

typedef struct s_maplist
{
    char			*line;
    struct s_maplist *next;
    struct s_maplist *prev;
}	t_maplist;

//------------Init----------------//

void	set_textures(t_parse *parse, t_cub *cub);
void	set_win(t_cub *cub);
void	set_game(t_cub *cub, t_parse *parse);

//------------Render----------------//

void	my_mlx_pixel_put(mlx_image_t *img, int x, int y, int color);
void	draw_pixel(mlx_image_t *img, int x, int y, int color);
void	render(t_cub *cub);
void	render_map(t_cub *cub);
void	render_scene(t_cub *cub);
void	cast_ray(t_cub *cub, char *wall_hit_direction);

//------------Events----------------//

void	events(t_cub *cub);
void	keyboard_in(mlx_key_data_t keydata, void* param);
void	move_event(t_cub *cub, float new_x, float new_y);
void	rotate_event(t_cub *cub);

//-------------Exit---------------//

void	destroy(void* param);
void	free_map(char **map);
void	ft_exit(char *str);
void	free_words(char **rslt);
void	free_parse(t_parse *parse);

//-------------Parsing---------------//

void	parsing_doc(char *map_doc, t_parse *parse, t_maplist **tok_list);
int		parse_line_map(char *str, t_parse *parse);
void	convert_num_color(char **colors, int color_x[3]);
char	*trim_spaces(char *str);
int		count_rows(char **argv);
void	create_map(t_parse *parse, t_maplist **head);
void	check_line(char *line, t_parse *parse, t_maplist **head);
void	add_node(char *line, t_maplist **head);
void	init_struct(t_parse *parse);
void	vetical_parse_map(t_parse *parse);
void	parse_player(t_parse *parse);
char	*parse_tabs(char *line);
void	clean_empty_nodes(t_maplist **head);

//-------------TEMPORAL---------------//
void	print_parse(t_parse *parse);

#endif
