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
#define K_LEFT 65361
#define K_RIGHT 65363
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

typedef struct	s_raycast
{
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	int	mapX;
	int	mapY;
	//length of ray from current position to next x or y-side
	double	sideDistX;
	double	sideDistY;
	//length of ray from one x or y-side to next x or y-side
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;

	//what direction to step in x or y direction (either +1 or -1)
	int	stepX;
	int	stepY;
	
	//it tell me if i hit a wall
	int	hit;

	//was a NS or a EW wall data->raycast.hit?
	int side;

	//Calculate height of line to draw on screen
	int	lineHeight;

	int	drawStart;
	int	drawEnd;
	int	texX;
	int	color;
	double	wallX;
}	data_raycast;

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
	int		left_rotate;
	int		right_rotate;
	int		go_forwar;
	int		go_back;
	int		go_left;
	int		go_right;
	data_raycast	raycast;
	t_img	img;
}				t_data;

int		key_press(int key, t_data *data);
int		start_game(t_data *data);
void	load_image(t_data *data, int *texture, char *path, t_img *img);
void	load_texture(t_data *data);
void	draw(t_data *data, int x);
void	init_struct(t_data *data);
void	init_raycast(t_data *data, int x);
int		init_buf(t_data *data);
void	destroy(t_data *data);
void	close_my_game(t_data *data);
void	free_map(t_data *data);
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
int		ft_keys_release(int	keycode, t_data	*data);
void	define_step(t_data *data);
void	dda_function(t_data *data);
void	draw_start_end(t_data *data);
void	add_texture(t_data *data, int x, int y);
int		set_position(t_data *data, char value);
int		ft_convert_color(char *str);
void	verLine(t_data *data, int color_ceil, int color_floor, int x);

#endif // !CUB3D_H