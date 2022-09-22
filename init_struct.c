/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:28:57 by alukongo          #+#    #+#             */
/*   Updated: 2022/09/22 20:02:57 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"



//i init my variable

// void start_orientation(t_data *data, int i, int j)
// {
// 	if (data->map[i][j] == 'N')
// 	{
// 		data->planeY = 0.66;
// 		data->dirX = -1;
// 		data->dirY = 0.0;
// 		data->planeX = 0.0;
// 	}
// 	else if (data->map[i][j] == 'S')
// 	{
// 		data->planeY = -0.66;
// 		data->dirX = 1;
// 		data->dirY = 0.0;
// 		data->planeX = 0.0;
// 	}
// 	else if (data->map[i][j] == 'E')
// 	{
// 		data->planeX = 0.66;
// 		data->dirY = 1;
// 		data->dirX = 0.0;
// 		data->planeY = 0.0;
// 	}
// 	else if (data->map[i][j] == 'W')
// 	{
// 		data->planeX = -0.66;
// 		data->dirY = -1;
// 		data->dirX = 0.0;
// 		data->planeY = 0.0;
// 	}
// }


// int start_position(t_data *data, char value)
// {
// 	int	i;
// 	int	j;

// 	i = -1;
// 	while (++i < data->row - (data->begin_map))
// 	{
// 		j = -1;
// 		while(++j < ft_strlen2(data->map[i]))
// 		{
// 			if (data->map[i][j] == 'N' || data->map[i][j] == 'S' || 
// 				data->map[i][j] == 'E' || data->map[i][j] == 'W')
// 			{
// 				if (value == 'X')
// 					return (i);
// 				else
// 				{
// 					start_orientation(data, i, j);
// 					data->map[i][j] = '0';
// 					return(j);
// 				}
// 			}
// 		}
// 	}
// 	return (1);
// }

void	init_struct(t_data *data)
{
	data->posX = start_position(data, 'X');
	data->posY = start_position(data, 'Y');
	data->re_buf = 0;
	data->moveSpeed = 0.05;
	data->rotSpeed = 0.05;
	data->left_rotate = 0;
	data->right_rotate = 0;
	data->go_forwar = 0;
	data->go_back = 0;
	data->go_left = 0;
	data->go_right = 0;
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
		// printf("-----------data->posX: %f, data->posY: %f-----------\n",data->posX, data->posY);
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
