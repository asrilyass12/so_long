/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilasrarf <ilasrarf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 09:05:22 by ilasrarf          #+#    #+#             */
/*   Updated: 2023/01/15 11:32:45 by ilasrarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../Libft/libft.h"

int ft_move_up(x_mlx *t_win)
{
    int x;
    int y;
    
    ft_pos(t_win->map, &x, &y);
    if (t_win->map[x - 1][y] == '0' || t_win->map[x - 1][y] == 'C')
    {
        if (t_win->map[x - 1][y] == 'C')
            t_win->coin_eat++;
        t_win->map[x - 1][y] = 'P';
        t_win->map[x][y] = '0';
        ft_move_write(t_win);
    }
    ft_draw(t_win);
    return(0);
}

int ft_move_left(x_mlx *t_win)
{
    int x;
    int y;
    
    ft_pos(t_win->map, &x, &y);
    if (t_win->map[x][y + 1] == '0' || t_win->map[x][y + 1] == 'C')
    {
        if (t_win->map[x][y + 1] == 'C')
            t_win->coin_eat++;
        t_win->map[x][y + 1] = 'P';
        t_win->map[x][y] = '0';
        ft_move_write(t_win);
    }
    ft_draw(t_win);
    return(0);
}

int ft_move_right(x_mlx *t_win)
{
    int x;
    int y;
    
    ft_pos(t_win->map, &x, &y);
    if (t_win->map[x][y - 1] == '0' || t_win->map[x][y - 1] == 'C')
    {
        if (t_win->map[x][y - 1] == 'C')
            t_win->coin_eat++;
        t_win->map[x][y - 1] = 'P';
        t_win->map[x][y] = '0';
        ft_move_write(t_win);
    }
    ft_draw(t_win);
    return(0);
}

int ft_move_down(x_mlx *t_win)
{
    int x;
    int y;
    
    ft_pos(t_win->map, &x, &y);
    if (t_win->map[x + 1][y] == '0' || t_win->map[x + 1][y] == 'C')
    {
        if (t_win->map[x + 1][y] == 'C')
            t_win->coin_eat++;
        t_win->map[x + 1][y] = 'P';
        t_win->map[x][y] = '0';
        ft_move_write(t_win);
    }
    ft_draw(t_win);
    return(0);
}

int ft_key_check(int key, x_mlx *t_win)
{
    if (key == 119)
    {
        mlx_clear_window(t_win->ptr, t_win->win);
        ft_move_up(t_win);
    }
    else if (key == 97)
    {
        mlx_clear_window(t_win->ptr, t_win->win);
        ft_move_right(t_win);
    }
    else if (key == 115)
    {
        mlx_clear_window(t_win->ptr, t_win->win);
        ft_move_down(t_win);
    }
    else if (key == 100)
    {
        mlx_clear_window(t_win->ptr, t_win->win);
        ft_move_left(t_win);
    }
    if (key == 65307)
        exit(0);
    return(0);
}