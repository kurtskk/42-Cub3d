/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-cad <jose-cad@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:18:07 by jose-cad          #+#    #+#             */
/*   Updated: 2026/02/12 14:18:13 by jose-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	load_exit_texture(t_cub *cub);
static void	load_sprite_frames(t_cub *cub);
static void	load_texture(t_cub *cub, int idx, char *path);
static void	load_single_sprite(t_cub *cub, int i, char *path);

void	init_textures(t_cub *cub)
{
	load_texture(cub, 0, cub->map.no_texture);
	load_texture(cub, 1, cub->map.so_texture);
	load_texture(cub, 2, cub->map.we_texture);
	load_texture(cub, 3, cub->map.ea_texture);
	load_sprite_frames(cub);
	load_exit_texture(cub);
}

static void	load_texture(t_cub *cub, int idx, char *path)
{
	t_img	*tex;

	tex = &cub->map.textures[idx];
	tex->img = mlx_xpm_file_to_image(cub->mlx, path,
			&tex->width, &tex->height);
	if (!tex->img)
		error_exit_cleanup(cub, "Error\nFailed to load texture\n");
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp,
			&tex->line_len, &tex->endian);
}

static void	load_sprite_frames(t_cub *cub)
{
	char	*paths[8];
	int		i;

	paths[0] = "./textures/ice1.xpm";
	paths[1] = "./textures/ice2.xpm";
	paths[2] = "./textures/ice3.xpm";
	paths[3] = "./textures/ice4.xpm";
	paths[4] = "./textures/ice5.xpm";
	paths[5] = "./textures/ice6.xpm";
	paths[6] = "./textures/ice7.xpm";
	paths[7] = "./textures/ice8.xpm";
	i = 0;
	while (i < 8)
	{
		load_single_sprite(cub, i, paths[i]);
		i++;
	}
}

static void	load_single_sprite(t_cub *cub, int i, char *path)
{
	t_img	*sprite;

	sprite = &cub->map.sprite_frames[i];
	sprite->img = mlx_xpm_file_to_image(cub->mlx, path,
			&sprite->width, &sprite->height);
	if (!sprite->img)
	{
		cub->map.sprite_frames[i] = cub->map.textures[i % 4];
		return ;
	}
	sprite->addr = mlx_get_data_addr(sprite->img, &sprite->bpp,
			&sprite->line_len, &sprite->endian);
}

static void	load_exit_texture(t_cub *cub)
{
	t_img	*exit_tex;

	if (!cub->map.has_exit)
		return ;
	exit_tex = &cub->map.sprite_frames[8];
	exit_tex->img = mlx_xpm_file_to_image(cub->mlx, "./textures/exit.xpm",
			&exit_tex->width, &exit_tex->height);
	if (!exit_tex->img)
	{
		cub->map.sprite_frames[8] = cub->map.textures[0];
		return ;
	}
	exit_tex->addr = mlx_get_data_addr(exit_tex->img, &exit_tex->bpp,
			&exit_tex->line_len, &exit_tex->endian);
}
