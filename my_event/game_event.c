/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:08:17 by alukongo          #+#    #+#             */
/*   Updated: 2022/09/26 19:02:46 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

void	move_back_forward(t_data *data)
{
	if (data->go_forwar == 1)
	{
		if (data->map[(int)(data->posX +
		data->dirX * data->moveSpeed)][(int)(data->posY)] == '0')
			data->posX += data->dirX * data->moveSpeed;
		if (data->map[(int)(data->posX)][(int)(data->posY +
		data->dirY * data->moveSpeed)] == '0')
			data->posY += data->dirY * data->moveSpeed;
	}
	else if (data->go_back == 1)
	{
		if (data->map[(int)(data->posX -
		data->dirX * data->moveSpeed)][(int)(data->posY)] == '0')
			data->posX -= data->dirX * data->moveSpeed;
		if (data->map[(int)(data->posX)][(int)(data->posY -
		data->dirY * data->moveSpeed)] == '0')
			data->posY -= data->dirY * data->moveSpeed;
	}
}

void	move_left_right(t_data *data)
{
	if (data->go_left == 1)
	{
		if (data->map[(int)(data->posX -
		data->dirY * data->moveSpeed)][(int)(data->posY)] == '0')
			data->posX -= data->dirY * data->moveSpeed;
		if (data->map[(int)(data->posX)][(int)(data->posY +
		(data->dirX * data->moveSpeed * 2))] == '0')
			data->posY += data->dirX * data->moveSpeed;
	}
	else if (data->go_right == 1)
	{
		if (data->map[(int)(data->posX + (data->dirY *
		data->moveSpeed * 2))][(int)(data->posY)] == '0')
			data->posX += data->dirY * (data->moveSpeed);
		if(data->map[(int)(data->posX)][(int)(data->posY -
		(data->dirX * data->moveSpeed * 2))] == '0')
			data->posY -= data->dirX * data->moveSpeed;
	}
}

void	rotation(t_data *data)
{
	double oldDirX = data->dirX;
	double oldPlaneX = data->planeX;

	if (data->right_rotate == 1)
	{
		data->dirX = data->dirX * cos(-data->rotSpeed) -
		data->dirY * sin(-data->rotSpeed);
		data->dirY = oldDirX * sin(-data->rotSpeed) +
		data->dirY * cos(-data->rotSpeed);
		data->planeX = data->planeX * cos(-data->rotSpeed) -
		data->planeY * sin(-data->rotSpeed);
		data->planeY = oldPlaneX * sin(-data->rotSpeed) +
		data->planeY * cos(-data->rotSpeed);
	}
	else if (data->left_rotate == 1)
	{
		data->dirX = data->dirX * cos(data->rotSpeed) -
		data->dirY * sin(data->rotSpeed);
		data->dirY = oldDirX * sin(data->rotSpeed) +
		data->dirY * cos(data->rotSpeed);
		data->planeX = data->planeX * cos(data->rotSpeed) -
		data->planeY * sin(data->rotSpeed);
		data->planeY = oldPlaneX * sin(data->rotSpeed) +
		data->planeY * cos(data->rotSpeed);
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
	if(key == K_A || key == K_D)
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
