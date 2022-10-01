/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:43:45 by alukongo          #+#    #+#             */
/*   Updated: 2022/10/01 21:10:36 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

/**
 * @brief i check if is a digit and if im bigger than 0 and smaller than 255
 * 
 * @param str 
 * @return int 
 */
int	ft_isdigit(char *str)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(str);
	while (i < size)
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (ERROR);
	}
	if (ft_atoi(str) > 255)
		return (ERROR);
	return (GOOD);
}
