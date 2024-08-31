/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez-b <gperez-b@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:29:57 by gperez-b          #+#    #+#             */
/*   Updated: 2024/08/29 16:44:51 by mmaltas-         ###   ########.fr       */
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

# define WIDTH	1024
# define HEIGHT	768
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

typedef struct s_flags
{
	char	player;
	int		close_wall;
	int		empty_line;
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
	char			**map;
	t_flags			*flags;
}	t_parse;

//------------Init----------------//

void	set_win(t_cub *cub);

//------------Render----------------//

void	my_mlx_pixel_put(mlx_image_t *img, int x, int y, int color);
void	draw_pixel(mlx_image_t *img, int x, int y, int color);
void	render(t_cub *cub);
void	render_map(t_cub *cub);
void	render_scene(t_cub *cub);


//------------Events----------------//

void	events(t_cub *cub);
void	keyboard_in(mlx_key_data_t keydata, void* param);
void	move_event(t_cub *cub, float new_x, float new_y);
void	rotate_event(t_cub *cub);

//-------------Exit---------------//

void	destroy(void* param);
void	free_map(char **map);

//-------------Parsing---------------//

void	parsing_doc(char *map_doc, t_parse *parse);

#endif
