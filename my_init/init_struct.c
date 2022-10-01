/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:28:57 by alukongo          #+#    #+#             */
/*   Updated: 2022/10/01 21:28:27 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

void	init_struct(t_data *data)
{
	data->cardinal = malloc(sizeof(char *) * 5 + 1);
	data->pos_x = set_position(data, 'X');
	data->pos_y = set_position(data, 'Y');
	data->re_buf = 0;
	data->movespeed = 0.05;
	data->rotspeed = 0.05;
	data->left_rotate = 0;
	data->right_rotate = 0;
	data->go_forwar = 0;
	data->go_back = 0;
	data->go_left = 0;
	data->go_right = 0;
}

//i init my texture
int	init_texture(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 8)
	{
		data->texture[i] = (int *)malloc(sizeof(int) * (TEXHEIGHT * TEXWIDTH));
		if (!data->texture[i])
			return (ERROR);
	}
	i = -1;
	while (++i < 8)
	{
		j = -1;
		while (++j < TEXHEIGHT * TEXWIDTH)
			data->buf[i][j] = 0;
	}
	return (GOOD);
}

void	init_raycast(t_data *data, int x)
{
	data->raycast.camera_x = 2 * x / (double)WIDTH - 1;
	data->raycast.ray_dir_x = data->dir_x + data->plane_x
		* data->raycast.camera_x;
	data->raycast.ray_dir_y = data->dir_y + data->plane_y
		* data->raycast.camera_x;
	data->raycast.map_x = (int)data->pos_x;
	data->raycast.map_y = (int)data->pos_y;
	data->raycast.delta_dist_x = fabs(1 / data->raycast.ray_dir_x);
	data->raycast.delta_dist_y = fabs(1 / data->raycast.ray_dir_y);
}

// i init the buffer
int	init_buf(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < HEIGHT)
	{
		j = -1;
		while (j++ < WIDTH)
		{
			data->buf[i][j] = 0;
		}
	}
	data->texture = (int **)malloc(sizeof(int *) * TEXHEIGHT);
	if (!data->texture)
		return (ERROR);
	if (init_texture(data) == ERROR)
		return (ERROR);
	return (GOOD);
}

void	init_null(t_data *data)
{
	data->map = NULL;
	data->file = NULL;
	data->mlx = NULL;
	data->win = NULL;
	data->texture = NULL;
	data->so = NULL;
	data->no = NULL;
	data->we = NULL;
	data->ea = NULL;
	data->color_floor = NULL;
	data->color_ceil = NULL;
}
