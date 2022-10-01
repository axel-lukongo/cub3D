/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:43:45 by alukongo          #+#    #+#             */
/*   Updated: 2022/10/01 18:52:29 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"
//good
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
