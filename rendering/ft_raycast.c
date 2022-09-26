/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:29:18 by alukongo          #+#    #+#             */
/*   Updated: 2022/09/26 21:24:41 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"



void	define_step(t_data *data)
{
	if (data->raycast.rayDirX < 0)
	{
		data->raycast.step_x = -1;
		data->raycast.sideDistX = (data->pos_x - data->raycast.mapX) * data->raycast.deltaDistX;
	}
	else
	{
		data->raycast.step_x = 1;
		data->raycast.sideDistX = (data->raycast.mapX + 1.0 - data->pos_x) * data->raycast.deltaDistX;
	}
	if (data->raycast.rayDirY < 0)
	{
		data->raycast.step_y = -1;
		data->raycast.sideDistY = (data->pos_y - data->raycast.mapY) * data->raycast.deltaDistY;
	}
	else
	{
		data->raycast.step_y = 1;
		data->raycast.sideDistY = (data->raycast.mapY + 1.0 - data->pos_y) * data->raycast.deltaDistY;
	}
}






void	dda_function(t_data *data)
{
	// while we don't hit a wall.
	while (data->raycast.hit == 0)
	{
		//jump to next map square, OR in x direction.
		if (data->raycast.sideDistX < data->raycast.sideDistY)
		{
			data->raycast.sideDistX += data->raycast.deltaDistX;
			data->raycast.mapX += data->raycast.step_x;
			data->raycast.side = 0;
		}
		else//jump to next map square, OR in y direction.
		{
			data->raycast.sideDistY += data->raycast.deltaDistY;
			data->raycast.mapY += data->raycast.step_y;
			data->raycast.side = 1;
		}
		//Check if ray has hit a wall
		if (data->map[data->raycast.mapX][data->raycast.mapY] > '0')
			data->raycast.hit = 1;
	}
}





void	draw_start_end(t_data *data)
{
	if (data->raycast.side == 0)
	{
		data->raycast.perpWallDist = (data->raycast.mapX - data->pos_x +
		(1 - data->raycast.step_x) / 2) / data->raycast.rayDirX;
	}
	else
	{
		data->raycast.perpWallDist = (data->raycast.mapY - data->pos_y +
		(1 - data->raycast.step_y) / 2) / data->raycast.rayDirY;
	}

	//Calculate HEIGHT of line to draw on screen
	data->raycast.line_height = (int)(HEIGHT / data->raycast.perpWallDist);

	//calculate lowest and highest pixel to fill in current stripe
	data->raycast.draw_start = -data->raycast.line_height / 2 + HEIGHT / 2;
	if(data->raycast.draw_start < 0)
		data->raycast.draw_start = 0;
	data->raycast.draw_end = data->raycast.line_height / 2 + HEIGHT / 2;
	if(data->raycast.draw_end >= HEIGHT)
		data->raycast.draw_end = HEIGHT - 1;
}


/**
 * texNum: the line where i save my texture
 * step: How much to increase the texture coordinate perscreen pixel
 * texPos: Starting texture coordinate
 * 
 * @param data 
 * @param x 
 */

void	add_texture(t_data *data, int x, int y)
{
	double	step;
	double	texPos;
	int		texY;

	step = 1.0 * TEXHEIGHT / data->raycast.line_height;
	texPos = (data->raycast.draw_start - HEIGHT / 2 + data->raycast.line_height / 2) * step;
	if (data->raycast.side == 0 && data->raycast.rayDirX > 0)
		data->raycast.tex_x = TEXWIDTH - data->raycast.tex_x - 1;
	if (data->raycast.side == 1 && data->raycast.rayDirY < 0)
		data->raycast.tex_x = TEXWIDTH - data->raycast.tex_x - 1;
	while (y < data->raycast.draw_end)
	{
		// Cast the texture coordinate to integer, and mask with (TEXHEIGHT - 1) in case of overflow
		texY = (int)texPos & (TEXHEIGHT - 1);
		texPos += step;
		data->raycast.color = data->texture[2][TEXHEIGHT * texY + data->raycast.tex_x];
		// make data->raycast.color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
		if (data->raycast.side == 1)
			data->raycast.color = (data->raycast.color >> 1) & 8355711;
		data->buf[y][x] = data->raycast.color;
		data->re_buf = 1;
		y++;
	}
}
