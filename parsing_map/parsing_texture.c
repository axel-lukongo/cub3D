/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:58:14 by alukongo          #+#    #+#             */
/*   Updated: 2022/09/26 21:48:52 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

/*si c'est une des tectures ou couleur je l'attribue a mes variable dans ma 
structure */

int	check_file(t_data *data)
{
	int	fd;

	fd = open(data->so, O_RDONLY);
	if (fd < 0)
		return (ERROR);
	close(fd);
		fd = open(data->no, O_RDONLY);
	if (fd < 0)
		return (ERROR);
	close(fd);
	fd = open(data->ea, O_RDONLY);
	if (fd < 0)
		return (ERROR);
	close(fd);
	fd = open(data->we, O_RDONLY);
	if (fd < 0)
		return (ERROR);
	close(fd);
	return (GOOD);
}

int	init_texture_and_color(t_data *data, int nb_data)
{
	int	i;

	i = -1;
	while (data->file[++i] && nb_data < 6)
	{
		if (!ft_strncmp(data->file[i], "SO ./", 5))
			data->so = my_cpy(data->so, data->file[i], "SO ./");
		else if (!ft_strncmp(data->file[i], "NO ./", 5))
			data->no = my_cpy(data->so, data->file[i], "NO ./");
		else if (!ft_strncmp(data->file[i], "WE ./", 5))
			data->we = my_cpy(data->so, data->file[i], "WE ./");
		else if (!ft_strncmp(data->file[i], "EA ./", 5))
			data->ea = my_cpy(data->so, data->file[i], "EA ./");
		else if (!ft_strncmp(data->file[i], "F ", 2))
			data->color_floor = my_cpy(data->so, data->file[i], "F ");
		else if (!ft_strncmp(data->file[i], "C ", 2))
			data->color_ceiling = my_cpy(data->so, data->file[i], "C ");
		else if (ft_strncmp(data->file[i], "\n", 2))
			return (ERROR);
		if (ft_strncmp(data->file[i], "\n", 2))
			nb_data++;
	}
	if (nb_data < 6)
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
	data->begin_map = init_texture_and_color(data, nb_data);
	if (data->begin_map == ERROR)
		return (ERROR);
	fd = check_file(data);
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
