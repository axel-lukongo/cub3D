/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 19:28:15 by alukongo          #+#    #+#             */
/*   Updated: 2022/09/20 20:38:22 by alukongo         ###   ########.fr       */
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






void	calc(t_data *data)
{
	int	x;

	x = 0;
	my_rebuf(data);
	while (x < width)
	{
		init_raycast(data, x);
		data->raycast.hit = 0; //was there a wall data->raycast.hit?
		// int data->raycast.side; //was a NS or a EW wall data->raycast.hit?

		define_step(data);
		define_hit(data);
		if (data->raycast.side == 0)
			data->raycast.perpWallDist = (data->raycast.mapX - data->posX + (1 - data->raycast.stepX) / 2) / data->raycast.rayDirX;
		else
			data->raycast.perpWallDist = (data->raycast.mapY - data->posY + (1 - data->raycast.stepY) / 2) / data->raycast.rayDirY;

		//Calculate height of line to draw on screen
		data->raycast.lineHeight = (int)(height / data->raycast.perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -data->raycast.lineHeight / 2 + height / 2;
		if(drawStart < 0)
			drawStart = 0;
		int drawEnd = data->raycast.lineHeight / 2 + height / 2;
		if(drawEnd >= height)
			drawEnd = height - 1;

		// texturing calculations
		int texNum = data->map[data->raycast.mapX][data->raycast.mapY] - 49;

		// calculate value of wallX
		double wallX;
		if (data->raycast.side == 0)
			wallX = data->posY + data->raycast.perpWallDist * data->raycast.rayDirY;
		else
			wallX = data->posX + data->raycast.perpWallDist * data->raycast.rayDirX;
		wallX -= floor(wallX);

		// x coordinate on the texture
		int texX = (int)(wallX * (double)texWidth);
		if (data->raycast.side == 0 && data->raycast.rayDirX > 0)
			texX = texWidth - texX - 1;
		if (data->raycast.side == 1 && data->raycast.rayDirY < 0)
			texX = texWidth - texX - 1;

		// How much to increase the texture coordinate perscreen pixel
		double step = 1.0 * texHeight / data->raycast.lineHeight;
		// Starting texture coordinate
		double texPos = (drawStart - height / 2 + data->raycast.lineHeight / 2) * step;
		for (int y = drawStart; y < drawEnd; y++)
		{
			// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
			int texY = (int)texPos & (texHeight - 1);
			texPos += step;
			// printf("------------texnum : %d\n", texNum);
			u_int32_t color = data->texture[texNum][texHeight * texY + texX];
			// make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
			if (data->raycast.side == 1)
				color = (color >> 1) & 8355711;
			data->buf[y][x] = color;
			data->re_buf = 1;
		}
		x++;
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
	data.win = mlx_new_window(data.mlx, width, height, "mlx");//i init my window
	data.img.img = mlx_new_image(data.mlx, width, height); //i init my image
	data.img.data = (int *)mlx_get_data_addr(data.img.img, &data.img.bpp, &data.img.size_l, &data.img.endian);
	mlx_loop_hook(data.mlx, &start_game, &data);//this is where every thing start
	mlx_hook(data.win, 2, 1L << 0, key_press, &data); 
	mlx_hook(data.win, 3, 1L << 1, ft_keys_release, &data);
	mlx_loop(data.mlx);
}
