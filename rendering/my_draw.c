/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 10:59:09 by alukongo          #+#    #+#             */
/*   Updated: 2022/09/26 21:18:57 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

void	load_image(t_data *data, int *texture, char *path, t_img *img)
{
	int	y;
	int	x;

	y = 0;
	img->img = mlx_xpm_file_to_image(data->mlx, path, &img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
	while (y < img->img_height)
	{
		x = 0;
		while (x < img->img_width)
		{
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(data->mlx, img->img);
}

void	verLine(t_data *data, int color_ceil, int color_floor, int x)
{
	int	y;

	y = 0;
	while (y < data->raycast.draw_start)
	{
		data->img.data[y * WIDTH + x] = color_ceil;
		y++;
	}
	y = data->raycast.draw_end;
	while (y < HEIGHT)
	{
		data->img.data[y * WIDTH + x] = color_floor;
		y++;
	}
	x++;
}

void	load_texture(t_data *data)
{
	t_img	img;

	load_image(data, data->texture[0], "textures/eagle.xpm", &img);
	load_image(data, data->texture[1], "textures/redbrick.xpm", &img);
	load_image(data, data->texture[2], data->so, &img);
	load_image(data, data->texture[3], "textures/greystone.xpm", &img);
	load_image(data, data->texture[4], "textures/bluestone.xpm", &img);
	load_image(data, data->texture[5], "textures/mossy.xpm", &img);
	load_image(data, data->texture[6], "textures/wood.xpm", &img);
	load_image(data, data->texture[7], "textures/colorstone.xpm", &img);
}

//this function allow me to draw a line
void	draw(t_data *data, int x)
{
	int	y;

	y = data->raycast.draw_start;
	while (y < data->raycast.draw_end)
	{
			data->img.data[y * WIDTH + x] = data->buf[y][x];
		y++;
	}
}
