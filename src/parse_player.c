/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez-b <gperez-b@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 20:43:13 by gperez-b          #+#    #+#             */
/*   Updated: 2024/02/29 19:47:39 by gperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_position(t_parse *parse)
{
	int		x;
	int		y;
	int		i;
	char **map;

	map = parse->map;
	y = parse->position[0];
	x = parse->position[1];
	if (map[y - 1][x] == ' ' || map[y + 1][x] == ' ')
		ft_exit("Error: Bad player position");
	y -= 1;
	i = 0;
	while(i++ <= 2)
	{
		if (map[y][x - 1] == ' ' || map[y][x + 1] == ' ')
			ft_exit("Error: Bad player position 2");
		y++;
	}
}

void	check_player(t_parse *parse, char c, int x, int y)
{
	if(!parse->player)
	{
		parse->player = c;
		parse->position[0] = y;
		parse->position[1] = x;
	}
	else
		ft_exit("Error: invalid number of players");
}

void find_player(t_parse *parse)
{
	int		x;
	int		y;
	char	**map;

	y = 0;
	map = parse->map;
	while(map[y])
	{
		x = 0;
		while(map[y][x])
		{
			if (map[y][x] == 'N' ||  map[y][x] == 'S' ||  map[y][x] == 'E' ||  map[y][x] == 'W')
				check_player(parse, map[y][x], x, y);
			x++;
		}
		y++;
	}
	if (parse->position[0] == 0 && parse->position[1] == 0)
		ft_exit("Error: No player found");
}

void parse_player(t_parse *parse)
{
	find_player(parse);
	check_position(parse);
	printf("ENTRA\n");
}
