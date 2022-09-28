/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:29:18 by alukongo          #+#    #+#             */
/*   Updated: 2022/09/28 12:59:39 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	define_step(t_data *data)
{
	if (data->raycast.ray_dir_x < 0)
	{
		data->raycast.step_x = -1;
		data->raycast.side_dist_x = (data->pos_x - data->raycast.map_x)
			* data->raycast.delta_dist_x;
	}
	else
	{
		data->raycast.step_x = 1;
		data->raycast.side_dist_x = (data->raycast.map_x + 1.0 - data->pos_x)
			* data->raycast.delta_dist_x;
	}
	if (data->raycast.ray_dir_y < 0)
	{
		data->raycast.step_y = -1;
		data->raycast.side_dist_y = (data->pos_y - data->raycast.map_y)
			* data->raycast.delta_dist_y;
	}
	else
	{
		data->raycast.step_y = 1;
		data->raycast.side_dist_y = (data->raycast.map_y + 1.0 - data->pos_y)
			* data->raycast.delta_dist_y;
	}
}

void	dda_function(t_data *data)
{
	while (data->raycast.hit == 0)
	{
		if (data->raycast.side_dist_x < data->raycast.side_dist_y)
		{
			data->raycast.side_dist_x += data->raycast.delta_dist_x;
			data->raycast.map_x += data->raycast.step_x;
			data->raycast.side = 0;
		}
		else
		{
			data->raycast.side_dist_y += data->raycast.delta_dist_y;
			data->raycast.map_y += data->raycast.step_y;
			data->raycast.side = 1;
		}
		if (data->map[data->raycast.map_x][data->raycast.map_y] > '0')
			data->raycast.hit = 1;
	}
}

void	draw_start_end(t_data *data)
{
	if (data->raycast.side == 0)
	{
		data->raycast.perp_wall_dist = (data->raycast.map_x - data->pos_x
				+ (1 - data->raycast.step_x) / 2) / data->raycast.ray_dir_x;
	}
	else
	{
		data->raycast.perp_wall_dist = (data->raycast.map_y - data->pos_y
				+ (1 - data->raycast.step_y) / 2) / data->raycast.ray_dir_y;
	}
	data->raycast.line_height = (int)(HEIGHT / data->raycast.perp_wall_dist);
	data->raycast.draw_start = -data->raycast.line_height / 2 + HEIGHT / 2;
	if (data->raycast.draw_start < 0)
		data->raycast.draw_start = 0;
	data->raycast.draw_end = data->raycast.line_height / 2 + HEIGHT / 2;
	if (data->raycast.draw_end >= HEIGHT)
		data->raycast.draw_end = HEIGHT - 1;
}

/**
 * texNum: the line where i save my texture
 * step: How much to increase the texture coordinate perscreen pixel
 * tex_pos: Starting texture coordinate
 * 
 * @param data 
 * @param x 
 */

void	add_texture(t_data *data, int x, int y)
{
	double	step;
	double	tex_pos;
	int		tex_y;

	step = 1.0 * TEXHEIGHT / data->raycast.line_height;
	tex_pos = (data->raycast.draw_start - HEIGHT / 2
			+ data->raycast.line_height / 2) * step;
	if (data->raycast.side == 0 && data->raycast.ray_dir_x > 0)
		data->raycast.tex_x = TEXWIDTH - data->raycast.tex_x - 1;
	if (data->raycast.side == 1 && data->raycast.ray_dir_y < 0)
		data->raycast.tex_x = TEXWIDTH - data->raycast.tex_x - 1;
	while (y < data->raycast.draw_end)
	{
		tex_y = (int)tex_pos & (TEXHEIGHT - 1);
		tex_pos += step;
		if (data->raycast.side == 1)
		{
			if (data->raycast.ray_dir_x > 0)//N
				data->raycast.color = data->texture[0][TEXHEIGHT
					* tex_y + data->raycast.tex_x];
			else if (data->raycast.ray_dir_x < 0)//S
				data->raycast.color = data->texture[1][TEXHEIGHT
					* tex_y + data->raycast.tex_x];
		}
		if (data->raycast.side == 0)
		{
			if (data->raycast.ray_dir_y < 0) //E
				data->raycast.color = data->texture[2][TEXHEIGHT
					* tex_y + data->raycast.tex_x];
			else if (data->raycast.ray_dir_y > 0)//W
				data->raycast.color = data->texture[3][TEXHEIGHT
					* tex_y + data->raycast.tex_x];
		}
		data->buf[y][x] = data->raycast.color;
		data->re_buf = 1;
		y++;
	}
}
