/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez-b <gperez-b@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 20:36:48 by gperez-b          #+#    #+#             */
/*   Updated: 2024/09/22 12:11:30 by mmaltas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


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

int map_width(t_maplist **head)
{
	t_maplist	*temp;
	size_t		width;

	temp = *head;
	width = 0;
	while (temp->next)
	{
		if (width < ft_strlen(temp->line))
			width = ft_strlen(temp->line);
		temp = temp->next;
	}
	return (width);
}

void fill_map(t_parse *parse, t_maplist **head)
{
	t_maplist	*temp;
	int			i;
	size_t		len;

	temp = *head;
	i = 0;
	printf("widht = %d\n", parse->map_width);
	while(i < parse->map_height)
	{
		len = ft_strlen(temp->line);
		parse->map[i] = (char *)malloc((parse->map_width + 1) * sizeof(char));
		if (!parse->map[i])
			ft_exit("Error de malloc 2");
		parse->map[i][parse->map_width] = '\0';
		ft_memset(parse->map[i], ' ', parse->map_width);
		if (ft_memcpy(parse->map[i], temp->line, len) == 0)
			ft_exit("Error in ft_strlcpy");
		printf("line = %s\n", parse->map[i]);
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
	parse->map_width = map_width(head);
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

	printf("map[1][5] = %c\n\n", map[1][4]);
	printf("W = %d\nH = %d\n", parse->map_width, parse->map_height);
	while(x < parse->map_width)
	{
		y = 0;
		while(y < parse->map_height)
		{
			printf("[%d][%d] / \n", y, x);
			if (map[y][x] && map[y][x] == ' ')
			{
				printf("ES ESPACIO\n");
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
					if (map[y][x + 1] && (map[y - 1][x + 1] != '1' && map[y - 1][x + 1] != ' ')) 
						printf("Error 3 wall open in vertilcal parse in x = %d y = %d    map[x][y] = %c\n", x, y, map[y][x]);
					if (map[y + 1] && (map[y + 1][x] == '0')) 
						printf("Error 4 wall open in vertilcal parse in x = %d y = %d    map[x][y] = %c\n", x, y, map[y][x]);
					if (map[y - 1] && map[y - 1][x] == '0')
						printf("Error 5 wall open in vertilcal parse in x = %d y = %d    map[x][y] = %c\n", x, y, map[y][x]);
					if ((x > 0 && map[y + 1]) && (map[y + 1][x - 1] == '0'))
						printf("Error 6 wall open in vertilcal parse in x = %d y = %d    map[x][y] = %c\n", x, y, map[y][x]);
				//	while (map[y][x] == ' ')
					y++;
				}
				if (map[y] && map[y + 1])
					y++;
			}
			else
			{
				//printf("AQUI?\n");
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
