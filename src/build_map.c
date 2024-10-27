#include "cub3D.h"

int	check_empty_line(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}

void	clean_empty_nodes(t_maplist **head)
{
	t_maplist	*temp;
	// t_maplist	*prev;
	int			flag_empty;

	flag_empty = 0;
	temp = *head;
	while (temp->next != NULL)
	{
		if (check_empty_line(temp->line))
		{
			flag_empty = 1;
		}
		if (!check_empty_line(temp->line) && flag_empty)
			ft_exit("Error: aqui es empty line in map");
		temp = temp->next;
	}
	//temp = temp->prev;
	while(check_empty_line(temp->line))
	{
		printf("str = %s\n", temp->line);
		temp = temp->prev;
		free(temp->next->line);
		free(temp->next);
		temp->next = NULL;
	}
	// temp = temp->prev;
	// while(check_empty_line(temp->line))
	// {
		
	// 	printf("str = %s\n", temp->line);
	// 	prev = temp->prev;
	// 	// free(temp->line);
	// 	// free(temp);
	// 	temp = prev;
	// 	temp->next = NULL;
	// }
	
}

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
		// free(temp->prev->line);
		// free(temp->prev);
		// temp->prev = NULL;
	}
}

static void	check_extrem_lines(t_parse *parse)
{
	//printf("map[1] = %s\n", parse->map[1]);
	if (ft_strchr(parse->map[1], '0'))
		ft_exit("Error char '0' on first line");
	//printf("map[parse->map_height] = %s\n", parse->map[parse->map_height - 2]);
	if (ft_strchr(parse->map[parse->map_height - 2], '0'))
		ft_exit("Error char '0' on last line");
}

void	create_map(t_parse *parse, t_maplist **head)
{
	int			height;

	clean_empty_nodes(head);
	height = map_height(head);
	printf("H = %d\n", height);
	parse->map = (char **)malloc((height + 3) * sizeof(char *));
	if (!parse->map)
		ft_exit("Error de malloc");
	parse->map[height + 2] = NULL;
	parse->map_height = height + 2;
	parse->map_width = map_width(head) + 2;
	fill_map(parse, head);
	//free_list(head);
	check_extrem_lines(parse);
}
