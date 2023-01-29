NAME = so_long.a
CC = cc
FLAGS = -Wall -Wextra -Werror
SRC = src/so_long.c src/check_map.c src/ft_close_and_free.c src/draw_map.c src/ft_move.c \
	  src/back_tracking.c util/ft_memset.c util/ft_strlen.c util/ft_strncmp.c  util/ft_strdup.c src/check_map2.c \
	  util/get_next_line.c util/get_next_line_utils.c util/ft_calloc.c  util/ft_bzero.c \
	  src/ft_move_left.c src/ft_move_right.c src/ft_move_up_down.c\

SRCB = src_bonus/so_long_bonus.c src_bonus/check_map_bonus.c src_bonus/ft_close_and_free_bonus.c src_bonus/draw_map_bonus.c src_bonus/ft_move_bonus.c \
	   src_bonus/back_tracking_bonus.c util/ft_memset.c util/ft_strlen.c util/ft_strncmp.c  util/ft_strdup.c src_bonus/check_map2_bonus.c \
	  util/get_next_line.c util/get_next_line_utils.c util/ft_calloc.c  util/ft_bzero.c \
	  src_bonus/ft_move_up_down_bonus.c src_bonus/ft_move_left_bonus.c src_bonus/ft_move_right_bonus.c src_bonus/animation.c \

MLX = -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

HEAD = so_long.h

B_HEAD = so_long_bonus.h

OBJ = ${SRC:.c=.o}

OBJ_B = ${SRCB:.c=.o}

FT_LIB = ./printf/libftprintf.a

%.o: %.c $(B_HEAD) $(HEAD)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ) $(FT_LIB) $(HEAD)
	ar rc $(NAME) $(OBJ)
	$(CC) $(FLAGS) $(NAME) $(FT_LIB) $(MLX) -lz -o so_long

all : ${NAME}

bonus : remv ${OBJ_B} ${FT_LIB} ${B_HEAD} 
	ar rc $(NAME) $(OBJ_B)
	$(CC) $(FLAGS) $(NAME) $(FT_LIB) $(MLX) -lz -o so_long_bonus
	

$(FT_LIB) :
	make -C ./printf

fclean : clean
	rm -rf ${NAME}
	rm -rf so_long so_long_bonus
	make fclean -C ./printf

remv :
	rm -rf ${NAME}

clean : 
	rm -rf ${OBJ} ${OBJ_B}
	make clean -C ./printf 

re : fclean all