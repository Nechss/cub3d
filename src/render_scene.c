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
	int	half_height;

	y = -1;
	half_height = HEIGHT >> 1;
	while (++y < half_height)
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

mlx_texture_t	*which_texture(t_cub *cub)
{
	mlx_texture_t	*texture;

	texture = NULL;
	if (cub->ray->direction == 'N')
		texture = cub->tex_n;
	if (cub->ray->direction == 'S')
		texture = cub->tex_s;
	if (cub->ray->direction == 'E')
		texture = cub->tex_e;
	if (cub->ray->direction == 'W')
		texture = cub->tex_w;
	return (texture);
}

void	render_wall(t_cub *cub, int ray_num, int y)
{
	mlx_texture_t	*texture;
	int				texture_x;
	int				texture_y;
	uint32_t		color;

	cub->ray->wall_height = (int)(cub->img->height / cub->ray->length);
	texture = which_texture(cub);
	if (cub->ray->direction == 'N' || cub->ray->direction == 'S')
		texture_x = (int)((cub->ray->x - (int)cub->ray->x) * texture->width);
	else
		texture_x = (int)((cub->ray->y - (int)cub->ray->y) * texture->width);
	while (++y < cub->ray->wall_height)
	{
		texture_y = (int)(y * texture->height / cub->ray->wall_height)
			% texture->height;
		color = get_texture_pixel(texture, texture_x, texture_y);
		draw_pixel(cub->img, ray_num,
			(cub->img->height >> 1) - (cub->ray->wall_height >> 1) + y, color);
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
