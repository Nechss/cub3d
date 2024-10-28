/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaltas <mmaltas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:30:48 by mmaltas           #+#    #+#             */
/*   Updated: 2024/10/28 14:30:49 by mmaltas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_struct(t_parse *parse)
{
	parse->tex_n = NULL;
	parse->tex_s = NULL;
	parse->tex_e = NULL;
	parse->tex_w = NULL;
	parse->color_c[0] = 0;
	parse->color_c[1] = 0;
	parse->color_c[2] = 0;
	parse->color_f[0] = 0;
	parse->color_f[1] = 0;
	parse->color_f[2] = 0;
	parse->map_width = 0;
	parse->map_height = 0;
	parse->map = NULL;
	parse->player = '\0';
}
