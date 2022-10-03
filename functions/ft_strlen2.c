/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:13:43 by alukongo          #+#    #+#             */
/*   Updated: 2022/10/03 13:13:49 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

int	ft_strlen_nl(char *s)
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
