/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaltas <mmaltas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:32:26 by mmaltas           #+#    #+#             */
/*   Updated: 2024/11/08 16:32:43 by mmaltas-         ###   ########.fr       */
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

void	check_arg(char *argv)
{
	int	len;

	len = ft_strlen(argv);
	if (len <= 4 || ft_strncmp(argv + len - 4, ".cub", 4))
		ft_exit("Error invalid document");
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
		printf("Usage: ./cub3D <map.cub>\n");
		exit(EXIT_FAILURE);
	}
	check_arg(argv[1]);
	parsing_doc(argv[1], &parse, &tok_list);
	set_textures(&parse, &cub);
	set_win(&cub);
	set_game(&cub, &parse);
	render(&cub);
	events(&cub);
	mlx_loop(cub.mlx);
	exit (0);
}
