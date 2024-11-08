/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaltas <mmaltas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 20:36:48 by gperez-b          #+#    #+#             */
/*   Updated: 2024/11/08 16:28:56 by mmaltas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_list(t_maplist **head)
{
	t_maplist	*temp;
	t_maplist	*next;

	temp = *head;
	while (temp)
	{
		next = temp->next;
		free(temp->line);
		free(temp);
		temp = next;
	}
	*head = NULL;
}

static void	get_line(t_parse *parse, char *map_doc, t_maplist **head)
{
	char	*line;
	int		fd;

	fd = (open(map_doc, O_RDONLY));
	if (fd == -1)
		ft_exit("Failed to read document .cub");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!ft_strncmp(line, "\n", 1))
		{
			if (parse->flags->init_map != 1)
			{
				free(line);
				continue ;
			}
			else if (parse->flags->init_map == 1)
				parse->flags->finish_map = 1;
		}
		check_line(line, parse, head);
		free(line);
	}
}

void	parsing_doc(char *map_doc, t_parse *parse, t_maplist **head)
{
	init_struct(parse);
	get_line(parse, map_doc, head);
	if(*head)
		create_map(parse, head);
	else
		ft_exit("Error empty doc");
	free_list(head);
	vetical_parse_map(parse);
	parse_player(parse);
}
