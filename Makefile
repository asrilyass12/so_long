# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilasrarf <ilasrarf@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 04:05:00 by ilasrarf          #+#    #+#              #
#    Updated: 2023/01/29 18:07:01 by ilasrarf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


FILES_M = so_long.c src/ft_read_map.c src/ft_check_valid_map_ex.c src/ft_open_file.c src/ft_check_walls.c src/ft_check_cnt_char.c \
			src/ft_check_extra.c src/ft_cnt_h.c src/ft_ply_path.c src/ft_draw.c src/ft_move.c src/ft_count_coin.c\
			src/free.c src/ft_destroy.c src/ft_write_moves.c src/ft_pos.c src/ft_alloc.c src/ft_check_key_part2.c src/ft_mess.c

FILES_O  = ${FILES_M:%.c=%.o}
			
FILES_B = so_long_bonus.c src_bonus/ft_read_map.c src_bonus/ft_check_valid_map_ex.c src_bonus/ft_open_file.c src_bonus/ft_check_walls.c src_bonus/ft_check_cnt_char.c \
			src_bonus/ft_check_extra.c src_bonus/ft_cnt_h.c src_bonus/ft_ply_path.c src_bonus/ft_draw.c src_bonus/ft_move.c src_bonus/ft_count_coin.c\
			src_bonus/free.c src_bonus/ft_destroy.c src_bonus/ft_move_enemy.c src_bonus/ft_animation.c src_bonus/ft_mess.c src_bonus/ft_check_key_part2.c\
			src_bonus/ft_pos.o src_bonus/ft_alloc.c src_bonus/ft_norm_free.c
			
FILES_B_O  = ${FILES_B:%.c=%.o}
			
NAME = so_long
LIBFT = Libft/libft.a
CC = cc
FLAGS = -Wall -Wextra -Werror
AR = ar rc
RM = rm -f

all: ${NAME}

%.o: %.c src/so_long.h
	$(CC) ${FLAGS}  -c $< -o $@

${LIBFT}:
	cd Libft && make

${NAME}: ${FILES_O} ${LIBFT}
	${CC} ${FLAGS} ${LIBFT} $^ -o ${NAME} -lmlx -framework OpenGL -framework AppKit

bonus: ${FILES_B_O} ${LIBFT}
	${CC} ${FLAGS} ${LIBFT} $^ -o ${NAME} -lmlx -framework OpenGL -framework AppKit

clean:
	${RM} ${FILES_B_O} ${FILES_O}
	cd Libft && make clean

fclean: clean
	${RM} ${NAME}
	cd Libft && make fclean

re: fclean all

.PHONY: all fclean re clean