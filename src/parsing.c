/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez-b <gperez-b@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 20:36:48 by gperez-b          #+#    #+#             */
/*   Updated: 2024/10/21 16:27:23 by mmaltas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	get_line(t_parse *parse, char *map_doc, t_maplist **head)
{
	char	*line;
	char	*clean_line;
	int		fd;

	fd = (open(map_doc, O_RDONLY));
	if (fd == -1)
		ft_exit("Failed to read document .cub");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		
		if (!strcmp(line, "\n"))
		{
			if (parse->flags->init_map != 1)
			{
				free(line);
				continue ;
			}
			else if(parse->flags->init_map == 1)
				parse->flags->finish_map = 1;
		}
		clean_line = ft_strtrim(line, "\n");
		check_line(clean_line, parse, head);
		free(line);
		free(clean_line);
	}
}

void	parsing_doc(char *map_doc, t_parse *parse, t_maplist **head)
{
	init_struct(parse);
	get_line(parse, map_doc, head);
	create_map(parse, head);
	vetical_parse_map(parse);
	parse_player(parse);
	print_parse(parse);
//	exit(0);
}
