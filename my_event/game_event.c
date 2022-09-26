/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:08:17 by alukongo          #+#    #+#             */
/*   Updated: 2022/09/26 21:53:28 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

void	move_back_forward(t_data *data)
{
	if (data->go_forwar == 1)
	{
		if (data->map[(int)(data->pos_x
			+ data->dir_x * data->movespeed)][(int)(data->pos_y)] == '0')
			data->pos_x += data->dir_x * data->movespeed;
		if (data->map[(int)(data->pos_x)][(int)(data->pos_y +
		data->dir_y * data->movespeed)] == '0')
			data->pos_y += data->dir_y * data->movespeed;
	}
	else if (data->go_back == 1)
	{
		if (data->map[(int)(data->pos_x
			- data->dir_x * data->movespeed)][(int)(data->pos_y)] == '0')
			data->pos_x -= data->dir_x * data->movespeed;
		if (data->map[(int)(data->pos_x)][(int)(data->pos_y -
		data->dir_y * data->movespeed)] == '0')
			data->pos_y -= data->dir_y * data->movespeed;
	}
}

void	move_left_right(t_data *data)
{
	if (data->go_left == 1)
	{
		if (data->map[(int)(data->pos_x
			- data->dir_y * data->movespeed)][(int)(data->pos_y)] == '0')
			data->pos_x -= data->dir_y * data->movespeed;
		if (data->map[(int)(data->pos_x)][(int)(data->pos_y +
		(data->dir_x * data->movespeed * 2))] == '0')
			data->pos_y += data->dir_x * data->movespeed;
	}
	else if (data->go_right == 1)
	{
		if (data->map[(int)(data->pos_x + (data->dir_y *
		data->movespeed * 2))][(int)(data->pos_y)] == '0')
			data->pos_x += data->dir_y * (data->movespeed);
		if(data->map[(int)(data->pos_x)][(int)(data->pos_y -
		(data->dir_x * data->movespeed * 2))] == '0')
			data->pos_y -= data->dir_x * data->movespeed;
	}
}

void	rotation(t_data *data)
{
	double	oldDirX;
	double	oldPlaneX;

	oldPlaneX = data->plane_x;
	oldDirX = data->dir_x;
	if (data->right_rotate == 1)
	{
		data->dir_x = data->dir_x * cos(-data->rotspeed)
			- data->dir_y * sin(-data->rotspeed);
		data->dir_y = oldDirX * sin(-data->rotspeed)
			+ data->dir_y * cos(-data->rotspeed);
		data->plane_x = data->plane_x * cos(-data->rotspeed)
			- data->plane_y * sin(-data->rotspeed);
		data->plane_y = oldPlaneX * sin(-data->rotspeed)
			+ data->plane_y * cos(-data->rotspeed);
	}
	else if (data->left_rotate == 1)
	{
		data->dir_x = data->dir_x * cos(data->rotspeed)
			- data->dir_y * sin(data->rotspeed);
		data->dir_y = oldDirX * sin(data->rotspeed)
			+ data->dir_y * cos(data->rotspeed);
		data->plane_x = data->plane_x * cos(data->rotspeed)
			- data->plane_y * sin(data->rotspeed);
		data->plane_y = oldPlaneX * sin(data->rotspeed)
			+ data->plane_y * cos(data->rotspeed);
	}
}

void	my_direction(t_data *data, int key)
{
	if (key == K_W || key == K_S)
	{
		if (key == K_W)
			data->go_forwar = 1;
		else if (key == K_S)
			data->go_back = 1;
		move_back_forward(data);
	}
	if (key == K_A || key == K_D)
	{
		if (key == K_A)
			data->go_left = 1;
		else if (key == K_D)
			data->go_right = 1;
		move_left_right(data);
	}
	if (key == K_RIGHT || key == K_LEFT)
	{
		if (key == K_RIGHT)
			data->right_rotate = 1;
		else if (key == K_LEFT)
			data->left_rotate = 1;
		rotation(data);
	}
}

int	key_press(int key, t_data *data)
{
	my_direction(data, key);
	if (key == K_ESC)
	{
		close_my_game(data, 1);
		exit(0);
	}
	mlx_clear_window(data->mlx, data->win);
	start_game(data);
	return (0);
}
