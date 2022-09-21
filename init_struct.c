/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:28:57 by alukongo          #+#    #+#             */
/*   Updated: 2022/09/21 20:40:04 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"



//i init my variable
void	init_struct(t_data *data)
{
	data->dirX = -1.0;
	data->dirY = 0.0;
	data->planeX = 0.0;
	data->planeY = 0.66;
	data->re_buf = 0;
	data->moveSpeed = 0.05;
	data->rotSpeed = 0.05;
	data->left_rotate = 0;
	data->right_rotate = 0;
	data->go_forwar = 0;
	data->go_back = 0;
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
		if (!data->texture[i])
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




void init_raycast(t_data *data, int x)
{
	data->raycast.cameraX = 2 * x / (double)width - 1;
		data->raycast.rayDirX = data->dirX + data->planeX * data->raycast.cameraX;
		data->raycast.rayDirY = data->dirY + data->planeY * data->raycast.cameraX;
		data->raycast.mapX = (int)data->posX;
		data->raycast.mapY = (int)data->posY;
		data->raycast.deltaDistX = fabs(1 / data->raycast.rayDirX);
		data->raycast.deltaDistY = fabs(1 / data->raycast.rayDirY);
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
	data->texture = (int **)malloc(sizeof(int *) * texHeight);
	if (!data->texture)
		return (ERROR);
	if(init_texture(data) == ERROR)
		return(ERROR);
	return (GOOD);
}
