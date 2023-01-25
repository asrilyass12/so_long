/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilasrarf <ilasrarf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 10:04:38 by ilasrarf          #+#    #+#             */
/*   Updated: 2023/01/24 03:36:19 by ilasrarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../Libft/libft.h"

int	ft_put_img(t_mlx *t_win)
{
	t_win->img_wall = mlx_xpm_file_to_image(t_win->ptr, "./assets/wall.xpm",
			&t_win->w_img, &t_win->h_img);
	t_win->img_flor = mlx_xpm_file_to_image(t_win->ptr, "./assets/floor.xpm",
			&t_win->w_img, &t_win->h_img);
	t_win->img_coin = mlx_xpm_file_to_image(t_win->ptr, "./assets/coin.xpm",
			&t_win->w_img, &t_win->h_img);
	t_win->img_plyr = mlx_xpm_file_to_image(t_win->ptr, "./assets/r_player.xpm",
			&t_win->w_img, &t_win->h_img);
	t_win->img_plyl = mlx_xpm_file_to_image(t_win->ptr, "./assets/l_player.xpm",
			&t_win->w_img, &t_win->h_img);
	t_win->img_exit_c = mlx_xpm_file_to_image(t_win->ptr, "./assets/c_exit.xpm",
			&t_win->w_img, &t_win->h_img);
	t_win->img_exit_o = mlx_xpm_file_to_image(t_win->ptr, "./assets/o_exit.xpm",
			&t_win->w_img, &t_win->h_img);
	if(!t_win->img_wall || !t_win->img_flor || !t_win->img_coin || !t_win->img_plyr 
			|| !t_win->img_plyl || !t_win->img_exit_c || !t_win->img_exit_o)
	{
		write(1,"!!ERROR!!\n", 10);
		exit(1);
	}
	return (0);
}

int	ft_draw_w_f(t_mlx *t_win)
{
	int	width_pos;
	int	height_pos;
	int	i;
	int	j;

	i = 0;
	height_pos = 32;
	while (t_win->map[i])
	{
		j = 0;
		width_pos = 0;
		while (t_win->map[i][j])
		{
			mlx_put_image_to_window(t_win->ptr, t_win->win,
				t_win->img_flor, width_pos, height_pos);
			if (t_win->map[i][j] == '1')
				mlx_put_image_to_window(t_win->ptr, t_win->win,
					t_win->img_wall, width_pos, height_pos);
			width_pos += 64;
			j++;
		}
		height_pos += 64;
		i++;
	}
	return (0);
}

int	ft_draw_p_c(t_mlx *t_win, int root)
{
	int	width_pos;
	int	height_pos;
	int	j;
	int	i;

	j = 0;
	i = 0;
	height_pos = 32;
	while (t_win->map[i])
	{
		j = 0;
		width_pos = 0;
		while (t_win->map[i][j])
		{
			if (t_win->map[i][j] == 'P' && root == 'l')
				mlx_put_image_to_window(t_win->ptr, t_win->win,
					t_win->img_plyl, width_pos, height_pos);
			if (t_win->map[i][j] == 'P' && root == 'r')
				mlx_put_image_to_window(t_win->ptr, t_win->win,
					t_win->img_plyr, width_pos, height_pos);
			if (t_win->map[i][j] == 'C')
				mlx_put_image_to_window(t_win->ptr, t_win->win,
					t_win->img_coin, width_pos, height_pos);
			width_pos += 64;
			j++;
		}
		height_pos += 64;
		i++;
	}
	return (0);
}

int	ft_draw_ext(t_mlx *t_win)
{
	int	width_pos;
	int	height_pos;
	int	j;
	int	i;

	j = 0;
	i = 0;
	height_pos = 32;
	while (t_win->map[i])
	{
		j = 0;
		width_pos = 0;
		while (t_win->map[i][j])
		{
			if (t_win->map[i][j] == 'E')
			{
				if (t_win->coin_cnt == t_win->coin_eat)
					mlx_put_image_to_window(t_win->ptr, t_win->win,
						t_win->img_exit_o, width_pos, height_pos);
				else
					mlx_put_image_to_window(t_win->ptr, t_win->win,
						t_win->img_exit_c, width_pos, height_pos);
			}
			width_pos += 64;
			j++;
		}
		height_pos += 64;
		i++;
	}
	return (0);
}
