#include "cub3D.h"

static void	parse_texture(char *line, t_parse *parse)
{
	char	*temp;
	temp = trim_spaces(line + 2);
	if (line[0] == 'N' && line[1] == 'O')
		parse->tex_n = ft_strdup(temp);
	else if (line[0] == 'S' && line[1] == 'O')
		parse->tex_s = ft_strdup(temp);
	else if (line[0] == 'E' && line[1] == 'A')
		parse->tex_e = ft_strdup(temp);
	else if (line[0] == 'W' && line[1] == 'E')
		parse->tex_w = ft_strdup(temp);
	free(temp);
}

static void	parse_color(char *line, t_parse *parse)
{
	char	**colors;
	int		option;

	colors = NULL;
	option = 0;
	if (line[0] == 'F')
		option = 1;
	else if (line[0] == 'C')
		option = 2;
	line = trim_spaces(line + 1);
	colors = ft_split(line, ',');
	if (count_rows(colors) != 3)
		ft_exit("Bad color format");
	if (option == 1)
		convert_num_color(colors, parse->color_f);
	else if (option == 2)
		convert_num_color(colors, parse->color_c);
	free_words(colors);
	free(line);
}

static void	parse_map(char *line, t_parse *parse, t_maplist **head)
{
	int		last_char;
	char	*new_line;

	printf("aqui line = %s\n", line);
	if (!parse->tex_n || !parse->tex_s || !parse->tex_e || !parse->tex_w)
		ft_exit("Error texture map ocurred / Check the .cub file");
	
	if (strcmp(line, "\t"))
	{
		new_line = parse_tabs(line);
		line = new_line;
	}
	last_char = parse_line_map(line, parse);
	if (last_char >= 0 && parse->flags->finish_map != 1)
	{
		last_char++;
		line[last_char] = '\0';
		add_node(line, head);
	}
	else if (parse->flags->finish_map != 1)
		parse->flags->finish_map = 1;
	else
		ft_exit("Empty line detected\n");
}

void	check_line(char *line, t_parse *parse, t_maplist **head)
{
	if (line[0] == 'N' || line[0] == 'S' || line[0] == 'E' || line[0] == 'W')
		parse_texture(line, parse);
	else if (line[0] == 'F' || line[0] == 'C')
		parse_color(line, parse);
	else if (line[0] == '1' || line[0] == ' ' || line[0] == '\t')
	{
		parse->flags->init_map = 1;
		parse_map(line, parse, head);
	}
	else
		ft_exit("Some error map ocurred / Check the .cub file");
}
