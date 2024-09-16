/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez-b <gperez-b@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 20:36:48 by gperez-b          #+#    #+#             */
/*   Updated: 2024/09/16 19:52:41 by mmaltas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int count_rows(char **argv)
{
	int	i;

	i = 0;
	while(argv[i])
		i++;
	return (i);
}
/*
int		count_spaces(char *str)
{
	int	i;
	int spaces;
	int checked;

	i = 0;
	spaces = 0;
	checked = 0;
	while(str[i] && !checked)
	{
		while(str[i] == ' ')
		{
			i++;
			spaces++;
			checked = 1;
		}
		i++;
		if (i > 3)
			break;
	}
	return (spaces);
}
*/

char	*trim_spaces(char *str)
{
	printf("trim_str = %s\n", str);
	char *temp;

	temp = str;
	temp = ft_strtrim(temp, " ");
	//ft_strlcpy(str, temp, ft_strlen(str));
	printf("TRIMED_str =%s\n", temp);
	return (temp);
}
/*void	read_map(t_parse *parse)
{
	char	*line;
	int		i;
	int		j;
}*/

void	parse_texture(char *line, t_parse *parse)
{
	char *temp;

	temp = trim_spaces(line + 2);	
	printf("tex_line = %s\n", temp);
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

void	check_if_is_num(char *str)
{
	printf("color = %s\n", str);
	int i;

	i = 0;	
	if (str[0] == '-')
		i++;
	while(str[i])
	{
		//printf("char_color = %c\n", str[i]);
		if (ft_isdigit(str[i]))
			i++;
		else
			ft_exit("Invalid color paramater");
	}
}
void	check_limits(char *str)
{
	if (ft_strlen(str) > 3)
		ft_exit("Number too long");
	if (str[0] == '-')
		ft_exit("Invalid negative number");
}

void	convert_num_color(char **colors, int color_x[3])
{
	int	i;

	i = 0;
//	check_color_format
	while (colors[i])
	{
		check_if_is_num(colors[i]);
		check_limits(colors[i]);
		color_x[i] = ft_atoi(colors[i]);
		if (color_x[i] > 255)
			color_x[i] = 255;
		if (color_x[i] < 0)
			color_x[i] = 0;
		i++;
	}
	//color_x[i] = ;
}

void	parse_color(char *line, t_parse *parse)
{
	char	**colors;
	int		option;
	//int		i;

	colors = NULL;
	option = 0;
	//i = 0;
	if (line[0] == 'F')
		option = 1;
	else if (line[0] == 'C')
		option = 2;
	line = trim_spaces(line + 1);
	//line += (1 + count_spaces(line));
	printf("line space color = %s\n", line);
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

int check_first_char(char *str, int i)
{
	while(str[i] && str[i] == ' ')
		i++;
	if(!str[i])
		return (-1);
	if (str[i] && str[i] != '1')
		ft_exit("Incorrect map at begining wall");
	return (i);
}

int check_last_char(char *str, int i)
{
	while(str[i])
		i++;
	i--;
	while(str[i] && str[i] == ' ')
		i--;
	if (str[i] != '1')
		ft_exit("Incorrect map at finish wall");
	return (i);
}

void check_char_type(char *str, int i)
{
	if(str[i] != '0' && str[i] != '1' && str[i] != 'N' \
	&& str[i] != 'S' && str[i] != 'E' && str[i] != 'W' \
	&& str[i] != ' ')  
		ft_exit("Incorrect map: bad caracter");	
}

int check_wall(char *str, t_parse *parse, int i)
{
	if(parse->flags->close_wall == 0 && str[i] != '1')
		ft_exit("Incorrect map: bad wall");
	else if (str[i] == '1')
	{
		parse->flags->close_wall = 1;
		if (parse->map_width < i)
			parse->map_width = i;
	}
	if (str[i] && str[i] == ' ')
	{
		if(str[i + 1] != '1')
			ft_exit("Incorrect map: bad wall en el hueco");
		parse->flags->close_wall = 0;
		while(str[i] && str[i] == ' ')
			i--;
		i++;
	}
	i--;
	return (i);
}

t_maplist *create_node(char *line)
{
    t_maplist *new_node;

    new_node = (t_maplist *)malloc(sizeof(t_maplist));
    if (!new_node)
        return NULL;
    new_node->line = ft_strdup(line);
    new_node->next = NULL;
    return new_node;
}

void add_node(char *line, t_maplist **head)
{
    t_maplist *new_node;
    t_maplist *temp;

	new_node = create_node(line);
	if (!new_node)
        return;
    if (*head == NULL)
		*head = new_node;
	else
	{
        temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_node;
    }
}

int	parse_line_map(char *str, t_parse *parse)
{
	int	i;
	int	j;
	int	last_char;

	i = 0;
	parse->flags->close_wall = 0;
    i = check_first_char(str, i);
	if (i == -1)
		return(-1);
	j = i;
	i = check_last_char(str, i);
	last_char = i;
	while(i > j)
	{
		check_char_type(str, i);
		i = check_wall(str, parse, i);
	}
	return (last_char);
}


void	parse_map(char *line, t_parse *parse, t_maplist **head)
{
	int last_char;

	if (!parse->tex_n || !parse->tex_s || !parse->tex_e || !parse->tex_w) 
		ft_exit("Failed to load texture");
	last_char = parse_line_map(line, parse);
	if(last_char >= 0 && parse->flags->finish_map != 1)
	{
		last_char++;
		line[last_char] = '\0';
		add_node(line, head);
	}
	else if (parse->flags->finish_map != 1)
		parse->flags->finish_map = 1;
	else
		ft_exit("EMpty line detected\n");
}

void	check_line(char *line, t_parse *parse, t_maplist **head)
{
//	printf("check_line = %s\n", line);
	if (line[0] == 'N' || line[0] == 'S' || line[0] == 'E' || line[0] == 'W')
		parse_texture(line, parse);
	else if(line[0] == 'F' || line[0] == 'C')
		parse_color(line, parse);
	else
		parse_map(line, parse, head);
}


void	init_struct(t_parse *parse)
{
	parse->tex_n = NULL;
	parse->tex_s = NULL;
	parse->tex_e = NULL;
	parse->tex_w = NULL;
	parse->color_c[0] = 0;
	parse->color_c[1] = 0;
	parse->color_c[2] = 0;
	parse->color_f[0] = 0;
	parse->color_f[1] = 0;
	parse->color_f[2] = 0;
	parse->map_width = 0;
	parse->map_height= 0;
	parse->map = NULL;
}

int	map_height(t_maplist **head)
{
	t_maplist	*temp;
	int			height;

	temp = *head;
	height = 0;
	while(temp->next)
	{
		temp = temp->next;
		height++;
	}
	return (height + 1);
}

void fill_map(t_parse *parse, t_maplist **head)
{
	t_maplist	*temp;
	int			i;
	size_t		len;

	temp = *head;
	i = 0;
	parse->map_width = 0;
	while(i < parse->map_height)
	{
		len = ft_strlen(temp->line);
		if (parse->map_width < (int)len)
			parse->map_width = (int)len;
		parse->map[i] = (char *)malloc((len + 1) * sizeof(char));
		if (!parse->map[i])
			ft_exit("Error de malloc 2");
		if (ft_strlcpy(parse->map[i], temp->line, len + 1) != len)
			ft_exit("Error in ft_strlcpy");
		temp = temp->next;
		i++;
	}
}

void create_map(t_parse *parse, t_maplist **head)
{
	int			height;

	height = map_height(head);
	parse->map = (char **)malloc((height + 1) * sizeof(char *));
	if (!parse->map)
		ft_exit("Error de malloc");
	parse->map[height] = NULL;
	parse->map_height = height;
	fill_map(parse, head);
}

void vetical_parse_map(t_parse *parse)
{
	int		y;
	int		x;
	char	**map;

	y = 0;
	x = 0;
	map = parse->map;

	while(x < parse->map_width)
	{
		y = 0;
		while(y < parse->map_height)
		{
			if (map[y][x] == ' ')
			{
				if (y == 0)
				{
					while(map[y][x] == ' ')
						y++;

					if (map[y][x] != '1')
						printf("Error 1 wall open in vertilcal parse in x = %d y = %d    map[x][y] = %c\n", x, y, map[y][x]);
					else
					{
						if (map[y][x + 1] == '0')
							printf("Error 2 wall open in vertilcal parse in x = %d y = %d\n", x + 1, y);
					}
				}
				else
				{
				
					//printf("map[x][y] = %c\n", map[y][x]);
					if (map[y - 1][x + 1] != '1' && map[y - 1][x + 1] != ' ')
						printf("Error 3 wall open in vertilcal parse in x = %d y = %d    map[x][y] = %c\n", x, y, map[y][x]);
				}
				//while (map[x][y] && map[x][y] != ' ')
				//	y++;
			}
			else
			{
				printf("[%d][%d] / ", x, y);
				y++;
			}
		}
		x++;
	}
}

void	parsing_doc(char *map_doc, t_parse *parse, t_maplist **head)
{
	char *line;
	char *clean_line;
	int		fd;

	init_struct(parse);
	fd = (open(map_doc, O_RDONLY));
	if (fd  == -1)
		ft_exit("Failed to read document .cub");	
	while(1)
	{
		line = get_next_line(fd);
		if(!line)
			break;
		if(!strcmp(line, "\n"))
		{
			free(line);
			continue;
		}
		clean_line = ft_strtrim(line, "\n");
		check_line(clean_line, parse, head);
		free(line);
		free(clean_line);
	}
	create_map(parse, head);
	vetical_parse_map(parse);
//	check_info_parsed(parse);
	print_parse(parse);
	exit(0);
}
