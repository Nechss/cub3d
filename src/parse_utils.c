/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaltas <mmaltas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:04:37 by mmaltas           #+#    #+#             */
/*   Updated: 2024/10/28 15:04:38 by mmaltas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	count_rows(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

char	*trim_spaces(char *str)
{
	char	*temp;

	temp = str;
	temp = ft_strtrim(temp, " ");
	return (temp);
}

static void	check_if_is_num(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			i++;
		else
			ft_exit("Invalid color paramater");
	}
}

static void	check_limits(char *str)
{
	if (ft_strlen(str) > 3)
		ft_exit("Number to many digits");
	if (str[0] == '-')
		ft_exit("Invalid negative number");
}

void	convert_num_color(char **colors, t_parse *parse, int option)
{
	int	i;

	i = 0;
	colors[2][ft_strlen(colors[2]) - 1] = '\0';
	while (colors[i])
	{
		check_if_is_num(colors[i]);
		check_limits(colors[i]);
		if (option == 1)
		{
			parse->color_f[i] = ft_atoi(colors[i]);
			if (parse->color_f[i] > 255 || parse->color_f[i] < 0)
				ft_exit("Error bad color value");
			parse->done_f = 1;
		}
		if (option == 2)
		{
			parse->color_c[i] = ft_atoi(colors[i]);
			if (parse->color_c[i] > 255 || parse->color_c[i] < 0)
				ft_exit("Error bad color value");
			parse->done_c = 1;
		}
		i++;
	}
}
