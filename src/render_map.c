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

void	draw_line(mlx_image_t *img, t_line *line, int err, int e2)
{
	err = line->dx - line->dy;
	while (1)
	{
		draw_pixel(img, line->x0, line->y0, RED);
		if (line->x0 == line->ray_x && line->y0 == line->ray_y)
			return ;
		e2 = err;
		if (e2 > -line->dy)
		{
			err -= line->dy;
			if (line->x0 < line->ray_x)
				line->x0++;
			else
				line->x0--;
		}
		if (e2 < line->dx)
		{
			err += line->dx;
			if (line->y0 < line->ray_y)
				line->y0++;
			else
				line->y0--;
		}
	}
}

void	draw_fov(t_cub *cub, float ray_angle)
{
	int		i;
	int		num_rays;
	float	angle_step;
	t_line	line;

	num_rays = 128;
	angle_step = cub->fov_angle / num_rays;
	i = -1;
	while (++i < num_rays)
	{
		ray_angle = cub->player.angle - (cub->fov_angle / 2) + i * angle_step;
		line.x0 = cub->player.x * cub->tile_size;
		line.y0 = cub->player.y * cub->tile_size;
		line.ray_x = line.x0 + cos(ray_angle) * 60;
		line.ray_y = line.y0 + sin(ray_angle) * 60;
		line.dx = abs(line.ray_x - line.x0);
		line.dy = abs(line.ray_y - line.y0);
		draw_line(cub->img, &line, 0, 0);
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
	draw_fov(cub, 0);
}
