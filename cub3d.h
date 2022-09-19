#ifndef CUB3D_H
#define CUB3D_H

#include "mlx/mlx.h"
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
# include <fcntl.h>
#include "gnl/get_next_line.h"

#define X_EVENT_KEY_PRESS	2
#define X_EVENT_KEY_EXIT	17
#define texWidth 64
#define GOOD 1
#define ERROR -1
#define texHeight 64
#define mapWidth 24
#define mapHeight 24
#define width 600
#define height 400
#define K_A 97
#define K_D 100
#define K_W 119
#define K_S 115
#define K_ESC 65307

typedef struct	s_img
{
	void	*img;
	int		*data;

	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}				t_img;

typedef struct	s_data
{
	void	*wall;
	char	*color_floor;
	char	*color_ceiling;
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	void	*mlx;
	void	*win;
	t_img	img;
	int		buf[height][width];
	int		**texture;
	double	moveSpeed;
	double	rotSpeed;
	int		re_buf;
	char	**file;
	char	*SO;
	char	*NO;
	char	*WE;
	char	*EA;
	int		row;
	int		col;
	int		begin_map;
	char	**map;
}				t_data;

int		key_press(int key, t_data *data);
int		main_loop(t_data *data);
void	load_image(t_data *data, int *texture, char *path, t_img *img);
void	load_texture(t_data *data);
void	draw(t_data *data);
void	init_struct(t_data *data);
int		init_buf(t_data *data);
void	destroy(t_data *data);
void	close_my_game(t_data *data);
void	free_map(t_data *data);
int		check_content_map(char **map, t_data *data);
int		init_file(t_data *data, char *file);
int		ft_strlen(char *s);
int		ft_strlen2(char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		check_texture(t_data *data);

#endif // !CUB3D_H