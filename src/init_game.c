/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaltas <mmaltas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:30:25 by mmaltas           #+#    #+#             */
/*   Updated: 2024/10/28 14:30:29 by mmaltas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	set_game(t_cub *cub, t_parse *p)
{
	cub->map = p->map;
	cub->map_height = p->map_height;
	cub->map_width = p->map_width;
	cub->color_f = p->color_f[2] << 16 | p->color_f[1] << 8 | p->color_f[0];
	cub->color_c = p->color_c[2] << 16 | p->color_c[1] << 8 | p->color_c[0];
	cub->fov_angle = 5 * M_PI / 12;
	if (cub->map_height > cub->map_width)
		cub->tile_size = (HEIGHT / 3) / cub->map_height;
	else
		cub->tile_size = (WIDTH / 3) / cub->map_width;
	cub->player.x = p->position[1] + 0.5;
	cub->player.y = p->position[0] + 0.5;
	if (p->player == 'E')
		cub->player.angle = 0;
	else if (p->player == 'W')
		cub->player.angle = M_PI;
	else if (p->player == 'N')
		cub->player.angle = 3 * M_PI_2;
	else if (p->player == 'S')
		cub->player.angle = M_PI_2;
}

void	set_win(t_cub *f)
{
	f->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	if (!f->mlx)
	{
		printf("Failed to initialize window\n");
		exit(EXIT_FAILURE);
	}
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->img)
	{
		printf("Failed to create new image\n");
		mlx_terminate(f->mlx);
		exit(EXIT_FAILURE);
	}
	ft_memset(f->img->pixels, 0, WIDTH * HEIGHT * sizeof(uint32_t));
	mlx_image_to_window(f->mlx, f->img, 0, 0);
}

void	set_textures(t_parse *parse, t_cub *cub)
{
	cub->tex_n = mlx_load_png(parse->tex_n);
	cub->tex_s = mlx_load_png(parse->tex_s);
	cub->tex_e = mlx_load_png(parse->tex_e);
	cub->tex_w = mlx_load_png(parse->tex_w);
	if (!cub->tex_n || !cub->tex_s || !cub->tex_e || !cub->tex_w)
	{
		printf("Failed to load texture\n");
		exit(EXIT_FAILURE);
	}
}
