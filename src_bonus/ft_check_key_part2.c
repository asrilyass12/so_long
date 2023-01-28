/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_key_part2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilasrarf <ilasrarf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 08:57:54 by ilasrarf          #+#    #+#             */
/*   Updated: 2023/01/28 10:03:53 by ilasrarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "../Libft/libft.h"

void	ft_up(t_mlx *t_win)
{
	mlx_clear_window(t_win->ptr, t_win->win);
	if (t_win->cv == 1)
		ft_move_up(t_win, t_win->img_enemy1);
	if (t_win->cv == 2)
		ft_move_up(t_win, t_win->img_enemy2);
	if (t_win->cv == 3)
		ft_move_up(t_win, t_win->img_enemy3);
}

void	ft_right(t_mlx *t_win)
{
	mlx_clear_window(t_win->ptr, t_win->win);
	if (t_win->cv == 1)
		ft_move_right(t_win, t_win->img_enemy1);
	if (t_win->cv == 2)
		ft_move_right(t_win, t_win->img_enemy2);
	if (t_win->cv == 3)
		ft_move_right(t_win, t_win->img_enemy3);
}

void	ft_down(t_mlx *t_win)
{
	mlx_clear_window(t_win->ptr, t_win->win);
	if (t_win->cv == 1)
		ft_move_down(t_win, t_win->img_enemy1);
	if (t_win->cv == 2)
		ft_move_down(t_win, t_win->img_enemy2);
	if (t_win->cv == 3)
		ft_move_down(t_win, t_win->img_enemy3);
}

void	ft_left(t_mlx *t_win)
{
	mlx_clear_window(t_win->ptr, t_win->win);
	if (t_win->cv == 1)
		ft_move_left(t_win, t_win->img_enemy1);
	if (t_win->cv == 2)
		ft_move_left(t_win, t_win->img_enemy2);
	if (t_win->cv == 3)
		ft_move_left(t_win, t_win->img_enemy3);
}
