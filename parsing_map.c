
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 15:29:22 by alukongo          #+#    #+#             */
/*   Updated: 2022/08/26 17:37:24 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

/**
 * @brief here i check if i have N,S,E,W one time in the map
 * 
 * @param data 
 * @return int 
 */
int check_doublons(t_data *data)
{
	int	i;
	int	j;
	int count;

	i = data->begin_map - 1;
	count = 0;
	while (1)
	{
		j = -1;
		if (!data->file[++i])
			break;
		while(++j < ft_strlen2(data->file[i]))
		{
			if (data->file[i][j] == 'N' || data->file[i][j] == 'S'
			|| data->file[i][j] == 'E' || data->file[i][j] == 'W')
			{
				data->posX = j;
				data->posY = i;
				count++;
			}
		}
	}
	if (count > 1 || count < 1)
		return (ERROR);
	return (GOOD);
}

/**
 * @brief in this function i check if the case above is 1 or 0
 * 
 * @param map 
 * @param i 
 * @param j 
 * @return int 
 */

int check_up(char **map, int i, int j)
{
	if (i > 0)
	{
		if (j < ft_strlen(map[i - 1]))
		{
			if (map[i - 1][j] != '1' && map[i - 1][j] != '0' && map[i - 1][j] != 'N' 
		&& map[i - 1][j] != 'S' && map[i - 1][j] != 'E' && map[i - 1][j] != 'W')// i look if the above case was 1 or 0
				return (ERROR);
		}
		else
			return (ERROR);
	}
	else
		return (ERROR);
	return (GOOD);
}

/**
 * @brief in this function i check if the cases below is 1 or 0
 *
 * @param map 
 * @param i 
 * @param j 
 * @return int 
 */

int check_down(char **map, int i, int j)
{
	if (j < ft_strlen(map[i + 1]))
	{
		if (map[i + 1][j] != '1' && map[i + 1][j] != '0' && map[i + 1][j] != 'N' 
		&& map[i + 1][j] != 'S' && map[i + 1][j] != 'E' && map[i + 1][j] != 'W')//i look if the below case is 1 or 0
			return (ERROR);
	}
	else
		return (ERROR);
	return (GOOD);
}


/**
 * @brief in this fonction i check the content and the border of the map
 * if i have somthing different of 1 or 0 i return a error
 * 
 * @param map 
 * @param i 
 * @param j 
 * @return int 
 */
int	verif_map(char **map, int i, int j)
{
	if (map[i][j] == '0' || (map[i][j] == 'N' 
		|| map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W'))
	{
		if (map[i][j - 1] != '1' && map[i][j - 1] != '0' && map[i][j - 1] != 'N' 
		&& map[i][j - 1] != 'S' && map[i][j - 1] != 'E' && map[i][j - 1] != 'W')//i look if the previous case was 1 or 0
			return (ERROR);
		if (map[i][j + 1] != '1' && map[i][j + 1] != '0' && map[i][j + 1] != 'N' 
		&& map[i][j + 1] != 'S' && map[i][j + 1] != 'E' && map[i][j + 1] != 'W')//i look if the next case is 1 or 0
			return (ERROR);
		if (check_up(map, i, j) == ERROR)
			return (ERROR);
		if (check_down(map, i, j) == ERROR)
			return (ERROR);
	}
	else if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'N' 
		&& map[i][j] != 'S' && map[i][j] != 'E' && map[i][j] != 'W')
		return (ERROR);
	return(GOOD);
}

int	check_content_map(char **map, t_data *data)
{
	int	i;
	int	j;

	i = data->begin_map - 1;
	if (check_doublons(data) == ERROR)
		return (ERROR);
	while (1)
	{
		j = 0;
		if (!map[++i])
			break;
		while (map[i] && map[i][j] == '\n')
			i++;
		while (map[i] && map[i][j] == ' ')
			j++;
		if (j >= ft_strlen(map[i]) || map[i][j] != '1' ||
			map[i][ft_strlen2(map[i]) - 1] != '1')//i check if my line begin by 1 and finish by 1
				return (ERROR);
		while (j < ft_strlen(map[i]) - 2)
		{
			if (verif_map(map, i, j++) == ERROR)
				return (ERROR);
		}
	}
	return (GOOD);
}
