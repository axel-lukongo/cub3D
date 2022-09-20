/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:29:18 by alukongo          #+#    #+#             */
/*   Updated: 2022/09/20 20:35:21 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void define_step(t_data *data)
{
	if (data->raycast.rayDirX < 0)
	{
		data->raycast.stepX = -1;
		data->raycast.sideDistX = (data->posX - data->raycast.mapX) * data->raycast.deltaDistX;
	}
	else
	{
		data->raycast.stepX = 1;
		data->raycast.sideDistX = (data->raycast.mapX + 1.0 - data->posX) * data->raycast.deltaDistX;
	}
	if (data->raycast.rayDirY < 0)
	{
		data->raycast.stepY = -1;
		data->raycast.sideDistY = (data->posY - data->raycast.mapY) * data->raycast.deltaDistY;
	}
	else
	{
		data->raycast.stepY = 1;
		data->raycast.sideDistY = (data->raycast.mapY + 1.0 - data->posY) * data->raycast.deltaDistY;
	}
}

void define_hit(t_data *data)
{
	while (data->raycast.hit == 0)
	{
		//jump to next map square, OR in x-direction, OR in y-direction
		if (data->raycast.sideDistX < data->raycast.sideDistY)
		{
			data->raycast.sideDistX += data->raycast.deltaDistX;
			data->raycast.mapX += data->raycast.stepX;
			data->raycast.side = 0;
		}
		else
		{
			data->raycast.sideDistY += data->raycast.deltaDistY;
			data->raycast.mapY += data->raycast.stepY;
			data->raycast.side = 1;
		}
		//Check if ray has data->raycast.hit a wall
		if (data->map[data->raycast.mapX][data->raycast.mapY] > '0') data->raycast.hit = 1;
	}
}
