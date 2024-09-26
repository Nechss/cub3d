#include "cub3D.h"

static void	check_error_one(int y, int x, char **map)
{
	if (map[y][x] != '1')
		ft_exit("Error: Bad map");
	else
	{
		if (map[y][x + 1] == '0')
		ft_exit("Error: Bad map");
	}
}

static void	check_error_two(int y, int x, char **map)
{
	if (map[y][x + 1] && (map[y - 1][x + 1] != '1' && map[y - 1][x + 1] != ' '))
		ft_exit("Error: Bad map");
	if (map[y + 1] && (map[y + 1][x] == '0'))
		ft_exit("Error: Bad map");
	if (map[y - 1] && map[y - 1][x] == '0')
		ft_exit("Error: Bad map");
	if ((x > 0 && map[y + 1]) && (map[y + 1][x - 1] == '0'))
		ft_exit("Error: Bad map");
}

static void	loop_parse_map(t_parse *parse, char **map, int x, int y)
{
	while (x++ < parse->map_width)
	{
		y = 0;
		while (y < parse->map_height)
		{
			if (map[y][x] && map[y][x] == ' ')
			{
				if (y == 0)
				{
					while (map[y][x] == ' ')
						y++;
					check_error_one(y, x, map);
				}
				else
				{
					check_error_two(y, x, map);
					y++;
				}
				if (map[y] && map[y + 1])
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
