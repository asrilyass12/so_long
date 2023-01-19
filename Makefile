# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilasrarf <ilasrarf@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 04:05:00 by ilasrarf          #+#    #+#              #
#    Updated: 2023/01/15 10:56:01 by ilasrarf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


FILES_M = so_long.c src/ft_read_map.c src/ft_check_valid_map_ex.c src/ft_open_file.c src/ft_check_walls.c src/ft_check_cnt_char.c \
			src/ft_check_extra.c src/ft_cnt_h.c src/ft_ply_path.c src/ft_draw.c src/ft_move.c src/ft_write_moves.c src/ft_count_coin.c\
			

FILES_O = so_long.o src/ft_read_map.o src/ft_check_valid_map_ex.o src/ft_open_file.o src/ft_check_walls.o src/ft_check_cnt_char.o \
			src/ft_check_extra.o src/ft_cnt_h.o src/ft_ply_path.o src/ft_draw.o src/ft_move.o src/ft_write_moves.o src/ft_count_coin.o\

NAME = so_long
LIBFT = Libft/libft.a
CC = cc
FLAGS = -Wall -Wextra -Werror
# -fsanitize=address
AR = ar rc
RM = rm -f

all: ${LIBFT} ${FILES_O} ${NAME}

${LIBFT}:
	cd Libft && make

${NAME}:
	${CC} ${FLAGS} ${FILES_O} ${LIBFT} -o ${NAME} -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

clean:
	${RM} ${FILES_O}
	cd Libft && make clean

fclean: clean 
	${RM} ${NAME}
	cd Libft && make fclean

re: fclean all

.PHONY: all fclean re clean