/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_position.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 20:02:37 by alukongo          #+#    #+#             */
/*   Updated: 2022/09/22 20:03:03 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

void start_orientation(t_data *data, int i, int j)
{
	if (data->map[i][j] == 'N')
	{
		data->planeY = 0.66;
		data->dirX = -1;
		data->dirY = 0.0;
		data->planeX = 0.0;
	}
	else if (data->map[i][j] == 'S')
	{
		data->planeY = -0.66;
		data->dirX = 1;
		data->dirY = 0.0;
		data->planeX = 0.0;
	}
	else if (data->map[i][j] == 'E')
	{
		data->planeX = 0.66;
		data->dirY = 1;
		data->dirX = 0.0;
		data->planeY = 0.0;
	}
	else if (data->map[i][j] == 'W')
	{
		data->planeX = -0.66;
		data->dirY = -1;
		data->dirX = 0.0;
		data->planeY = 0.0;
	}
}


int start_position(t_data *data, char value)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->row - (data->begin_map))
	{
		j = -1;
		while(++j < ft_strlen2(data->map[i]))
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S' || 
				data->map[i][j] == 'E' || data->map[i][j] == 'W')
			{
				if (value == 'X')
					return (i);
				else
				{
					start_orientation(data, i, j);
					data->map[i][j] = '0';
					return(j);
				}
			}
		}
	}
	return (1);
}