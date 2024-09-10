
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

void	init_map(t_cub *cub)
{

	cub->fov_angle = 5 * M_PI / 12;
	if (cub->map_height > cub->map_width)
		cub->tile_size = (HEIGHT / 3) / cub->map_height;
	else
		cub->tile_size = (WIDTH / 3) / cub->map_width;
	cub->player.x = 4;
	cub->player.y = 5;
	cub->player.angle = 0;
	cub->color_c = 0xFF00aa;
	cub->color_f = 0xaaaaaa;
}

void	get_textures(t_cub *cub)
{
	cub->tex_n = mlx_load_png("./textures/rockwall.png");
	cub->tex_s = mlx_load_png("./textures/rockwall.png");
	cub->tex_e = mlx_load_png("./textures/rockwall.png");
	cub->tex_w = mlx_load_png("./textures/rockwall_red.png");
	if (!cub->tex_n || !cub->tex_s || !cub->tex_e || !cub->tex_w)
	{
		printf("Failed to load texture\n");
		mlx_terminate(cub->mlx);
		free_map(cub->map);
		exit(EXIT_FAILURE);
	}
}

void	get_map(t_cub *cub, char *path)
{
	int		fd;
	char	**map;
	int		i;

	map = (char **)malloc(sizeof(char *) * 100);
	fd = open(path, O_RDONLY);
	if (fd < 0 || !map)
	{
		printf("Failed to initialize map\n");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (1)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
			break ;
		i++;
	}
	map[i] = NULL;
	close(fd);
	cub->map = map;
	cub->map_height = i;
	cub->map_width = ft_strlen(map[0]) - 1;
	init_map(cub);
}

void set_win(t_cub *f)
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

int	main(int argc, char **argv)
{
	t_cub	cub;
	t_parse parse;
	t_flags flags;
	t_maplist *tok_list;

	parse.flags = &flags;
	tok_list = NULL;
	if (argc != 2)
	{
		parse.flags->close_wall = 4;
		printf("Usage: ./cub3D <map.cub>\nflag wall == %d\n", flags.close_wall);
		exit(EXIT_FAILURE);
	}
	parsing_doc(argv[1], &parse, &tok_list); 
	set_win(&cub);
	get_map(&cub, argv[1]);
	get_textures(&cub);
	render(&cub);
	events(&cub);
	mlx_loop(cub.mlx);
	return (0);
}
