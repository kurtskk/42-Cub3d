/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_animation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-cad <jose-cad@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:12:21 by jose-cad          #+#    #+#             */
/*   Updated: 2026/02/12 14:13:44 by jose-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	update_door_animation(t_cub *cub)
{
	static struct timeval	last_time;
	struct timeval			curr_time;
	long					ms;
	int						i;

	gettimeofday(&curr_time, NULL);
	ms = (curr_time.tv_sec * 1000 + curr_time.tv_usec / 1000)
		- (last_time.tv_sec * 1000 + last_time.tv_usec / 1000);
	if (ms > 150)
	{
		i = 0;
		while (i < cub->map.num_doors)
		{
			if (!cub->map.doors[i].is_open)
			{
				cub->map.doors[i].anim_frame++;
				if (cub->map.doors[i].anim_frame >= 4)
					cub->map.doors[i].anim_frame = 0;
			}
			i++;
		}
		last_time = curr_time;
	}
}
