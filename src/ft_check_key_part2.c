/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_key_part2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilasrarf <ilasrarf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 13:53:06 by ilasrarf          #+#    #+#             */
/*   Updated: 2023/01/29 13:55:08 by ilasrarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../Libft/libft.h"

void	ft_up(t_mlx *t_win)
{
	mlx_clear_window(t_win->ptr, t_win->win);
	ft_move_up(t_win);
}

void	ft_right(t_mlx *t_win)
{
	mlx_clear_window(t_win->ptr, t_win->win);
	ft_move_right(t_win);
}

void	ft_down(t_mlx *t_win)
{
	mlx_clear_window(t_win->ptr, t_win->win);
	ft_move_down(t_win);
}

void	ft_left(t_mlx *t_win)
{
	mlx_clear_window(t_win->ptr, t_win->win);
	ft_move_left(t_win);
}
