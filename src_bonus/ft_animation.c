/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilasrarf <ilasrarf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 04:40:01 by ilasrarf          #+#    #+#             */
/*   Updated: 2023/01/27 14:25:54 by ilasrarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "../Libft/libft.h"

int	ft_animation(t_mlx *t_win)
{
	static int	lop = 0;

	ft_find_p(t_win);
	if (lop <= 10)
	{
		t_win->cv = 1;
		ft_draw(t_win, t_win->img_enemy1, t_win->root);
	}
	else if (lop <= 20)
	{
		t_win->cv = 2;
		ft_draw(t_win, t_win->img_enemy2, t_win->root);
	}
	else if (lop <= 30)
	{
		t_win->cv = 3;
		ft_draw(t_win, t_win->img_enemy3, t_win->root);
	}
	else if (lop == 31)
		ft_move_enemy(t_win);
	else
		lop = 0;
	lop ++;
	return (0);
}
