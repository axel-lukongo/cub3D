/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 21:14:24 by alukongo          #+#    #+#             */
/*   Updated: 2022/09/26 21:39:10 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx/mlx.h"
# include <math.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "gnl/get_next_line.h"
# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_EXIT	17
# define TEXWIDTH 64
# define GOOD 1
# define ERROR -1
# define TEXHEIGHT 64
# define WIDTH 1100
# define HEIGHT 1000
# define K_A 97
# define K_D 100
# define K_LEFT 65361
# define K_RIGHT 65363
# define K_W 119
# define K_S 115
# define K_ESC 65307

typedef struct s_img
{
	void	*img;
	int		*data;

	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}				t_img;

typedef struct s_raycast
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	//length of ray from current position to next x or y-side
	double	side_dist_x;
	double	side_dist_y;
	//length of ray from one x or y-side to next x or y-side
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;

	//what direction to step in x or y direction (either +1 or -1)
	int		step_x;
	int		step_y;

	//it tell me if i hit a wall
	int		hit;

	//was a NS or a EW wall data->raycast.hit?
	int		side;

	//Calculate HEIGHT of line to draw on screen
	int		line_height;

	int		draw_start;
	int		draw_end;
	int		tex_x;
	int		color;
	double	wall_x;
}	t_raycast;

typedef struct s_data
{
	char			*color_floor;
	char			*color_ceiling;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	void			*mlx;
	void			*win;
	int				buf[HEIGHT][WIDTH];
	int				**texture;
	double			movespeed;
	double			rotspeed;
	int				re_buf;
	char			**file;
	char			*so;
	char			*no;
	char			*we;
	char			*ea;
	int				row;
	int				col;
	int				begin_map;
	char			**map;
	int				left_rotate;
	int				right_rotate;
	int				go_forwar;
	int				go_back;
	int				go_left;
	int				go_right;
	t_raycast		raycast;
	t_img			img;
}				t_data;

int		key_press(int key, t_data *data);
int		start_game(t_data *data);
void	load_image(t_data *data, int *texture, char *path, t_img *img);
void	load_texture(t_data *data);
void	draw(t_data *data, int x);
void	init_null(t_data *data);
void	init_struct(t_data *data);
void	init_raycast(t_data *data, int x);
int		init_buf(t_data *data);
void	destroy(t_data *data);
void	close_my_game(t_data *data, int flag);
void	free_file(t_data *data);
void	free_texture(t_data *data);
int		check_content_map(char **map, t_data *data);
int		init_file(t_data *data, char *file);
int		ft_strlen(char *s);
int		ft_strlen2(char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*my_cpy(char *dest, char *src, char *to_skip);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	**ft_split(char const *s, char c);
void	my_free_alloc(char **tab);
int		ft_atoi(const char *str);
int		check_texture(t_data *data);
int		ft_keys_release(int keycode, t_data *data);
void	define_step(t_data *data);
void	dda_function(t_data *data);
void	draw_start_end(t_data *data);
void	add_texture(t_data *data, int x, int y);
float	set_position(t_data *data, char value);
int		ft_convert_color(char *str);
void	draw_sky_floor(t_data *data, int color_ceil, int color_floor, int x);

#endif // !CUB3D_H