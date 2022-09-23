/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:58:14 by alukongo          #+#    #+#             */
/*   Updated: 2022/09/23 11:43:07 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

/*si c'est une des tectures ou couleur je l'attribue a mes variable dans ma 
structure */

int	init_texture_and_color(t_data *data, int nb_data)
{
	int i;

	i = -1;
	while (data->file[++i] && nb_data < 6)
	{
		if (!ft_strncmp(data->file[i], "SO ./", 5))
			data->SO = data->file[i];
		else if (!ft_strncmp(data->file[i], "NO ./", 5))
			data->NO = data->file[i];
		else if (!ft_strncmp(data->file[i], "WE ./", 5))
			data->WE = data->file[i];
		else if (!ft_strncmp(data->file[i], "EA ./", 5))
			data->EA = data->file[i] + 5;
		else if (!ft_strncmp(data->file[i], "F ", 2))
			data->color_floor = data->file[i];
		else if (!ft_strncmp(data->file[i], "C ", 2))
			data->color_ceiling = data->file[i];
		else if (ft_strncmp(data->file[i], "\n", 2))
			return (ERROR);
		if (ft_strncmp(data->file[i], "\n", 2))
			nb_data++;
	}
	if (nb_data < 6)
		return (ERROR);
	return (i);
}

/*void init_to_null(t_data *data)
{
	data->SO = NULL;
	data->NO = NULL;
	data->WE = NULL;
	data->EA = NULL;
	data->color_floor = NULL;
	data->color_ceiling = NULL;
}*/

/*je dois maintenant parcourir le tableau jusque a ce que 
j'obtienne toutes mes textures et couleurs*/
int	check_texture(t_data *data)
{
	int nb_data;

	nb_data = 0;
	data->begin_map = init_texture_and_color(data, nb_data);
	if (data->file[data->begin_map] && data->file[data->begin_map][0]== '\n')
	{
		while (data->file[data->begin_map] && data->file[data->begin_map][0] == '\n')
			data->begin_map++;
	}
	else
		return (ERROR);
	if (!data->file[data->begin_map])
		return (ERROR);
	return (GOOD);
}