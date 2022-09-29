/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_position.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 20:02:37 by alukongo          #+#    #+#             */
/*   Updated: 2022/09/29 11:40:42 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

void	direction_plane(t_data *data, char player_orientation)
{
	if (player_orientation == 'N' || player_orientation == 'S')
	{
		data->dir_y = 0.0;
		data->plane_x = 0.0;
	}
	else if (player_orientation == 'E' || player_orientation == 'W')
	{
		data->dir_x = 0.0;
		data->plane_y = 0.0;
	}
}

void	init_cardinal_point(t_data *data)
{
	data->cardinal[0] = data->no;
	data->cardinal[1] = data->so;
	data->cardinal[2] = data->ea;
	data->cardinal[3] = data->we;
}

void	start_orientation(t_data *data, char player_orientation)
{
	init_cardinal_point(data);
	if (player_orientation == 'N')
	{
		data->plane_y = 0.66;
		data->dir_x = -1;
	}
	else if (player_orientation == 'S')
	{
		data->plane_y = -0.66;
		data->dir_x = 1;
	}
	else if (player_orientation == 'E')
	{
		data->plane_x = 0.66;
		data->dir_y = 1;
	}
	else if (player_orientation == 'W')
	{
		data->plane_x = -0.66;
		data->dir_y = -1;
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
					return (i + 0.0005);
				else
				{
					start_orientation(data, data->map[i][j]);
					data->map[i][j] = '0';
					return (j + 0.0005);
				}
			}
		}
	}
	return (1);
}
