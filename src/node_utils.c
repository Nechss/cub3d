/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaltas <mmaltas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:23:27 by mmaltas           #+#    #+#             */
/*   Updated: 2024/10/28 14:32:35 by mmaltas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_empty_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
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
	while (check_empty_line(temp->line))
	{
		printf("str = %s\n", temp->line);
		temp = temp->prev;
		free(temp->next->line);
		free(temp->next);
		temp->next = NULL;
	}
}
