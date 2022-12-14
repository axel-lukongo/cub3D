/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 19:28:15 by alukongo          #+#    #+#             */
/*   Updated: 2022/10/03 14:05:56 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_rebuf(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	if (data->re_buf == 1)
	{
		while (++i < HEIGHT)
		{
			j = -1;
			while (++j < WIDTH)
				data->buf[i][j] = 0;
		}
	}
}

/**
 * data->raycast.hit: was there a wall data->raycast.hit?
 * define_step(data): step is the value who allow me to increas to the
 * other coordinate in X or Y
 * dda_function(data): the DDA allow me to now where my ray touch the
 * next squarre
 * draw_start_end(data): this function allow me to know where i have
 * to start and finish to draw my line
 * side: it for know if i touch the side of the squar first or the face
 * 
 * 
 * @param data 
 */

void	ft_raycasting(t_data *data, int x)
{
	while (++x < WIDTH)
	{
		init_raycast(data, x);
		data->raycast.hit = 0;
		define_step(data);
		dda_function(data);
		draw_start_end(data);
		if (data->raycast.side == 0)
		{
			data->raycast.wall_x = data->pos_y
				+ data->raycast.perp_wall_dist * data->raycast.ray_dir_y;
		}
		else
		{
			data->raycast.wall_x = data->pos_x
				+ data->raycast.perp_wall_dist * data->raycast.ray_dir_x;
		}
		data->raycast.wall_x -= floor(data->raycast.wall_x);
		data->raycast.tex_x = (int)(data->raycast.wall_x * (double)TEXWIDTH);
		add_texture(data, x, data->raycast.draw_start);
		draw(data, x);
	}
}

/**
 * @ft_raycasting i init every variable who i need for draw in 3D.
 * @draw when my variable has been calculate i will draw a
 * column according to my variable
 * i do this in loop until i close my game.
 * 
 * @param data 
 * @return int 
 */
int	start_game(t_data *data)
{
	my_rebuf(data);
	ft_raycasting(data, -1);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
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
	t_data	data;

	init_null(&data);
	if (ac != 2 || (init_file(&data, av[1]) == ERROR))
	{
		printf("\033[1;31mERROR\033[0m\n");
		if (ac == 2)
			close_my_game(&data, 0);
		return (0);
	}
	replace_by(data.map, ' ', '1');
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "mlx");
	data.img.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.img.data = (int *)mlx_get_data_addr(data.img.img,
			&data.img.bpp, &data.img.size_l, &data.img.endian);
	init_struct(&data);
	if (init_buf(&data) == ERROR)
		return (ERROR);
	load_texture(&data);
	mlx_loop_hook(data.mlx, &start_game, &data);
	mlx_hook(data.win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.win, 17, 1L << 17, mouse_event, &data);
	mlx_hook(data.win, 3, 1L << 1, ft_keys_release, &data);
	mlx_loop(data.mlx);
}
