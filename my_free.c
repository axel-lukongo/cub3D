/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:19:01 by alukongo          #+#    #+#             */
/*   Updated: 2022/09/19 20:21:46 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

void	destroy(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img.img);
	// mlx_destroy_image(data->mlx, data->wall);
	// mlx_destroy_image(data->mlx, data->collect);
	// mlx_destroy_image(data->mlx, data->perso);
	// mlx_destroy_image(data->mlx, data->door);
	// mlx_destroy_image(data->mlx, data->flor);
}

void	close_my_game(t_data *data)
{
	free_map(data);
	destroy(data);
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(1);
}


void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->row)
	{
		free(data->file[i]);
		if(i < 8)
			free(data->texture[i]);
		i++;
	}
	free(data->map);
	free(data->file);
	free(data->texture);
}
