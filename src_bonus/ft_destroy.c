/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilasrarf <ilasrarf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 03:12:27 by ilasrarf          #+#    #+#             */
/*   Updated: 2023/01/25 06:31:23 by ilasrarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "../Libft/libft.h"

int	ft_destroy(t_mlx *t_win)
{
	mlx_destroy_image(t_win->ptr, t_win->img_wall);
	mlx_destroy_image(t_win->ptr, t_win->img_flor);
	mlx_destroy_image(t_win->ptr, t_win->img_coin);
	mlx_destroy_image(t_win->ptr, t_win->img_plyl);
	mlx_destroy_image(t_win->ptr, t_win->img_plyr);
	mlx_destroy_image(t_win->ptr, t_win->img_exit_o);
	mlx_destroy_image(t_win->ptr, t_win->img_enemy1);
	mlx_destroy_image(t_win->ptr, t_win->img_enemy2);
	mlx_destroy_image(t_win->ptr, t_win->img_enemy3);
	mlx_destroy_image(t_win->ptr, t_win->img_enemy4);
	mlx_destroy_image(t_win->ptr, t_win->img_enemy5);
	mlx_destroy_image(t_win->ptr, t_win->img_enemy6);
	mlx_clear_window(t_win->ptr, t_win->win);
	mlx_destroy_window(t_win->ptr, t_win->win);
	return (0);
}


int ft_destroy_frame(t_mlx *t_win)
{
	mlx_destroy_image(t_win->ptr, t_win->img_enemy1);
	mlx_destroy_image(t_win->ptr, t_win->img_enemy2);
	mlx_destroy_image(t_win->ptr, t_win->img_enemy3);
	return (0);
}