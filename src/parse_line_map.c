#include "cub3D.h"

static int check_first_char(char *str, int i)
{
	while(str[i] && str[i] == ' ')
		i++;
	if(!str[i])
		return (-1);
	if (str[i] && str[i] != '1')
		ft_exit("Incorrect map at begining wall");
	return (i);
}

static int check_last_char(char *str, int i)
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

static void check_char_type(char *str, int i)
{
	if(str[i] != '0' && str[i] != '1' && str[i] != 'N' \
	&& str[i] != 'S' && str[i] != 'E' && str[i] != 'W' \
	&& str[i] != ' ')  
		ft_exit("Incorrect map: bad caracter");	
}

static int check_wall(char *str, t_parse *parse, int i)
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
