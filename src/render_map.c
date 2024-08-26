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

void draw_line(mlx_image_t *img, int x0, int y0, int x1, int y1)
{
	int dx;
    int dy;
	int err;
	int e2;

	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	err = dx - dy;
	while (1)
	{
		draw_pixel(img, x0, y0, RED);
		if (x0 == x1 && y0 == y1)
			return;
		e2 = err;
		if (e2 > -dy)
		{
			err -= dy;
			if (x0 < x1)
				x0++;
			else
				x0--;
 		}
		if (e2 < dx)
		{
			err += dx;
			if (y0 < y1)
				y0++;
			else
				y0--;
		}
	}
}

void	draw_fov(t_cub *cub, float ray_x, float ray_y, float ray_angle)
{
	int		i;
	int		num_rays;
	float	angle_step;

	i = -1;
	num_rays = 100;
	angle_step = cub->fov_angle / num_rays;
	while (++i < num_rays)
	{
		ray_angle = cub->player.angle - (cub->fov_angle / 2) + i * angle_step;
		ray_x = (cub->player.x * cub->tile_size) + cos(ray_angle) * 60;
		ray_y = (cub->player.y * cub->tile_size) + sin(ray_angle) * 60;
		draw_line(cub->img, cub->player.x * cub->tile_size,
			cub->player.y * cub->tile_size, ray_x, ray_y);
	}
}

void	draw_player(mlx_image_t *img, int xc, int yc, uint32_t color)
{
	int	x;
	int	y;
	int	r;

	r = 5;
	y = -r;
	while (y <= r)
	{
		x = -r;
		while (x <= r)
		{
			if (x * x + y * y <= r * r)
				draw_pixel(img, xc + x, yc + y, color);
			x++;
		}
		y++;
	}
}

void	draw_rectangle(t_cub *cub, int x, int y, uint32_t color)
{
	int	i;
	int	j;
	int	height;
	int	width;

	i = 0;
	width = cub->tile_size;
	height = width;
	while (i < width)
	{
		j = 0;
		while (j < height)
		{
			draw_pixel(cub->img, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	render_map(t_cub *cub)
{
	int	ts;
	int	color;
	int	y;
	int	x;

	ts = cub->tile_size;
	y = 0;
	while (y < cub->map_height)
	{
		x = 0;
		while (x < cub->map_width)
		{
			color = WHITE;
			if (cub->map[y][x] == '1')
				color = BLACK;
			draw_rectangle(cub, x * ts, y * ts, color);
			x++;
		}
		y++;
	}
	draw_player(cub->img, cub->player.x * ts, cub->player.y * ts, BLUE);
	draw_fov(cub, cub->player.x * ts, cub->player.y * ts, RED);
}
