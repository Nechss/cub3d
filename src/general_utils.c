#include "cub3D.h"

void	ft_exit(char *str)
{
	printf("%s\n", str);
	exit(EXIT_FAILURE);
}

void	free_words(char **rslt)
{
	int	i;

	i = 0;
	while (rslt[i])
	{
		free(rslt[i]);
		i++;
	}
	free(rslt);
}

void	print_parse(t_parse *parse)
{
	int i;

	i = 0;
	printf("Text_n = %s\n", parse->tex_n);
	printf("Text_s = %s\n", parse->tex_s);
	printf("Text_e = %s\n", parse->tex_e);
	printf("Text_w = %s\n", parse->tex_w);
	printf("Colors C = %d,%d,%d\n", parse->color_c[0], parse->color_c[1], parse->color_c[2]);
	printf("Colors F = %d,%d,%d\n", parse->color_f[0], parse->color_f[1], parse->color_f[2]);
	printf("Map width = %d\nMap height = %d\n\n", parse->map_width, parse->map_height);
	while(parse->map[i])
	{
		printf("-> %s\n", parse->map[i]);
		i++;
	}
}
