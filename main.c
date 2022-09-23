/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 19:28:15 by alukongo          #+#    #+#             */
/*   Updated: 2022/09/23 13:31:38 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



void my_rebuf(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	if (data->re_buf == 1)
	{
		while (++i < height)
		{
			j = -1;
			while (++j < width)
				data->buf[i][j] = 0;
		}
	}
}



/**
 * data->raycast.hit: was there a wall data->raycast.hit?
 * define_step(data): step is the value who allow me to increas to the other coordinate in X or Y
 * dda_function(data): the DDA allow me to now where my ray touch the next squarre
 * draw_start_end(data): this function allow me to know where i have to start and finish to draw my line
 * side: it for know if i touch the side of the squar first or the face
 * 
 * 
 * @param data 
 */

void	calc(t_data *data)
{
	int	x;

	x = -1;
	my_rebuf(data);
	while (++x < width)
	{
		init_raycast(data, x);
		data->raycast.hit = 0;
		define_step(data);
		dda_function(data);
		draw_start_end(data);
		if (data->raycast.side == 0)
		{
			data->raycast.wallX = data->posY + 
			data->raycast.perpWallDist * data->raycast.rayDirY;
		}
		else
		{
			data->raycast.wallX = data->posX +
			data->raycast.perpWallDist * data->raycast.rayDirX;
		}
		data->raycast.wallX -= floor(data->raycast.wallX);
		data->raycast.texX = (int)(data->raycast.wallX * (double)texWidth);
		add_texture(data, x, data->raycast.drawStart);
	}
}






/**
 * @calc i init every variable who i need for draw in 3D.
 * @draw when my variable has been calculate i will draw i column according to my variable
 * i do this in loop until i close my game.
 * 
 * @param data 
 * @return int 
 */
int	start_game(t_data *data)
{
	calc(data);
	draw(data);
	return (0);
}


	// verLine(&data, 0xFF0000, 0x0000FF);





/**
 * in the main function i initialize everything


 * @init_file: i initalize my map,
   i save the information bellow the map(color, texture...),
   and i parse my map.

   
 * @param ac 
 * @param av 
 * @return int 
 */
int	main(int ac, char **av)
{
	t_data data;
	data.mlx = mlx_init();

	if ((init_file(&data, av[1]) == ERROR) || ac != 2 || !data.mlx)
	{
		printf("\033[1;31mERROR\n\033[0m");
		free_map(&data);
		return(0);
	}
	init_struct(&data);
	if (init_buf(&data) == ERROR)
		return(ERROR);
	load_texture(&data);
	// printf("-----------path_text: %s----------\n", data.EA+5);
	data.win = mlx_new_window(data.mlx, width, height, "mlx");//i init my window
	data.img.img = mlx_new_image(data.mlx, width, height); //i init my image
	data.img.data = (int *)mlx_get_data_addr(data.img.img, &data.img.bpp, &data.img.size_l, &data.img.endian);
	mlx_loop_hook(data.mlx, &start_game, &data);//this is where every thing start
	mlx_hook(data.win, 2, 1L << 0, key_press, &data); 
	mlx_hook(data.win, 3, 1L << 1, ft_keys_release, &data);
	mlx_loop(data.mlx);
}
