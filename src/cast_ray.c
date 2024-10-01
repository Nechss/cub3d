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

void	wall_hit(t_cub *cub, int step_x, int step_y, char *wall_hit_dir)
{
	if (cub->ray->side == 0)
	{
		if (step_x < 0)
			*wall_hit_dir = 'W';
		else
			*wall_hit_dir = 'E';
	}
	else
	{
		if (step_y < 0)
			*wall_hit_dir = 'N';
		else
			*wall_hit_dir = 'S';
	}
}

void	ray_hit(t_cub *cub, int step_x, int step_y, char *wall_hit_dir)
{
	while (!cub->ray->hit)
	{
		if (cub->ray->side_x < cub->ray->side_y)
		{
			cub->ray->side_x += cub->ray->delta_x;
			cub->ray->map_x += step_x;
			cub->ray->side = 0;
		}
		else
		{
			cub->ray->side_y += cub->ray->delta_y;
			cub->ray->map_y += step_y;
			cub->ray->side = 1;
		}
		if (cub->ray->map_x >= 0 && cub->ray->map_x < cub->map_width
			&& cub->ray->map_y >= 0 && cub->ray->map_y < cub->map_height
			&& cub->map[cub->ray->map_y][cub->ray->map_x] == '1')
		{
			cub->ray->hit = 1;
			wall_hit(cub, step_x, step_y, wall_hit_dir);
		}
	}
}

void	set_step(t_cub *cub, int *step_x, int *step_y)
{
	if (cub->ray->dir_x < 0)
	{
		*step_x = -1;
		cub->ray->side_x = (cub->player.x - cub->ray->map_x)
			* cub->ray->delta_x;
	}
	else
	{
		*step_x = 1;
		cub->ray->side_x = (cub->ray->map_x + 1.0 - cub->player.x)
			* cub->ray->delta_x;
	}
	if (cub->ray->dir_y < 0)
	{
		*step_y = -1;
		cub->ray->side_y = (cub->player.y - cub->ray->map_y)
			* cub->ray->delta_y;
	}
	else
	{
		*step_y = 1;
		cub->ray->side_y = (cub->ray->map_y + 1.0 - cub->player.y)
			* cub->ray->delta_y;
	}
}

void	init_ray(t_ray *ray, t_cub *cub)
{
	ray->map_x = (int)cub->player.x;
	ray->map_y = (int)cub->player.y;
	ray->hit = 0;
	ray->dir_x = cos(cub->ray->angle);
	ray->dir_y = sin(cub->ray->angle);
	ray->side = 0;
	ray->delta_x = fabs(1 / cub->ray->dir_x);
	ray->delta_y = fabs(1 / cub->ray->dir_y);
}

void	cast_ray(t_cub *cub, char *wall_hit_direction)
{
	int	step_x;
	int	step_y;

	init_ray(cub->ray, cub);
	set_step(cub, &step_x, &step_y);
	ray_hit(cub, step_x, step_y, wall_hit_direction);
	if (cub->ray->side == 0)
	{
		cub->ray->length = (cub->ray->map_x - cub->player.x + (1 - step_x) / 2)
			/ cub->ray->dir_x;
		cub->ray->x = cub->player.x + cub->ray->length * cub->ray->dir_x;
		cub->ray->y = cub->player.y + cub->ray->length * cub->ray->dir_y;
	}
	else
	{
		cub->ray->length = (cub->ray->map_y - cub->player.y + (1 - step_y) / 2)
			/ cub->ray->dir_y;
		cub->ray->x = cub->player.x + cub->ray->length * cub->ray->dir_x;
		cub->ray->y = cub->player.y + cub->ray->length * cub->ray->dir_y;
	}
	cub->ray->length = cos(cub->player.angle - cub->ray->angle)
		* cub->ray->length;
}
