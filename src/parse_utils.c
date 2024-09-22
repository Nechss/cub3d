#include "cub3D.h"

int count_rows(char **argv)
{
	int	i;

	i = 0;
	while(argv[i])
		i++;
	return (i);
}

char	*trim_spaces(char *str)
{
	printf("trim_str = %s\n", str);
	char *temp;

	temp = str;
	temp = ft_strtrim(temp, " ");
	//ft_strlcpy(str, temp, ft_strlen(str));
	printf("TRIMED_str =%s\n", temp);
	return (temp);
}


static void	check_if_is_num(char *str)
{
	printf("color = %s\n", str);
	int i;

	i = 0;	
	if (str[0] == '-')
		i++;
	while(str[i])
	{
		//printf("char_color = %c\n", str[i]);
		if (ft_isdigit(str[i]))
			i++;
		else
			ft_exit("Invalid color paramater");
	}
}
static void	check_limits(char *str)
{
	if (ft_strlen(str) > 3)
		ft_exit("Number too long");
	if (str[0] == '-')
		ft_exit("Invalid negative number");
}

void	convert_num_color(char **colors, int color_x[3])
{
	int	i;

	i = 0;
//	check_color_format
	while (colors[i])
	{
		check_if_is_num(colors[i]);
		check_limits(colors[i]);
		color_x[i] = ft_atoi(colors[i]);
		if (color_x[i] > 255)
			color_x[i] = 255;
		if (color_x[i] < 0)
			color_x[i] = 0;
		i++;
	}
	//color_x[i] = ;
}
