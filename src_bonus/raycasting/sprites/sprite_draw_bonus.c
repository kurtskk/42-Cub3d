/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_draw_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-cad <jose-cad@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:17:41 by jose-cad          #+#    #+#             */
/*   Updated: 2026/02/12 14:18:42 by jose-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	put_sprite_pixel(t_cub *cub, t_img *tex, t_sprite_draw *sd);

void	render_sprites(t_cub *cub)
{
	t_sprite_calc	sc;
	t_sprite_draw	sd;
	t_img			*tex;
	int				i;

	sort_sprites(cub);
	i = 0;
	while (i < cub->map.num_sprites)
	{
		calc_sprite_transform(cub, &sc, &cub->map.sprites[i]);
		if (sc.transform_y > 0)
		{
			calc_sprite_screen(&sc, &sd);
			sd.depth = sc.transform_y;
			tex = &cub->map.sprite_frames[update_animation_frame()];
			draw_sprite(cub, &sd, tex);
		}
		i++;
	}
	if (cub->map.has_exit)
		render_exit(cub);
}

void	calc_tex_coords(t_sprite_draw *sd, t_img *tex)
{
	int	sprite_width;
	int	sprite_height;

	sprite_width = sd->end_x - sd->start_x;
	sprite_height = sd->end_y - sd->start_y;
	sd->tex_x = (sd->x - sd->start_x) * tex->width / sprite_width;
	sd->tex_y = (sd->y - sd->start_y) * tex->height / sprite_height;
}

void	draw_sprite(t_cub *cub, t_sprite_draw *sd, t_img *tex)
{
	sd->x = sd->start_x;
	while (sd->x < sd->end_x)
	{
		if (sd->x >= 0 && sd->x < WIN_WIDTH
			&& sd->depth >= cub->z_buffer[sd->x])
		{
			sd->x++;
			continue ;
		}
		sd->y = sd->start_y;
		while (sd->y < sd->end_y)
		{
			calc_tex_coords(sd, tex);
			put_sprite_pixel(cub, tex, sd);
			sd->y++;
		}
		sd->x++;
	}
}

static void	put_sprite_pixel(t_cub *cub, t_img *tex, t_sprite_draw *sd)
{
	char	*dst;
	int		color;

	if (sd->tex_y < 0 || sd->tex_y >= tex->height
		|| sd->tex_x < 0 || sd->tex_x >= tex->width)
		return ;
	dst = tex->addr + (sd->tex_y * tex->line_len
			+ sd->tex_x * (tex->bpp / 8));
	color = *(unsigned int *)dst;
	if ((color & 0x00FFFFFF) != 0)
		my_mlx_pixel_put(&cub->screen, sd->x, sd->y, color);
}
