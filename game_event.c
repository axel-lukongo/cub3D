/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:08:17 by alukongo          #+#    #+#             */
/*   Updated: 2022/09/20 16:05:36 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

int	ft_keys_release(int	keycode, t_data	*data)
{
	if (keycode == K_W)  //linux QWERTY: 119, linux AZERTY: 122
	{
		// printf("forward released\n");
		data->go_forwar = 0;
	}
	else if (keycode == K_S)
	{
		// printf("S = back released\n");
		data->go_back = 0;
	}
	if (keycode == K_RIGHT)
		data->right_rotate = 0;
	else if (keycode == K_LEFT)  //linux QWERTY: 97, linux AZERTY: 113
		data->left_rotate = 0;
	// else if (keycode == XK_Right)
	// {
	// 	printf("release rotate right\n");
	// 	data->rot_right = 0;
	// }
	// else if (keycode == XK_Left)
	// {
	// 	printf("release rotate left\n");
	// 	data->rot_left = 0;
	// }
	return (0);
}

int	key_press(int key, t_data *data)
{
	printf("---------dirX: %f,  dirY: %f ------\n", data->dirX, data->dirY);
	if (key == K_W)
	{
		data->go_forwar = 1;
		if (data->map[(int)(data->posX + data->dirX * data->moveSpeed)][(int)(data->posY)] == '0')
			data->posX += data->dirX * data->moveSpeed;
		if (data->map[(int)(data->posX)][(int)(data->posY + data->dirY * data->moveSpeed)] == '0')
			data->posY += data->dirY * data->moveSpeed;
	}
	//move backwards if no wall behind you
	if (key == K_S)
	{
		data->go_back = 1;
		if (data->map[(int)(data->posX - data->dirX * data->moveSpeed)][(int)(data->posY)] == '0')
			data->posX -= data->dirX * data->moveSpeed;
		if (data->map[(int)(data->posX)][(int)(data->posY - data->dirY * data->moveSpeed)] == '0')
			data->posY -= data->dirY * data->moveSpeed;
	}
	//rotate to the right
	if (key == K_RIGHT)
	{
		//both camera direction and camera plane must be rotated
		data->right_rotate = 1;
		double oldDirX = data->dirX;
		data->dirX = data->dirX * cos(-data->rotSpeed) - data->dirY * sin(-data->rotSpeed);
		data->dirY = oldDirX * sin(-data->rotSpeed) + data->dirY * cos(-data->rotSpeed);
		double oldPlaneX = data->planeX;
		data->planeX = data->planeX * cos(-data->rotSpeed) - data->planeY * sin(-data->rotSpeed);
		data->planeY = oldPlaneX * sin(-data->rotSpeed) + data->planeY * cos(-data->rotSpeed);
	}
	//rotate to the left
	if (key == K_LEFT)
	{
		//both camera direction and camera plane must be rotated
		data->left_rotate = 1;
		double oldDirX = data->dirX;
		data->dirX = data->dirX * cos(data->rotSpeed) - data->dirY * sin(data->rotSpeed);
		data->dirY = oldDirX * sin(data->rotSpeed) + data->dirY * cos(data->rotSpeed);
		double oldPlaneX = data->planeX;
		data->planeX = data->planeX * cos(data->rotSpeed) - data->planeY * sin(data->rotSpeed);
		data->planeY = oldPlaneX * sin(data->rotSpeed) + data->planeY * cos(data->rotSpeed);
	}
	if (key == K_ESC)
	{
		close_my_game(data);
		exit(0);
	}
	mlx_clear_window(data->mlx, data->win);
	start_game(data);
	return (0);
}
