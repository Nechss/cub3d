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
		ft_exit("Number too long");
	if (str[0] == '-')
		ft_exit("Invalid negative number");
}

void	convert_num_color(char **colors, int color_x[3])
{
	int	i;

	i = 0;
	colors[2][ft_strlen(colors[2]) - 1] = '\0';
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
}
