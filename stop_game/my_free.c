/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:19:01 by alukongo          #+#    #+#             */
/*   Updated: 2022/09/28 16:28:37 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

void	free_texture(t_data *data)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		free(data->texture[i]);
		i++;
	}
	free(data->texture);
}

void	close_my_game(t_data *data, int flag)
{
	if (data->file)
		free_file(data);
	if (flag > 0)
	{
		free_texture(data);
		free(data->cardinal);
	}
	mlx_destroy_image(data->mlx, data->img.img);
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(1);
}

void	free_file(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->row)
	{
		free(data->file[i]);
		i++;
	}
	free(data->map);
	free(data->file);
	free(data->so);
	free(data->ea);
	free(data->no);
	free(data->we);
	free(data->color_ceiling);
	free(data->color_floor);
}

void	my_free_alloc(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
