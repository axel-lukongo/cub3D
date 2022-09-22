/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_cpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 21:33:17 by alukongo          #+#    #+#             */
/*   Updated: 2022/09/22 21:39:13 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

int my_cpy(char *dest, char *src, char *to_skip, int n)
{
	int	i;
	
	i = 0
	dest = malloc(sizeof(char) * ft_strlen(src) + 1);
	if(!dest)
		return(ERROR);
	while(src[i] == ' ')
		i++;
	
}