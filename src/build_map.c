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

static void	fill_map(t_parse *parse, t_maplist **head)
{
	t_maplist	*temp;
	int			i;
	size_t		len;

	temp = *head;
	i = 0;

	while (i < parse->map_height)
	{
		len = ft_strlen(temp->line);
		parse->map[i] = (char *)malloc((parse->map_width + 1) * sizeof(char));
		if (!parse->map[i])
			ft_exit("Error de malloc 2");
		parse->map[i][parse->map_width] = '\0';
		ft_memset(parse->map[i], ' ', parse->map_width);
		if (ft_memcpy(parse->map[i], temp->line, len) == 0)
			ft_exit("Error in ft_strlcpy");
		temp = temp->next;
		i++;
	}
}

static void	check_extrem_lines(t_parse *parse)
{
	if (ft_strchr(parse->map[0], '0'))
		ft_exit("Error char '0' limit");
	if (ft_strchr(parse->map[parse->map_height - 1], '0'))
		ft_exit("Error char '0' limit");
}

void	create_map(t_parse *parse, t_maplist **head)
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
	check_extrem_lines(parse);
}
