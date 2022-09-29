/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 20:44:05 by alukongo          #+#    #+#             */
/*   Updated: 2022/09/29 11:29:45 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

int	ft_keys_release(int keycode, t_data	*data)
{
	if (keycode == K_W)
		data->go_forwar = 0;
	else if (keycode == K_S)
		data->go_back = 0;
	if (keycode == K_RIGHT)
		data->right_rotate = 0;
	else if (keycode == K_LEFT)
		data->left_rotate = 0;
	if (keycode == K_A)
		data->go_left = 0;
	else if (keycode == K_D)
		data->go_right = 0;
	return (0);
}

int	mouse_event(t_data *data)
{
	close_my_game(data, 1);
	return (1);
}
