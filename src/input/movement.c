/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-cad <jose-cad@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:01:34 by jose-cad          #+#    #+#             */
/*   Updated: 2026/02/12 14:01:50 by jose-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_new_position(t_cub *cub, double *new_x, double *new_y,
	int direction)
{
	double	move_speed;

	move_speed = MOVE_SPEED;
	*new_x = cub->player.pos_x;
	*new_y = cub->player.pos_y;
	if (direction == 0)
	{
		*new_x += cub->player.dir_x * move_speed;
		*new_y += cub->player.dir_y * move_speed;
	}
	else if (direction == 1)
	{
		*new_x -= cub->player.dir_x * move_speed;
		*new_y -= cub->player.dir_y * move_speed;
	}
	else if (direction == 2)
	{
		*new_x -= cub->player.plane_x * move_speed;
		*new_y -= cub->player.plane_y * move_speed;
	}
	else if (direction == 3)
	{
		*new_x += cub->player.plane_x * move_speed;
		*new_y += cub->player.plane_y * move_speed;
	}
}

int	handle_movement_keys(int keycode, t_cub *cub)
{
	(void)keycode;
	(void)cub;
	return (0);
}
