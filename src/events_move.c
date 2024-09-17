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


///// comprobar los dos a la vez : 

 
void	can_move(float new_x, float new_y, t_cub *cub)
{
	int	map_x;
	int	map_y;
	int	current_map_x;
	int	current_map_y;

	map_x = (int)(new_x);
	map_y = (int)(new_y);
	current_map_x = (int)(cub->player.x);
	current_map_y = (int)(cub->player.y);
	if (map_x >= 0 && map_x < cub->map_width
		&& cub->map[current_map_y][(int)(new_x + 0.3)] != '1' &&
			cub->map[current_map_y][(int)(new_x - 0.3)] != '1')
		;
	if (map_y >= 0 && map_y < cub->map_height
		&& cub->map[(int)(new_y + 0.3)][current_map_x] != '1' &&
			cub->map[(int)(new_y - 0.3)][current_map_x] != '1')
		 ;

	if (cub->map[(int)(new_y)][(int)(new_x)] != '1' &&
			cub->map[(int)(new_y - 0.3)][(int)(new_x - 0.3)] != '1')
	{
		cub->player.x = new_x;
		cub->player.y = new_y;
	}

	printf("new_x: %f\n", new_x);
	printf("new_y: %f\n", new_y);
}


// void	can_move(float new_x, float new_y, t_cub *cub)
// {
// 	int	map_x;
// 	int	map_y;
// 	int	current_map_x;
// 	int	current_map_y;

// 	map_x = (int)(new_x);
// 	map_y = (int)(new_y);
// 	current_map_x = (int)(cub->player.x);
// 	current_map_y = (int)(cub->player.y);
// 	if (map_x >= 0 && map_x < cub->map_width
// 		&& cub->map[(int)(new_y + 0.3)][(int)(new_x + 0.3)] != '1' &&
// 			cub->map[(int)(new_y - 0.3)][(int)(new_x - 0.3)] != '1')
// 	{
// 		cub->player.x = new_x;
// 		cub->player.y = new_y;
// 	}
// 	printf("new_x: %f\n", new_x);
// 	printf("new_y: %f\n", new_y);
// }

// void	can_move(float new_x, float new_y, t_cub *cub)
// {
// 	int	map_x;
// 	int	map_y;
// 	int	current_map_x;
// 	int	current_map_y;

// 	map_x = (int)(new_x);
// 	map_y = (int)(new_y);
// 	current_map_x = (int)(cub->player.x);
// 	current_map_y = (int)(cub->player.y);
// 	if (map_x >= 0 && map_x < cub->map_width
// 		&& cub->map[(int)(cub->player.y + 0.5)][(int)(new_x + 0.15)] != '1' &&
// 			cub->map[(int)(cub->player.y + 0.5)][(int)(new_x - 0.15)] != '1')
// 		cub->player.x = new_x;
// 	if (map_y >= 0 && map_y < cub->map_height
// 		&& cub->map[(int)(new_y + 0.15)][current_map_x] != '1' &&
// 			cub->map[(int)(new_y - 0.15)][current_map_x] != '1')
// 		cub->player.y = new_y;


// 	if (map_x >= 0 && map_x < cub->map_width
// 		&& cub->map[(int)(cub->player.y - 0.5)][(int)(new_x + 0.15)] != '1' &&
// 			cub->map[(int)(cub->player.y - 0.5)][(int)(new_x - 0.15)] != '1')
// 		cub->player.x = new_x;
// 	if (map_y >= 0 && map_y < cub->map_height
// 		&& cub->map[(int)(new_y + 0.15)][current_map_x] != '1' &&
// 			cub->map[(int)(new_y - 0.15)][current_map_x] != '1')
// 		cub->player.y = new_y;


// 	if (map_x >= 0 && map_x < cub->map_width
// 		&& cub->map[(int)(cub->player.y)][(int)(new_x + 0.15)] != '1' &&
// 			cub->map[(int)(cub->player.y)][(int)(new_x - 0.15)] != '1')
// 		cub->player.x = new_x;
// 	if (map_y >= 0 && map_y < cub->map_height
// 		&& cub->map[(int)(new_y + 0.15)][(int)(cub->player.x + 0.5)] != '1' &&
// 			cub->map[(int)(new_y - 0.15)][(int)(cub->player.x + 0.5)] != '1')
// 		cub->player.y = new_y;

// 	if (map_x >= 0 && map_x < cub->map_width
// 		&& cub->map[(int)(cub->player.y)][(int)(new_x + 0.15)] != '1' &&
// 			cub->map[(int)(cub->player.y)][(int)(new_x - 0.15)] != '1')
// 		cub->player.x = new_x;
// 	if (map_y >= 0 && map_y < cub->map_height
// 		&& cub->map[(int)(new_y + 0.15)][(int)(cub->player.x - 0.5)] != '1' &&
// 			cub->map[(int)(new_y - 0.15)][(int)(cub->player.x - 0.5)] != '1')
// 		cub->player.y = new_y;
// }

float	round_to_decimals(float value, int decimals)
{
	float	factor;

	factor = pow(10, decimals);
	return (round(value * factor) / factor);
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
	//new_x = round_to_decimals(new_x, 3);
	//new_y = round_to_decimals(new_y, 3);
	can_move(new_x, new_y, cub);
}

void	rotate_event(t_cub *cub)
{
	if (mlx_is_key_down(cub->mlx, LEFT))
		cub->player.angle -= ROTATE_SPEED;
	if (mlx_is_key_down(cub->mlx, RIGHT))
		cub->player.angle += ROTATE_SPEED;
	//cub->player.angle = round_to_decimals(cub->player.angle, 2);
	render(cub);
}
