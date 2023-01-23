/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilasrarf <ilasrarf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:49:33 by ilasrarf          #+#    #+#             */
/*   Updated: 2023/01/23 16:54:47 by ilasrarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../Libft/libft.h"

int ft_write_moves(t_mlx *t_win)
{
	write(1, "move :", 6);
	ft_putnbr_fd(t_win->move_cnt, 1);
	write(1, "\n", 1);
	return (0);
}