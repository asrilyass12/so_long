/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilasrarf <ilasrarf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 08:33:55 by ilasrarf          #+#    #+#             */
/*   Updated: 2023/01/15 10:40:15 by ilasrarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../Libft/libft.h"

void    ft_move_write(x_mlx *t_win)
{
    t_win->move_cnt++;
    write(1, "the number of moves :", 21);
    ft_putnbr_fd(t_win->move_cnt, 1);
    write(1, "\n", 1);
}