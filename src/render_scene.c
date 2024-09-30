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
int	ray_hit(t_cub *cub, int *side, int step_x, int step_y)
{
	int hit = 0;

	while (!hit)
	{
		if (cub->ray->side_x < cub->ray->side_y)
		{
			cub->ray->side_x += cub->ray->delta_x;
			cub->ray->map_x += step_x;
			*side = 0;
		}
		else
		{
			cub->ray->side_y += cub->ray->delta_y;
			cub->ray->map_y += step_y;
			*side = 1;
		}

		// Check for a wall hit
		if (cub->ray->map_x >= 0 && cub->ray->map_x < cub->map_width && cub->ray->map_y >= 0 && cub->ray->map_y < cub->map_height && cub->map[cub->ray->map_y][cub->ray->map_x] == '1')
		{
			hit = 1;
		}
	}
	return hit;
}


void cast_ray(t_cub *cub, char *wall_hit_direction)
{
	int	step_x;
	int	step_y;

    cub->ray->map_x = (int)cub->player.x;
    cub->ray->map_y = (int)cub->player.y;
	cub->ray->dir_x = cos(cub->ray->angle);
    cub->ray->dir_y = sin(cub->ray->angle);
	cub->ray->delta_x = fabs(1 / cub->ray->dir_x);
    cub->ray->delta_y = fabs(1 / cub->ray->dir_y);
	if (cub->ray->dir_x < 0)
    {
        step_x = -1;
        cub->ray->side_x = (cub->player.x - cub->ray->map_x) * cub->ray->delta_x;
    }
    else
    {
        step_x = 1;
        cub->ray->side_x = (cub->ray->map_x + 1.0 - cub->player.x) * cub->ray->delta_x;
    }

    if (cub->ray->dir_y < 0)
    {
        step_y = -1;
        cub->ray->side_y = (cub->player.y - cub->ray->map_y) * cub->ray->delta_y;
    }
    else
    {
        step_y = 1;
        cub->ray->side_y = (cub->ray->map_y + 1.0 - cub->player.y) * cub->ray->delta_y;
    }
	int hit = 0;
	int side = 0;
	//ray_hit(cub, &side, step_x, step_y);
    while (!hit)
    {
        if (cub->ray->side_x < cub->ray->side_y)
        {
            cub->ray->side_x += cub->ray->delta_x;
            cub->ray->map_x += step_x;
            side = 0;
        }
        else
        {
            cub->ray->side_y += cub->ray->delta_y;
            cub->ray->map_y += step_y;
            side = 1;
        }

        if (cub->ray->map_x >= 0 && cub->ray->map_x < cub->map_width && cub->ray->map_y >= 0 && cub->ray->map_y < cub->map_height && cub->map[cub->ray->map_y][cub->ray->map_x] == '1')
        {
            hit = 1;
            if (side == 0)
                *wall_hit_direction = (step_x < 0) ? 'W' : 'E';
            else
                *wall_hit_direction = (step_y < 0) ? 'N' : 'S';
        }
    }

	if (side == 0)
    {
        cub->ray->length = (cub->ray->map_x - cub->player.x + (1 - step_x) / 2) / cub->ray->dir_x;
        cub->ray->x = cub->player.x + cub->ray->length * cub->ray->dir_x;  // Save exact hit X
        cub->ray->y = cub->player.y + cub->ray->length * cub->ray->dir_y;  // Save exact hit Y
    }
    else
    {
        cub->ray->length = (cub->ray->map_y - cub->player.y + (1 - step_y) / 2) / cub->ray->dir_y;
        cub->ray->x = cub->player.x + cub->ray->length * cub->ray->dir_x;  // Save exact hit X
        cub->ray->y = cub->player.y + cub->ray->length * cub->ray->dir_y;  // Save exact hit Y
    }
	cub->ray->length = cos(cub->player.angle - cub->ray->angle)
				* cub->ray->length;
}

// void	cast_ray(t_cub *cub, char *wall_hit_direction)
// {
// 	int		map_x;
// 	int		map_y;

// 	cub->ray->length = 0;
// 	cub->ray->x = cub->player.x;
// 	cub->ray->y = cub->player.y;
// 	while (1)
// 	{
// 		cub->ray->x += RAY_STEP * cos(cub->ray->angle);
// 		cub->ray->y += RAY_STEP * sin(cub->ray->angle);
// 		cub->ray->length += RAY_STEP;
// 		map_x = (int)(cub->ray->x);
// 		map_y = (int)(cub->ray->y);
// 		if (cub->ray->length > 1000)
// 			break ;
// 		if (map_x >= 0 && map_x < cub->map_width && map_y >= 0
// 			&& map_y < cub->map_height && cub->map[map_y][map_x] == '1')
// 		{
// 			which_wall(wall_hit_direction, cub->ray->x - map_x,
// 				cub->ray->y - map_y);
			// cub->ray->length = cos(cub->player.angle - cub->ray->angle)
			// 	* cub->ray->length;
// 			if (cub->ray->angle > 0 && cub->ray->angle < 1)
// 				printf("cub->ray->length: %f\n", cub->ray->length);
// 			break ;
// 		}
// 	}
// }

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
