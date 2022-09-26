/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:46:55 by alukongo          #+#    #+#             */
/*   Updated: 2022/09/26 15:42:21 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

int	ft_convert_color(char *str)
{
	char	**rgb;
	int		res;

	rgb = ft_split(str, ',');
	res = (ft_atoi(rgb[0]) * 256 * 256) + (ft_atoi(rgb[1]) * 256) + ft_atoi(rgb[2]);
	my_free_alloc(rgb);
	return (res);
}
