/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaltas <mmaltas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:32:42 by mmaltas           #+#    #+#             */
/*   Updated: 2024/10/28 17:26:40 by mmaltas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	parse_texture(char *line, t_parse *parse)
{
	char	*temp;

	line[ft_strlen(line) - 1] = '\0';
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
	char	*temp;

	colors = NULL;
	option = 0;
	if (line[0] == 'F')
		option = 1;
	else if (line[0] == 'C')
		option = 2;
	line[ft_strlen(line) - 1] = '\0';
	temp = trim_spaces(line + 1);
	colors = ft_split(temp, ',');
	if (count_rows(colors) != 3)
		ft_exit("Bad color format");
	if (option == 1)
		convert_num_color(colors, parse->color_f);
	else if (option == 2)
		convert_num_color(colors, parse->color_c);
	free_words(colors);
	free(temp);
}

static void	parse_map(char *line, t_parse *parse, t_maplist **head)
{
	char	*new_line;

	if (!parse->tex_n || !parse->tex_s || !parse->tex_e || !parse->tex_w)
		ft_exit("Error texture map ocurred / Check the .cub file");
	if (ft_strncmp(line, "\t", ft_strlen(line)))
	{
		new_line = parse_tabs(line);
		line = new_line;
	}
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	parse_line_map(line, parse);
	add_node(line, head);
	free(line);
}

void	check_line(char *line, t_parse *parse, t_maplist **head)
{
	if (line[0] == 'N' || line[0] == 'S' || line[0] == 'E' || line[0] == 'W')
		parse_texture(line, parse);
	else if (line[0] == 'F' || line[0] == 'C')
		parse_color(line, parse);
	else if (line[0] == '1' || line[0] == ' ' || \
	line[0] == '\n' || line[0] == '\t')
	{
		parse->flags->init_map = 1;
		parse_map(line, parse, head);
	}
	else
		ft_exit("Error: map error format");
}
