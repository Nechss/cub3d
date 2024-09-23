#include "cub3D.h"

static void	check_error_one(int y, int x, char **map)
{
	if (map[y][x] != '1')
		printf("Error 1 wall open in vertilcal parse in x = %d y = %d    map[x][y] = %c\n", x, y, map[y][x]);
	else
	{
		if (map[y][x + 1] == '0')
			printf("Error 2 wall open in vertilcal parse in x = %d y = %d\n", x + 1, y);
	}
}

static void	check_error_two(int y, int x, char **map)
{
	if (map[y][x + 1] && (map[y - 1][x + 1] != '1' && map[y - 1][x + 1] != ' '))
		printf("Error 3 wall open in vertilcal parse in x = %d y = %d    map[x][y] = %c\n", x, y, map[y][x]);
	if (map[y + 1] && (map[y + 1][x] == '0'))
		printf("Error 4 wall open in vertilcal parse in x = %d y = %d    map[x][y] = %c\n", x, y, map[y][x]);
	if (map[y - 1] && map[y - 1][x] == '0')
		printf("Error 5 wall open in vertilcal parse in x = %d y = %d    map[x][y] = %c\n", x, y, map[y][x]);
	if ((x > 0 && map[y + 1]) && (map[y + 1][x - 1] == '0'))
		printf("Error 6 wall open in vertilcal parse in x = %d y = %d    map[x][y] = %c\n", x, y, map[y][x]);
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
