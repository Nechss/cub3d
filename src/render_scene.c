/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez-b <gperez-b@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 20:43:13 by gperez-b          #+#    #+#             */
/*   Updated: 2024/02/29 19:47:39 by gperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

uint32_t	get_texture_pixel(mlx_texture_t *texture, int x, int y)
{
	int	offset;

	x = x % texture->width;
	y = y % texture->height;
	offset = (y * texture->width + x) * 4;
	return (*(uint32_t *)(texture->pixels + offset));
}

void	render_floor_ceiling(t_cub *cub)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT / 2)
	{
		x = 0;
		while (x < WIDTH)
		{
			draw_pixel(cub->img, x, y, cub->color_c);
			x++;
		}
	}
	while (++y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			draw_pixel(cub->img, x, y, cub->color_f);
			x++;
		}
	}
}

void	cast_ray(t_cub *cub, char *wall_hit_direction)
{
	int		map_x;
	int		map_y;
	float	hit_x;
	float	hit_y;

	cub->ray->length = 0;
	cub->ray->x = cub->player.x;
	cub->ray->y = cub->player.y;
	while (1)
	{
		cub->ray->x += 0.005 * cos(cub->ray->angle);
		cub->ray->y += 0.005 * sin(cub->ray->angle);
		cub->ray->length += 0.005;
		map_x = (int)(cub->ray->x);
		map_y = (int)(cub->ray->y);
		if (cub->ray->length > 1000)
			break;
		if (map_x >= 0 && map_x < cub->map_width && map_y >= 0
			&& map_y < cub->map_height && cub->map[map_y][map_x] == '1')
		{
			hit_x = cub->ray->x - map_x;
			hit_y = cub->ray->y - map_y;
			if (fabs(hit_x - 0.5) > fabs(hit_y - 0.5)) 
			{
				if (hit_x < 0.5)
					*wall_hit_direction = 'W';
				else
					*wall_hit_direction = 'E';
			}
			else 
			{
				if (hit_y < 0.5)
					*wall_hit_direction = 'N';
				else
					*wall_hit_direction = 'S';
			}
			break;
		}
	}
}

void	render_wall(t_cub *cub, int ray_num, int y)
{
	mlx_texture_t	*texture;
	int				texture_x;
	int				texture_y;
	uint32_t		color;

	texture = NULL;
	cub->ray->wall_height = (int)(cub->img->height / cub->ray->length);
	if (cub->ray->direction == 'N')
		texture = cub->tex_n;
	if (cub->ray->direction == 'S')
		texture = cub->tex_s;
	if (cub->ray->direction == 'E')
		texture = cub->tex_e;
	if (cub->ray->direction == 'W')
		texture = cub->tex_w;
	if (cub->ray->direction == 'N' || cub->ray->direction == 'S')
		texture_x = (int)((cub->ray->x - (int)cub->ray->x) * texture->width);
	else
		texture_x = (int)((cub->ray->y - (int)cub->ray->y) * texture->width);
	while (++y < cub->ray->wall_height)
	{
		texture_y = (int)(y * texture->height / cub->ray->wall_height) % texture->height;
		color = get_texture_pixel(texture, texture_x, texture_y);
		draw_pixel(cub->img, ray_num, (cub->img->height / 2) - (cub->ray->wall_height / 2) + y, color);
	}
}

void	render_scene(t_cub *cub)
{
	int		i;
	int		num_rays;
	float	angle_step;
	t_ray	ray;


	i = -1;
	num_rays = cub->img->width;
	angle_step = cub->fov_angle / num_rays;
	cub->ray = &ray;
	render_floor_ceiling(cub);
	while (++i < num_rays)
	{
		ray.angle = cub->player.angle - (cub->fov_angle / 2) + i * angle_step;
		cast_ray(cub, &ray.direction);
		render_wall(cub, i, -1);
	}
	cub->ray = NULL;
}

// void	render_scene(t_cub *cub)
// {
// 	int		i;
// 	int		num_rays;
// 	float	angle_step;
// 	t_ray	ray;
// 	t_ray	tmp;
// 	t_ray	tmp2;

// 	i = 0;
// 	num_rays = cub->img->width;
// 	angle_step = cub->fov_angle / num_rays;
// 	cub->ray = &ray;
// 	render_floor_ceiling(cub);
// 	while (i < num_rays)
// 	{
// 		ray.angle = cub->player.angle - (cub->fov_angle / 2) + i * angle_step;
// 		cast_ray(cub, &ray.direction);
// 		render_wall(cub, i, -1);
// 		if (tmp.length)
// 		{
// 			tmp2 = ray;
// 			ray.angle = (ray.angle + tmp.angle) / 2;
// 			ray.length = (ray.length + tmp.length) / 2;
// 			render_wall(cub, i - 1, -1);
// 			ray = tmp2;
// 		}
// 		tmp = ray;
// 		i += 2;
// 	}
// }
