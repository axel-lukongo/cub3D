/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:58:14 by alukongo          #+#    #+#             */
/*   Updated: 2022/09/29 21:01:24 by alukongo         ###   ########.fr       */
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
static int	init_texture2(t_data *data, char *str, int index)
{
	if (!ft_strncmp(&str[index], "SO ", 3))
	{
		if (!data->so)
			data->so = my_cpy(data->so, &str[index], "SO ");
		return (2);
	}
	else if (!ft_strncmp(&str[index], "NO ", 3))
	{
		if (!data->no)
			data->no = my_cpy(data->no, &str[index], "NO ");
		return (2);
	}
	else if (!ft_strncmp(&str[index], "WE ", 3))
	{
		if (!data->we)
			data->we = my_cpy(data->we, &str[index], "WE ");
		return (2);
	}
	else if (!ft_strncmp(&str[index], "EA ", 3))
	{
		if (!data->ea)
			data->ea = my_cpy(data->ea, &str[index], "EA ");
		return (2);
	}
	return (1);
}

/**
 * @brief here i init my color
 * 
 * @param data 
 * @param index 
 */
static void	init_color(t_data *data, int index)
{
	if (!ft_strncmp(&data->s[index], "F ", 2))
	{
		if (!data->color_floor)
			data->color_floor = my_cpy(data->tm, &data->s[index], "F ");
	}
	else if (!ft_strncmp(&data->s[index], "C ", 2))
	{
		if (!data->color_ceil)
			data->color_ceil = my_cpy(data->tm, &data->s[index], "C ");
	}
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
static int	init_texture_and_color(t_data *data, int nb_data, int i, int index)
{
	while (data->file[++i] && nb_data < 6)
	{
		index = 0;
		data->s = data->file[i];
		while (data->s[index] == ' ')
			index++;
		if (data->s[index] == '.' || data->s[index] == '/' || !check_e(data->s))
			return (ERROR);
		if (init_texture2(data, data->s, index) != 2)
		{
			if (!ft_strncmp(&data->s[index], "F ", 2)
				|| !ft_strncmp(&data->s[index], "C ", 2))
			{
				init_color(data, index);
			}
			else if (ft_strncmp(&data->s[index], "\n", 2))
				return (ERROR);
		}
		if (ft_strncmp(&data->s[index], "\n", 2))
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
	data->begin_map = init_texture_and_color(data, nb_data, -1, 0);
	if (data->begin_map == ERROR)
		return (ERROR);
	fd = check_access_file(data);
	if ((data->file[data->begin_map] && data->file[data->begin_map][0] == '\n')
		|| (data->file[data->begin_map][0] == ' '))
	{
		while ((data->file[data->begin_map]
				&& data->file[data->begin_map][0] == '\n')
				|| (data->file[data->begin_map][0] == ' '))
			data->begin_map++;
	}
	else
		return (ERROR);
	if (!data->file[data->begin_map] || fd < 0)
		return (ERROR);
	return (GOOD);
}
