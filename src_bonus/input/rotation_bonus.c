/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-cad <jose-cad@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:12:51 by jose-cad          #+#    #+#             */
/*   Updated: 2026/02/12 14:13:03 by jose-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	rotate_player(t_cub *cub, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cub->player.dir_x;
	cub->player.dir_x = cub->player.dir_x * cos(rot_speed)
		- cub->player.dir_y * sin(rot_speed);
	cub->player.dir_y = old_dir_x * sin(rot_speed)
		+ cub->player.dir_y * cos(rot_speed);
	old_plane_x = cub->player.plane_x;
	cub->player.plane_x = cub->player.plane_x * cos(rot_speed)
		- cub->player.plane_y * sin(rot_speed);
	cub->player.plane_y = old_plane_x * sin(rot_speed)
		+ cub->player.plane_y * cos(rot_speed);
}
