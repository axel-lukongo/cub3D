/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_cpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 21:33:17 by alukongo          #+#    #+#             */
/*   Updated: 2022/09/29 20:29:30 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

char	*my_cpy(char *dest, char *src, char *to_skip)
{
	int	i;

	i = 0;
	dest = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!dest)
		return (NULL);
	while (src[i] == ' ')
		i++;
	if (ft_strncmp(&src[i], to_skip, ft_strlen(to_skip)))
		return (NULL);
	i += ft_strlen(to_skip);
	while (src[i] == ' ')
		i++;
	dest = ft_strncpy(dest, src + i, ft_strlen2(src));
	return (dest);
}
