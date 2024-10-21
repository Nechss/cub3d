/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez-b <gperez-b@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 20:36:48 by gperez-b          #+#    #+#             */
/*   Updated: 2024/02/25 20:37:27 by gperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	can_move(float new_x, float new_y, t_cub *cub)
{
	if ((int)(new_x) >= 0 && (int)(new_x) < cub->map_width &&
		(int)(new_y) >= 0 && (int)(new_y) < cub->map_height &&
		cub->map[(int)(new_y + 0.15)][(int)(new_x + 0.15)] != '1' &&
		cub->map[(int)(new_y + 0.15)][(int)(new_x - 0.15)] != '1' &&
		cub->map[(int)(new_y - 0.15)][(int)(new_x + 0.15)] != '1' &&
		cub->map[(int)(new_y - 0.15)][(int)(new_x - 0.15)] != '1')
	{
		cub->player.x = new_x;
		cub->player.y = new_y;
	}
}

void	move_event(t_cub *cub, float new_x, float new_y)
{
	if (mlx_is_key_down(cub->mlx, WKEY))
	{
		new_x += MOVE_SPEED * cos(cub->player.angle);
		new_y += MOVE_SPEED * sin(cub->player.angle);
	}
	if (mlx_is_key_down(cub->mlx, SKEY))
	{
		new_x -= MOVE_SPEED * cos(cub->player.angle);
		new_y -= MOVE_SPEED * sin(cub->player.angle);
	}
	if (mlx_is_key_down(cub->mlx, AKEY))
	{
		new_x += MOVE_SPEED * cos(cub->player.angle - M_PI_2);
		new_y += MOVE_SPEED * sin(cub->player.angle - M_PI_2);
	}
	if (mlx_is_key_down(cub->mlx, DKEY))
	{
		new_x += MOVE_SPEED * cos(cub->player.angle + M_PI_2);
		new_y += MOVE_SPEED * sin(cub->player.angle + M_PI_2);
	}
	can_move(new_x, new_y, cub);
}

void	rotate_event(t_cub *cub)
{
	if (mlx_is_key_down(cub->mlx, LEFT))
		cub->player.angle -= ROTATE_SPEED;
	if (mlx_is_key_down(cub->mlx, RIGHT))
		cub->player.angle += ROTATE_SPEED;
	render(cub);
}
