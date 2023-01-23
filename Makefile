# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilasrarf <ilasrarf@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 04:05:00 by ilasrarf          #+#    #+#              #
#    Updated: 2023/01/23 16:53:52 by ilasrarf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


FILES_M = so_long.c src/ft_read_map.c src/ft_check_valid_map_ex.c src/ft_open_file.c src/ft_check_walls.c src/ft_check_cnt_char.c \
			src/ft_check_extra.c src/ft_cnt_h.c src/ft_ply_path.c src/ft_draw.c src/ft_move.c src/ft_count_coin.c\
			src/free.c src/ft_destroy.c src/ft_write_moves.c

FILES_O = so_long.o src/ft_read_map.o src/ft_check_valid_map_ex.o src/ft_open_file.o src/ft_check_walls.o src/ft_check_cnt_char.o \
			src/ft_check_extra.o src/ft_cnt_h.o src/ft_ply_path.o src/ft_draw.o src/ft_move.o src/ft_count_coin.o\
			src/free.o src/ft_destroy.o src/ft_write_moves.o
			
FILES_B = so_long_bonus.c src_bonus/ft_read_map.c src_bonus/ft_check_valid_map_ex.c src_bonus/ft_open_file.c src_bonus/ft_check_walls.c src_bonus/ft_check_cnt_char.c \
			src_bonus/ft_check_extra.c src_bonus/ft_cnt_h.c src_bonus/ft_ply_path.c src_bonus/ft_draw.c src_bonus/ft_move.c src_bonus/ft_count_coin.c\
			src_bonus/free.c src_bonus/ft_destroy.c

FILES_B_O = so_long_bonus.o src_bonus/ft_read_map.o src_bonus/ft_check_valid_map_ex.o src_bonus/ft_open_file.o src_bonus/ft_check_walls.o src_bonus/ft_check_cnt_char.o \
			src_bonus/ft_check_extra.o src_bonus/ft_cnt_h.o src_bonus/ft_ply_path.o src_bonus/ft_draw.o src_bonus/ft_move.o src_bonus/ft_count_coin.o\
			src_bonus/free.o src_bonus/ft_destroy.o
			
NAME = so_long
NAME_B = so_long_bonus
LIBFT = Libft/libft.a
CC = cc
FLAGS = -Wall -Wextra -Werror
# -fsanitize=address
AR = ar rc
RM = rm -f

all: ${LIBFT} ${FILES_O} ${NAME}

%.o: %.c so_long.h
	$(CC) -Wall -Wextra -Werror  -c $< -o $@

${LIBFT}:
	cd Libft && make

${NAME}:
	${CC} ${FLAGS} ${FILES_O} ${LIBFT} -o ${NAME} -lmlx -framework OpenGL -framework AppKit

bonus: ${LIBFT} ${FILES_B_O}
	${CC} ${FLAGS} ${FILES_B_O} ${LIBFT} -o ${NAME_B} -lmlx -framework OpenGL -framework AppKit

clean:
	${RM} ${FILES_O}
	${RM} ${FILES_B_O}
	cd Libft && make clean

fclean: clean
	${RM} ${NAME}
	${RM} ${NAME_B}
	cd Libft && make fclean

re: fclean all

.PHONY: all fclean re clean