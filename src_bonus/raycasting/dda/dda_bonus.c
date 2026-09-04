/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-cad <jose-cad@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:16:39 by jose-cad          #+#    #+#             */
/*   Updated: 2026/02/12 14:18:55 by jose-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	step_ray(t_ray *ray);
static int	check_wall_hit(t_cub *cub, t_ray *ray);
static int	is_out_of_bounds(t_cub *cub, int map_x, int map_y);

void	calc_step(t_cub *cub, t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (cub->player.pos_x - ray->map_x)
			* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - cub->player.pos_x)
			* ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (cub->player.pos_y - ray->map_y)
			* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - cub->player.pos_y)
			* ray->delta_dist_y;
	}
}

void	perform_dda(t_cub *cub, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (is_out_of_bounds(cub, ray->map_x, ray->map_y))
		{
			ray->hit = 1;
			break ;
		}
		step_ray(ray);
		if (check_wall_hit(cub, ray))
		{
			ray->hit = 1;
			break ;
		}
	}
}

static void	step_ray(t_ray *ray)
{
	if (ray->side_dist_x < ray->side_dist_y)
	{
		ray->side_dist_x += ray->delta_dist_x;
		ray->map_x += ray->step_x;
		ray->side = 0;
	}
	else
	{
		ray->side_dist_y += ray->delta_dist_y;
		ray->map_y += ray->step_y;
		ray->side = 1;
	}
}

static int	is_out_of_bounds(t_cub *cub, int map_x, int map_y)
{
	if (map_x < 0 || map_y < 0 || map_y >= cub->map.height)
		return (1);
	if (map_x >= (int)ft_strlen(cub->map.grid[map_y]))
		return (1);
	return (0);
}

static int	check_wall_hit(t_cub *cub, t_ray *ray)
{
	char	cell;

	if (is_out_of_bounds(cub, ray->map_x, ray->map_y))
		return (1);
	cell = cub->map.grid[ray->map_y][ray->map_x];
	if (cell == '1')
		return (1);
	if (cell == 'D' && !is_door_open(cub, ray->map_x, ray->map_y))
		return (1);
	return (0);
}
