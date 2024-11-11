/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaltas <mmaltas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:33:26 by mmaltas           #+#    #+#             */
/*   Updated: 2024/10/28 17:37:21 by mmaltas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	map_height(t_maplist **head)
{
	t_maplist	*temp;
	int			height;

	temp = *head;
	height = 0;
	while (temp->next)
	{
		temp = temp->next;
		height++;
	}
	return (height + 1);
}

static int	map_width(t_maplist **head)
{
	t_maplist	*temp;
	size_t		width;
	int			i;

	temp = *head;
	width = 0;
	while (temp)
	{
		i = 0;
		while (temp->line[i])
			i++;
		if (i > 0)
			i--;
		while (temp->line && temp->line[i] == ' ')
			i--;
		if (temp->line[i])
			temp->line[i + 1] = '\0';
		if (width < ft_strlen(temp->line))
			width = ft_strlen(temp->line);
		temp = temp->next;
	}
	return (width);
}

static void	fill_map(t_parse *parse, t_maplist **head)
{
	t_maplist	*temp;
	int			i;
	size_t		len;

	temp = *head;
	i = -1;
	while (i++ < parse->map_height - 1)
	{
		len = ft_strlen(temp->line);
		parse->map[i] = (char *)malloc((parse->map_width +3) * sizeof(char));
		if (!parse->map[i])
			ft_exit("Error de malloc 2");
		parse->map[i][parse->map_width + 2] = '\0';
		ft_memset(parse->map[i], ' ', parse->map_width + 2);
		if (i == 0 || i == parse->map_height - 1)
			continue ;
		if (ft_memcpy(parse->map[i] + 1, temp->line, len) == 0)
			ft_exit("Error in ft_strlcpy");
		if (temp->next)
			temp = temp->next;
	}
}

static void	check_extrem_lines(t_parse *parse)
{
	if (ft_strchr(parse->map[1], '0'))
		ft_exit("Error char '0' on first line");
	if (ft_strchr(parse->map[parse->map_height - 2], '0'))
		ft_exit("Error char '0' on last line");
}

void	create_map(t_parse *parse, t_maplist **head)
{
	int			height;

	clean_empty_nodes(head);
	height = map_height(head);
	parse->map = (char **)malloc((height + 3) * sizeof(char *));
	if (!parse->map)
		ft_exit("Error de malloc");
	parse->map[height + 2] = NULL;
	parse->map_height = height + 2;
	parse->map_width = map_width(head) + 2;
	fill_map(parse, head);
	free_list(head);
	check_extrem_lines(parse);
}
