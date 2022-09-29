/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:58:14 by alukongo          #+#    #+#             */
/*   Updated: 2022/09/29 14:00:42 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

/**
 * @brief here i initialize uniquely the texture
 * 
 * @param data 
 * @param i 
 * @return int 
 */
int	init_texture2(t_data *data, int i)
{
	if (!ft_strncmp(data->file[i], "SO ./", 5))
	{
		if (!data->so)
			data->so = my_cpy(data->so, data->file[i], "SO ./");
		return (2);
	}
	else if (!ft_strncmp(data->file[i], "NO ./", 5))
	{
		if (!data->no)
			data->no = my_cpy(data->so, data->file[i], "NO ./");
		return (2);
	}
	else if (!ft_strncmp(data->file[i], "WE ./", 5))
	{
		if (!data->we)
			data->we = my_cpy(data->so, data->file[i], "WE ./");
		return (2);
	}
	else if (!ft_strncmp(data->file[i], "EA ./", 5))
	{
		if (!data->ea)
			data->ea = my_cpy(data->so, data->file[i], "EA ./");
		return (2);
	}
	return (1);
}

/**
 * @brief lorsque je vois la tecture ou la couleur correspondant
 * je l'attribu a la variable approprier de ma structure si a la fin nb data < 6
 * alors je n'ai pas eu mes 6 information donc ERROR
 * 
 * @param data 
 * @param nb_data 
 * @param i 
 * @return int 
 */
int	init_texture_and_color(t_data *data, int nb_data, int i)
{
	while (data->file[++i] && nb_data < 6)
	{
		if (init_texture2(data, i) != 2)
		{
			if (!ft_strncmp(data->file[i], "F ", 2))
			{
				if (!data->color_floor)
					data->color_floor = my_cpy(data->so, data->file[i], "F ");
			}
			else if (!ft_strncmp(data->file[i], "C ", 2))
			{
				if (!data->color_ceiling)
					data->color_ceiling = my_cpy(data->so, data->file[i], "C ");
			}
			else if (ft_strncmp(data->file[i], "\n", 2))
				return (ERROR);
		}
		if (ft_strncmp(data->file[i], "\n", 2))
			nb_data++;
	}
	if (nb_data < 6 || check_info(data) == ERROR)
		return (ERROR);
	return (i);
}

/*je dois maintenant parcourir le tableau jusque a ce que 
j'obtienne toutes mes textures et couleurs*/
int	check_texture(t_data *data)
{
	int	nb_data;
	int	fd;

	nb_data = 0;
	data->begin_map = init_texture_and_color(data, nb_data, -1);
	if (data->begin_map == ERROR)
		return (ERROR);
	fd = check_access_file(data);
	if (data->file[data->begin_map] && data->file[data->begin_map][0] == '\n')
	{
		while (data->file[data->begin_map]
			&& data->file[data->begin_map][0] == '\n')
			data->begin_map++;
	}
	else
		return (ERROR);
	if (!data->file[data->begin_map] || fd < 0)
		return (ERROR);
	return (GOOD);
}
