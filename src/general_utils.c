/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaltas <mmaltas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:32:50 by mmaltas           #+#    #+#             */
/*   Updated: 2024/10/28 17:40:04 by mmaltas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_exit(char *str)
{
	printf("%s\n", str);
	exit(EXIT_FAILURE);
}

void	free_words(char **rslt)
{
	int	i;

	i = 0;
	while (rslt[i])
	{
		free(rslt[i]);
		i++;
	}
	free(rslt);
}

void	free_parse(t_parse *parse)
{
	free(parse->tex_n);
	free(parse->tex_s);
	free(parse->tex_e);
	free(parse->tex_w);
	free_words(parse->map);
	printf("entra\n");
}
