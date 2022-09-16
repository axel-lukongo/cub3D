/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:28:57 by alukongo          #+#    #+#             */
/*   Updated: 2022/09/16 20:27:47 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

// int	g_img_width;
// int	g_img_height;

//i init my variable
void	init_struct(t_data *data)
{
	
	data->posX = 22.0;
	data->posY = 11.5;
	data->dirX = -1.0;
	data->dirY = 0.0;
	data->planeX = 0.0;
	data->planeY = 0.66;
	data->re_buf = 0;
	data->moveSpeed = 0.05;
	data->rotSpeed = 0.05;
}

//i init my texture
int init_texture(t_data *data)
{
	int i;
	int j;

	i = -1;
	while (++i < 8)
	{
		data->texture[i] = (int *)malloc(sizeof(int) * (texHeight * texWidth));
		if (!data->texture)
			return (ERROR);
	}
	i = -1;
	while (++i < 8)
	{
		j = -1;
		while (++j < texHeight * texWidth)
			data->buf[i][j] = 0;
	}
	return(GOOD);
}

// i init the buffer
int	init_buf(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < height)
	{
		j = -1;
		while (j++ < width)
			data->buf[i][j] = 0;
	}
	data->texture = (int **)malloc(sizeof(int *) * 8);
	if (!data->texture)
		return (ERROR);
	if(init_texture(data) == ERROR)
		return(ERROR);
	return (GOOD);
}
