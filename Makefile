NAME = so_long.a
CC = cc
FLAGS = -Wall -Wextra -Werror
SRC = src/so_long.c src/check_map.c src/ft_close_and_free.c src/draw_map.c src/ft_move.c \
	  src/back_tracking.c util/ft_memset.c util/ft_strlen.c util/ft_strncmp.c  util/ft_strdup.c \
	  util/get_next_line.c util/get_next_line_utils.c util/ft_calloc.c  util/ft_bzero.c\

MLX = -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit 

OBJ = ${SRC:.c=.o}

FT_LIB = ./printf/libftprintf.a

%.o: %.c so_long.h
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ) $(FT_LIB)
	ar rc $(NAME) $(OBJ)
	$(CC) $(FLAGS) $(NAME) $(FT_LIB) $(MLX) -lz -o so_long

all : ${NAME}

$(FT_LIB) :
	make -C ./printf

fclean : clean
	rm -rf ${NAME}
	rm -rf so_long
	make fclean -C ./printf

clean : 
	rm -rf ${OBJ}
	make clean -C ./printf 

re : fclean all