/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaltas <mmaltas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:32:26 by mmaltas           #+#    #+#             */
/*   Updated: 2024/10/28 16:10:48 by mmaltas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_pixel(mlx_image_t *img, int x, int y, int color)
{
	uint32_t	*pixel;

	if (x >= 0 && (uint32_t)x < img->width && y >= 0
		&& (uint32_t)y < img->height)
	{
		pixel = (uint32_t *)(img->pixels + (y * img->width + x)
				* sizeof(uint32_t));
		*pixel = (color & 0xFFFFFF) | 0xFF000000;
	}
}

void	render(t_cub *cub)
{
	render_scene(cub);
	render_map(cub);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	main(int argc, char **argv)
{
	t_cub		cub;
	t_parse		parse;
	t_flags		flags;
	t_maplist	*tok_list;

	parse.flags = &flags;
	tok_list = NULL;
	if (argc != 2)
	{
		parse.flags->close_wall = 4;
		printf("Usage: ./cub3D <map.cub>\nflag wall == %d\n", flags.close_wall);
		exit(EXIT_FAILURE);
	}
	parsing_doc(argv[1], &parse, &tok_list);
	set_textures(&parse, &cub);
	set_win(&cub);
	set_game(&cub, &parse);
	render(&cub);
	events(&cub);
	mlx_loop(cub.mlx);
	return (0);
}
