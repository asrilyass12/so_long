/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilasrarf <ilasrarf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 00:52:58 by ilasrarf          #+#    #+#             */
/*   Updated: 2023/01/29 15:04:56 by ilasrarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include "mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../Libft/libft.h"

typedef struct pars{
	int	j;
	int	i;
	int	one;
	int	zero;
	int	c;
	int	e;
	int	p;
	int	sum;
}	t_pars;

typedef struct mlx_win{
	char	**map;
	char	root;
	void	*ptr;
	void	*win;
	void	*img_wall;
	void	*img_coin;
	void	*img_door;
	void	*img_plyl;
	void	*img_plyr;
	void	*img_flor;
	void	*img_exit_o;
	void	*img_exit_c;
	void	*img_enemy1;
	void	*img_enemy2;
	void	*img_enemy3;
	void	*img_enemy4;
	void	*img_enemy5;
	void	*img_enemy6;
	int		move_cnt;
	int		enemy_cnt;
	int		coin_cnt;
	int		coin_eat;
	int		c_exit;
	int		o_exit;
	int		h_img;
	int		w_img;
	int		h_win;
	int		w_win;
	int		cv;
	int		width_pos;
	int		height_pos;
}	t_mlx;

typedef struct mlx_pos_e{
	int	i;
	int	j;
}	t_data_pos;

//------------- pasrsing part -------------//

char	**get_next_line(int fd);//read the map end stored into double pointure 
char	**so_long(int map);// the main function
int		ft_check_ex(char *haystack);//check if the extantion is valid
int		ft_open_file(char *str);//to open the file
int		ft_check_walls_len(char **str);//check if map lines is the same
void	ft_no_escape_map(char **str);// check if the map is closed by '1'
int		ft_check_characters(char **str, t_pars *pars);
int		ft_check_rec(char **str);//check if map is recto
char	**ft_error(char *av, t_pars *pars);//to run all parsing function 
int		ft_map_file(char *str);//run the open file funtion and check extantion
void	ft_cnt_char(char **str, t_pars *pars);
int		ft_cnt_char_err(t_pars *pars);
void	ft_err_read(char *str);//call all parsing functions
int		ft_check_extra(char **str);//check extra characters
int		ft_pos(char **str, int *y, int *x);//get plyaer position
int		ft_check_ply_path(char **str);//check if player have a valid path
int		ft_cnt_h(char **map); // count lines in the map
void	ft_free(char **str);

int		ft_check_zero(char **map);
void	ft_fill(char **str);
char	**ft_alloc(char **str);
void	ft_final_check(char **map);
//------------- pasrsing part end -------------//

//------------- drawing part -------------//

void	ft_mess(t_mlx *t_win, char *str);

//put the xpm file into void * -> for control (image)
int		ft_put_img(t_mlx *t_win);//put image
int		ft_put_img_enemy(t_mlx *t_win);//put enemy image

int		ft_key_check(int key, t_mlx *t_win);//to check the keys

int		ft_cnt_coin(t_mlx *t_win);//cont coin in the fucking map

int		ft_draw(t_mlx *t_win, void *img, char root);//draw all
void	ft_draw_p_c(t_mlx *t_win, int root);//draw player and coins 
void	ft_draw_w_f(t_mlx *t_win, void *img);//draw walls and floor
void	ft_draw_ext(t_mlx *t_win);//draw exit door

int		ft_move_down(t_mlx *t_win, void *img);
int		ft_move_right(t_mlx *t_win, void *img);
int		ft_move_left(t_mlx *t_win, void *img);
int		ft_move_up(t_mlx *t_win, void *img);

int		ft_write_moves(t_mlx *t_win);//wirte the number of moves in command line

int		ft_destroy(t_mlx *t_win); // destroy images and window

void	ft_move_enemy(t_mlx *t_win);//for enemy move
void	ft_find_p(t_mlx *t_win);//find ply if enemy eated 
void	ft_cnt_enemy(t_mlx *t_win);// count enemy
int		*ft_get_all_pos(t_mlx *t_win);//get all positions for enemy
int		ft_animation(t_mlx *t_win);//animation

void	ft_up(t_mlx *t_win);
void	ft_down(t_mlx *t_win);
void	ft_left(t_mlx *t_win);
void	ft_right(t_mlx *t_win);

void	ft_free_nor(char **str);

//------------- drawing part  end -------------//
#endif
