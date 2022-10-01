/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:52:43 by alukongo          #+#    #+#             */
/*   Updated: 2022/10/01 21:11:08 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

int	check_info(t_data *data)
{
	if (!data->ea)
		return (ERROR);
	if (!data->we)
		return (ERROR);
	if (!data->no)
		return (ERROR);
	if (!data->so)
		return (ERROR);
	if (!data->color_ceil)
		return (ERROR);
	if (!data->color_floor)
		return (ERROR);
	return (GOOD);
}

static int	check_color_util(char *str)
{
	int	size;
	int	i;
	int	count;

	count = 0;
	i = -1;
	size = ft_strlen(str);
	while (++i < size)
	{
		if (str[i] == ',')
			count++;
	}
	if (count != 2)
		return (0);
	return (GOOD);
}

/**
 * @brief here i check if i only have a digit in my RGB number,
 * and if i have only 2 ','
 * 
 * @param data 
 * @return int 
 */
int	check_color(t_data *data)
{
	char	**str;

	check_color_util(data->color_ceil);
	str = ft_split(data->color_ceil, ',');
	if (check_color_util(data->color_ceil))
	{
		if (ft_isdigit(str[0]) > 0 && ft_isdigit(str[1]) > 0
			&& ft_isdigit(str[2]) > 0)
		{
			my_free_alloc(str);
			str = ft_split(data->color_floor, ',');
			if (check_color_util(data->color_floor))
			{
				if (ft_isdigit(str[0]) > 0 && ft_isdigit(str[1]) > 0
					&& ft_isdigit(str[2]) > 0)
				{
					my_free_alloc(str);
					return (GOOD);
				}
			}
		}
	}
	my_free_alloc(str);
	return (ERROR);
}

/**
 * @brief here i check if the path is valid
 * 
 * @param data 
 * @return int 
 */
int	check_access_file(t_data *data)
{
	int		fd;

	fd = open(data->so + 2, O_RDONLY);
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
	if (fd < 0 || check_color(data) == ERROR)
		return (ERROR);
	close(fd);
	return (GOOD);
}

/**
 * @brief here i check if i have only 2 element for the texture
 * ((side of texture and name of texture))
 * i check if i have only 2 element for the color
 * (floor or ceiling and the RGB)
 * @param str 
 * @return int 
 */
int	check_e(char *str)
{
	char	**tab;

	tab = ft_split(str, ' ');
	if (ft_tab_height(tab) != 2 || ft_strlen_nl(tab[1]) < 4)
	{
		if (ft_tab_height(tab) == 3 && !ft_strncmp(tab[2], "\n", 1))
		{
			my_free_alloc(tab);
			return (GOOD);
		}
		my_free_alloc(tab);
		return (0);
	}
	my_free_alloc(tab);
	return (GOOD);
}
