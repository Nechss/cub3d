/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tabs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaltas <mmaltas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 20:36:48 by gperez-b          #+#    #+#             */
/*   Updated: 2024/10/28 17:24:37 by mmaltas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	replace_tabs(char *line, char *new_line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == '\t')
		{
			new_line[j++] = ' ';
			new_line[j++] = ' ';
			new_line[j++] = ' ';
			new_line[j++] = ' ';
		}
		else
			new_line[j++] = line[i];
		i++;
	}
	new_line[j] = '\0';
}

char	*parse_tabs(char *line)
{
	int		tabs_count;
	int		i;
	char	*new_line;
	int		new_len;

	tabs_count = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '\t')
			tabs_count++;
		i++;
	}
	new_len = i + tabs_count * 3;
	new_line = (char *)malloc(new_len + 1);
	if (!new_line)
		ft_exit("Error de Malloc");
	replace_tabs(line, new_line);
	return (new_line);
}
