/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilasrarf <ilasrarf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 10:04:38 by ilasrarf          #+#    #+#             */
/*   Updated: 2023/01/15 11:37:25 by ilasrarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../Libft/libft.h"

int ft_draw_w_f(x_mlx *t_win)
{
	int		width_img;
	int		height_img;
	int		width_pos;
	int		height_pos;
	int		i;
	int		j;
	
	i = 0;
	height_pos = 0;
	t_win->img_wall = mlx_xpm_file_to_image(t_win->ptr , "./assets/wall.xpm", &width_img, &height_img);
	t_win->img_flor = mlx_xpm_file_to_image(t_win->ptr , "./assets/flor.xpm", &width_img, &height_img);
	// printf("%s", map[1]);
	while (t_win->map[i])
	{
		j = 0;
		width_pos = 0;
		while (t_win->map[i][j])
		{
			mlx_put_image_to_window(t_win->ptr ,t_win->win, t_win->img_flor, width_pos, height_pos);
			if(t_win->map[i][j] == '1')
				mlx_put_image_to_window(t_win->ptr ,t_win->win, t_win->img_wall, width_pos, height_pos);
			width_pos += 32;
			j++;
		}
		height_pos += 32;
		i++;
	}
	return(0);
}

int ft_draw_p_c(x_mlx *t_win)
{
    int		width_pos;
    int		height_pos;
	int		width_img;
	int		height_img;
    int		j;
    int		i;

    j = 0;
    i = 0;
    width_pos = 0;
    height_pos = 0;
	t_win->img_coin = mlx_xpm_file_to_image(t_win->ptr , "./assets/coin.xpm", &width_img, &height_img);
	t_win->img_ply = mlx_xpm_file_to_image(t_win->ptr , "./assets/player.xpm", &width_img, &height_img);
    while (t_win->map[i])
	{
		j = 0;
		width_pos = 0;
		while (t_win->map[i][j])
		{
			if(t_win->map[i][j] == 'P')
				mlx_put_image_to_window(t_win->ptr ,t_win->win, t_win->img_ply, width_pos, height_pos);
            if(t_win->map[i][j] == 'C')
				mlx_put_image_to_window(t_win->ptr ,t_win->win, t_win->img_coin, width_pos, height_pos);
			width_pos += 32;
			j++;
		}
		height_pos += 32;
		i++;
	}
    return (0);
}

int ft_draw_ext(x_mlx *t_win)
{
    int		width_pos;
    int		height_pos;
	int		width_img;
	int		height_img;
    int		j;
    int		i;

    j = 0;
    i = 0;
    width_pos = 0;
    height_pos = 0;
	t_win->img_exit_c = mlx_xpm_file_to_image(t_win->ptr , "./assets/c_exit.xpm", &width_img, &height_img);
	t_win->img_exit_o = mlx_xpm_file_to_image(t_win->ptr , "./assets/o_exit.xpm", &width_img, &height_img);
    while (t_win->map[i])
	{
		j = 0;
		width_pos = 0;
		while (t_win->map[i][j])
		{
			if(t_win->map[i][j] == 'E')
			{
				if (t_win->coin_cnt == t_win->coin_eat && t_win->coin_cnt != 0 && t_win->coin_eat != 0)
					mlx_put_image_to_window(t_win->ptr ,t_win->win, t_win->img_exit_o, width_pos, height_pos);
				else
					mlx_put_image_to_window(t_win->ptr ,t_win->win, t_win->img_exit_c, width_pos, height_pos);
			}
			width_pos += 32;
			j++;
		}
		height_pos += 32;
		i++;
	}
    return (0);
}
