/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilasrarf <ilasrarf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 00:52:58 by ilasrarf          #+#    #+#             */
/*   Updated: 2023/01/15 11:31:32 by ilasrarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx_linux/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "Libft/libft.h"

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
# endif

typedef struct mlx_win{
	char	**map;
	void	*ptr;
	void	*win;
	void	*img_wall;
	void	*img_coin;
	void	*img_door;
	void	*img_ply;
	void	*img_flor;
	int		move_cnt;
	int		coin_cnt;
	int		coin_eat;
	void	*img_exit_o;
	void	*img_exit_c;
	int		c_exit;
	int		o_exit;
	int		h_img;
	int		w_img;
} x_mlx;

//------------- pasrsing part -------------//

char	**get_next_line(int fd);//read the map end stored into double pointure 
char	**so_long(int map);// the main function
int		ft_check_ex(char *haystack);//check if the extantion is valid
int		ft_open_file(char *str);//to open the file
int		ft_check_walls_len(char **str);//check if map lines is the same
int		ft_no_escape_map(char **str);// check if the map is closed by '1' 
int		ft_error_check_map_file(char *str);
int		ft_check_characters(char **str);
int		ft_check_rec(char **str);//***
char	**ft_error(char *av);//to run all parsing function 
int		ft_map_file(char *str);// to run the open file funtion and check extantion
int		ft_cnt_char(char **str);
void	ft_err_read(char *str);
int		ft_check_extra(char **str);
int		ft_pos(char **str, int *y, int *x);//get plyaer position
int		ft_check_ply_path(char **str);//check if player have a valid path
int		ft_cnt_h(char **map); // count lines in the map 

//------------- pasrsing part end -------------//

//------------- drawing part -------------//

int		ft_put_img(x_mlx *t_win);// to put the xpm file into void * --> for control (image)

int		ft_key_check(int key, x_mlx *t_win);//to check the keys

int		ft_draw(x_mlx *t_win);
int		ft_draw_p_c(x_mlx *t_win);
int		ft_draw_w_f(x_mlx *t_win);
int		ft_draw_ext(x_mlx *t_win);

int		ft_move_down(x_mlx *t_win);
int		ft_move_right(x_mlx *t_win);
int		ft_move_left(x_mlx *t_win);
int		ft_move_up(x_mlx *t_win);

void	ft_move_write(x_mlx *t_win);

//------------- drawing part  end -------------//
# endif
