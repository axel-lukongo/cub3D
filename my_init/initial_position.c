/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_position.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 20:02:37 by alukongo          #+#    #+#             */
/*   Updated: 2022/09/26 15:38:33 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

void	direction_plane(t_data *data, char player_orientation)
{
	if (player_orientation == 'N' || player_orientation == 'S')
	{
		data->dirY = 0.0;
		data->planeX = 0.0;
	}
	else if (player_orientation == 'E' || player_orientation == 'W')
	{
		data->dirX = 0.0;
		data->planeY = 0.0;
	}
}

void	start_orientation(t_data *data, char player_orientation)
{
	if (player_orientation == 'N')
	{
		data->planeY = 0.66;
		data->dirX = -1;
	}
	else if (player_orientation == 'S')
	{
		data->planeY = -0.66;
		data->dirX = 1;
	}
	else if (player_orientation == 'E')
	{
		data->planeX = 0.66;
		data->dirY = 1;
	}
	else if (player_orientation == 'W')
	{
		data->planeX = -0.66;
		data->dirY = -1;
	}
	direction_plane(data, player_orientation);
}

float	set_position(t_data *data, char value)
{
	int	i;
	int	j;

	i = -1;
	while (++i < (data->row - (data->begin_map)))
	{
		j = -1;
		while (++j < ft_strlen2(data->map[i]))
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S' ||
				data->map[i][j] == 'E' || data->map[i][j] == 'W')
			{
				if (value == 'X')
					return (i + 0.05);
				else
				{
					start_orientation(data, data->map[i][j]);
					data->map[i][j] = '0';
					return (j + 0.5);
				}
			}
		}
	}
	return (1);
}
