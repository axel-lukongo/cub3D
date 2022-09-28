CC = gcc

RM = rm -rf

NAME = cub3d

SRCS =	main.c\
		my_init/init_struct.c\
		my_init/initial_position.c\
		parsing_map/init_all.c\
		parsing_map/parsing_map.c\
		parsing_map/parsing_texture.c\
		rendering/my_draw.c\
		rendering/ft_raycast.c\
		my_event/game_event.c\
		my_event/release_key.c\
		gnl/get_next_line.c\
		gnl/get_next_line_utils.c\
		functions/utils.c\
		functions/ft_strlen2.c\
		functions/ft_strncmp.c\
		functions/my_cpy.c\
		functions/ft_strncpy.c\
		functions/ft_split.c\
		functions/ft_atoi.c\
		functions/ft_isdigit.c\
		stop_game/my_free.c\


BONUS_SRCS = ${BONUS_SRC}

OBJ	= ${SRCS:.c=.o}

CFLAGS	= -g -Wall -Werror -Wextra

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): $(OBJ)
	$(CC) $(SRCS) ${CFLAGS} mlx/libmlx_Linux.a -lm -lXext -lX11 -o $(NAME) 

all: ${NAME}

clean:
	${RM} ${OBJ} ${BONUS_OBJS}

fclean: clean
	${RM} ${NAME} ${BONUS_NAME}

re: fclean all

.PHONY: all clean fclean re
