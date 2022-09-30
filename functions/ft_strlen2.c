/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 17:28:33 by alukongo          #+#    #+#             */
/*   Updated: 2022/09/30 18:26:29 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

int	ft_strlen2(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] && s[i] != '\n')
			i++;
	}
	return (i);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
	}
	return (i);
}

int	ft_tab_height(char **tab)
{
	int	i;
	
	i = 0;
	if (tab[i])
	{
		while (tab[i])
			i++;
	}
	return (i);
}
