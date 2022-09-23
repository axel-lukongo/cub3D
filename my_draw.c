/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 10:59:09 by alukongo          #+#    #+#             */
/*   Updated: 2022/09/23 20:07:18 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"


// void		my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->img.data + (y * data->img.size_l
// 	+ x * (data->img.bpp / 8));
// 	*(unsigned int*)dst = color;
// }

// void		draw_ceil_floor(t_data *data, int x)
// {
// 	int		y;

// 	y = -1;
// 	while (++y < data->raycast.draw_start)
// 		my_mlx_pixel_put(data, x, y, data->file.c_rgb);
// 	y = data->raycast.draw_end - 1;
// 	while (++y < height)
// 		my_mlx_pixel_put(data, x, y, data->file.f_rgb);
// }

void	load_image(t_data *data, int *texture, char *path, t_img *img)
{
	int y;
	int x;
	
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
	// int	x;

	// x = 0;
	// while (x < width)
	// {
		y = 0;
		while (y < data->raycast.drawStart)
		{
			// mlx_pixel_put(data->mlx, data->win, x, y, color_ceil);
			// my_mlx_pixel_put(data, x, y, color_ceil);
			data->img.data[y * width + x] = color_ceil;
			y++;
		}
		y = data->raycast.drawEnd;
		while (y < height)
		{
			// my_mlx_pixel_put(data, x, y, color_floor);
			// mlx_pixel_put(data->mlx, data->win, x, y, color_floor);
			data->img.data[y * width + x] = color_floor;
			y++;
		}
		x++;
	// }
}

void	load_texture(t_data *data)
{
	t_img	img;
	

	load_image(data, data->texture[0], "textures/eagle.xpm", &img);
	load_image(data, data->texture[1], "textures/redbrick.xpm", &img);
	load_image(data, data->texture[2], data->SO, &img);
	load_image(data, data->texture[3], "textures/greystone.xpm", &img);
	load_image(data, data->texture[4], "textures/bluestone.xpm", &img);
	load_image(data, data->texture[5], "textures/mossy.xpm", &img);
	load_image(data, data->texture[6], "textures/wood.xpm", &img);
	load_image(data, data->texture[7], "textures/colorstone.xpm", &img);
}



//this function allow me to draw a line
void	draw(t_data *data, int x)
{
	int y;
	// int x;

	y = data->raycast.drawStart;
	while (y < data->raycast.drawEnd)
	{
		// x = 0;
		// while (x < width)
		// {
			data->img.data[y * width + x] = data->buf[y][x];
			// x++;
		// }
		y++;
	}
	// verLine(data, 0xFF0000,0x0000FF);
	// mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}
