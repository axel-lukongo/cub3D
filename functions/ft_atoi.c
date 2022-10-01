/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 10:06:12 by alukongo          #+#    #+#             */
/*   Updated: 2022/10/01 18:52:32 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

//good
unsigned long int	ft_atoi(const char *str)
{
	long					i;
	int						signe;
	unsigned long long int	nbr;

	nbr = 0;
	signe = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '+')
			signe = signe * 1;
		if (str[i] == '-')
			signe = signe * (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - 48;
		i++;
	}
	nbr = nbr * signe;
	return (nbr);
}
