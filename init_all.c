/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 01:40:22 by alukongo          #+#    #+#             */
/*   Updated: 2022/09/22 18:11:36 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

/**
 * @brief in this function i save the number of the line under my map in row
 * 
 * @param file 
 * @param data 
 */

void	count_line(char *file, t_data *data)
{
	int		fd;
	int		nb_line;
	char	*str;

	nb_line = 0;
	fd = open(file, O_RDONLY);
	str = get_next_line(fd);
	data->col = 0;
	while (str)
	{
		if (ft_strlen(str) > data->col)
			data->col = ft_strlen(str);
		nb_line++;
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
	data->row = nb_line + 1;
}

/**
 * @brief in this function i allocate my matrice for contain the map
 * 
 * @param data is my structure where ia save all information
 * @param file is the name of the file who i gave when the exec
 * @param fd is the fd of the file
 */

void	allocate_map(t_data *data, char *file, int fd)
{
	if (fd < 0)
	{
		printf("Error\n");
		exit(1);
	}
	count_line(file, data);
	data->file = malloc(sizeof(char *) * data->row + 1);
	if (!data->file || data->row < 3)
	{
		free(data->file);
		printf("Error\n");
		exit(1);
	}
}

/**
 * @brief in this function i check if the name of the file finish by .cub
 * 
 * @param file 
 */

void	check_name_map(char *file)
{
	int	i;

	i = 0;
	while (file[i])
	{
		if (file[i] == '.')
			if (file[i + 1] == 'c')
				if (file[i + 2] == 'u')
					if (file[i + 3] == 'b')
						if (file[i + 4] == '\0')
							return ;
		i++;
	}
	printf("Error\n");
	exit(1);
}

char	**init_map(t_data *data)
{
	char	**map;
	int		i;
	int begin_map;

	i = 0;
	begin_map = data->begin_map;
	map = malloc(sizeof(char *) * (data->row - begin_map) + 1);
	if(!map)
		return(NULL);
	while (begin_map < data->row)
	{
		map[i] = data->file[begin_map];
		i++;
		begin_map++;
	}
	return (map);
}

int	init_file(t_data *data, char *file)
{
	int	i;
	int	fd;

	i = 0;
	check_name_map(file);
	fd = open(file, O_RDONLY);
	allocate_map(data, file, fd);
	while (1)
	{
		data->file[i] = get_next_line(fd);
		if (data->file[i] == NULL)
			break ;
		i++;
	}
	data->file[i] = NULL;
	if (check_texture(data) == ERROR)
		return (ERROR);
	data->map = init_map(data);
	if (check_content_map(data->file, data) == ERROR || !data->map)
		return (ERROR);
	return (GOOD);
}
