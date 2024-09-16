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

void	destroy(void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	if (cub && cub->mlx)
		mlx_terminate(cub->mlx);
	free_map(cub->map);
	exit(0);
}

void	loop_hook(void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	if (mlx_is_key_down(cub->mlx, ESC))
		destroy(cub);
	move_event(cub, cub->player.x, cub->player.y);
	rotate_event(cub);
}

void	events(t_cub *cub)
{
	mlx_loop_hook(cub->mlx, &loop_hook, cub);
	mlx_close_hook(cub->mlx, &destroy, cub);
}
