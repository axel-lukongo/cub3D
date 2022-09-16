CC = gcc

RM = rm -rf

NAME = cub3d

SRCS =	main.c\
		init_struct.c\
		init_all.c\
		parsing_map.c\
		parsing_texture.c\
		my_draw.c\
		my_free.c\
		game_event.c\
		gnl/get_next_line.c\
		gnl/get_next_line_utils.c\
		functions/ft_strlen2.c\
		functions/ft_strncmp.c\



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
