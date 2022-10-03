/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:46:55 by alukongo          #+#    #+#             */
/*   Updated: 2022/10/03 13:14:04 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

int	ft_convert_color(char *str)
{
	char	**rgb;
	int		res;

	rgb = ft_split(str, ',');
	res = (ft_atoi(rgb[0]) * 256 * 256)
		+ (ft_atoi(rgb[1]) * 256) + ft_atoi(rgb[2]);
	my_free_alloc(rgb);
	return (res);
}

void	replace_by(char **tab, char old, char new)
{
	int	i;
	int	j;
	int	height;

	height = ft_tab_height(tab);
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < ft_strlen_nl(tab[i]))
		{
			if (tab[i][j] == old)
				tab[i][j] = new;
			j++;
		}
		i++;
	}
}
