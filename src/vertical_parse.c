/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaltas <mmaltas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:33:37 by mmaltas           #+#    #+#             */
/*   Updated: 2024/10/28 15:07:13 by mmaltas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	loop_parse_map(t_parse *parse, char **map, int x, int y)
{
	while (x++ < parse->map_width)
	{
		y = 1;
		while (y < parse->map_height - 2)
		{
			if (map[y][x] && map[y][x] == ' ')
			{
				if (map[y][x - 1] == '0' || map[y + 1][x] == '0' || \
				map[y - 1][x] == '0' || map[y][x + 1] == '0')
				{
					printf("Error on x = %d, y = %d\n", x, y);
					ft_exit("map not closed");
				}
				y++;
			}
			else
				y++;
		}
	}
}

void	vetical_parse_map(t_parse *parse)
{
	int		y;
	int		x;
	char	**map;

	y = 0;
	x = 0;
	map = parse->map;
	loop_parse_map(parse, map, x, y);
}
