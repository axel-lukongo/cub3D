/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:52:43 by alukongo          #+#    #+#             */
/*   Updated: 2022/09/29 21:07:13 by alukongo         ###   ########.fr       */
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

int	check_color(t_data *data)
{
	char	**str;

	str = ft_split(data->color_ceil, ',');
	if (str[0] && str[1] && str[2] && !str[3])
	{
		if (ft_isdigit(str[0]) > 0 && ft_isdigit(str[1]) > 0
			&& ft_isdigit(str[2]) > 0)
		{
			my_free_alloc(str);
			str = ft_split(data->color_floor, ',');
			if (str[0] && str[1] && str[2])
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

int	check_e(char *str)
{
	char	**tab;

	tab = ft_split(str, ' ');
	if (tab[2] && tab[2][0] != '\n')
	{
		my_free_alloc(tab);
		return (0);
	}
	my_free_alloc(tab);
	return (GOOD);
}
