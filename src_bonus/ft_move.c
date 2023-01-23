/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilasrarf <ilasrarf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 09:05:22 by ilasrarf          #+#    #+#             */
/*   Updated: 2023/01/23 20:22:36 by ilasrarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../Libft/libft.h"

int	ft_move_up(t_mlx *t_win)
{
	int	x;
	int	y;

	ft_pos(t_win->map, &x, &y);
	if (t_win->map[x - 1][y] == '0' || t_win->map[x - 1][y] == 'C'
		|| t_win->map[x - 1][y] == 'E' || t_win->map[x - 1][y] == 'M')
	{
		if (t_win->map[x - 1][y] == 'C')
			t_win->coin_eat++;
		if (t_win->map[x - 1][y] == 'E' && t_win->coin_cnt == t_win->coin_eat)
		{
			ft_destroy(t_win);
			write(1, "YOU WIN THE GAME <3", 19);
			exit(1);
		}
		if (t_win->map[x - 1][y] == 'M')
		{
			ft_destroy(t_win);
			write(1, "YOU LOSE THE GAME <3", 20);
			exit(1);
		}
		t_win->map[x - 1][y] = 'P';
		t_win->map[x][y] = '0';
		t_win->move_cnt++;
	}
	ft_draw(t_win, t_win->root);
	return (0);
}

int	ft_move_left(t_mlx *t_win)
{
	int	x;
	int	y;

	ft_pos(t_win->map, &x, &y);
	if (t_win->map[x][y + 1] == '0' || t_win->map[x][y + 1] == 'C'
		|| t_win->map[x][y + 1] == 'E' || t_win->map[x][y + 1] == 'M')
	{
		if (t_win->map[x][y + 1] == 'C')
			t_win->coin_eat++;
		if (t_win->map[x][y + 1] == 'E' && t_win->coin_cnt == t_win->coin_eat)
		{
			ft_destroy(t_win);
			write(1, "YOU WIN THE GAME <3", 19);
			exit(1);
		}
		if (t_win->map[x][y + 1] == 'M')
		{
			ft_destroy(t_win);
			write(1, "YOU LOSE THE GAME <3", 20);
			exit(1);
		}
		t_win->map[x][y + 1] = 'P';
		t_win->map[x][y] = '0';
		t_win->move_cnt++;
	}
	t_win->root = 'r';
	ft_draw(t_win , t_win->root);
	return (0);
}

int	ft_move_right(t_mlx *t_win)
{
	int	x;
	int	y;

	ft_pos(t_win->map, &x, &y);
	if (t_win->map[x][y - 1] == '0' || t_win->map[x][y - 1] == 'C'
		|| t_win->map[x][y - 1] == 'E' || t_win->map[x][y - 1] == 'M')
	{
		if (t_win->map[x][y - 1] == 'C')
			t_win->coin_eat++;
		if (t_win->map[x][y - 1] == 'E' && t_win->coin_cnt == t_win->coin_eat)
		{
			ft_destroy(t_win);
			write(1, "YOU WIN THE GAME <3", 19);
			exit(1);
		}
		if (t_win->map[x][y - 1] == 'M')
		{
			ft_destroy(t_win);
			write(1, "YOU LOSE THE GAME <3", 20);
			exit(1);
		}
		t_win->map[x][y - 1] = 'P';
		t_win->map[x][y] = '0';
		t_win->move_cnt++;
	}
	t_win->root = 'l';
	ft_draw(t_win, t_win->root);
	return (0);
}

int	ft_move_down(t_mlx *t_win)
{
	int	x;
	int	y;

	ft_pos(t_win->map, &x, &y);
	if (t_win->map[x + 1][y] == '0' || t_win->map[x + 1][y] == 'C'
		|| t_win->map[x + 1][y] == 'E' || t_win->map[x + 1][y] == 'M')
	{
		if (t_win->map[x + 1][y] == 'C')
			t_win->coin_eat++;
		if (t_win->map[x + 1][y] == 'E' && t_win->coin_cnt == t_win->coin_eat)
		{
			ft_destroy(t_win);
			write(1, "YOU WIN THE GAME <3", 19);
			exit(1);
		}
		if (t_win->map[x + 1][y] == 'M')
		{
			ft_destroy(t_win);
			write(1, "YOU LOSE THE GAME <3", 20);
			exit(1);
		}
		t_win->map[x + 1][y] = 'P';
		t_win->map[x][y] = '0';
		t_win->move_cnt++;
	}
	ft_draw(t_win, t_win->root);
	return (0);
}

int	ft_key_check(int key, t_mlx *t_win)
{
	if (key == 13 || key == 126)
	{
		mlx_clear_window(t_win->ptr, t_win->win);
		ft_move_up(t_win);
	}
	else if (key == 0 || key == 123)
	{
		mlx_clear_window(t_win->ptr, t_win->win);
		ft_move_right(t_win);
	}
	else if (key == 1 || key == 125)
	{
		mlx_clear_window(t_win->ptr, t_win->win);
		ft_move_down(t_win);
	}
	else if (key == 2 || key == 124)
	{
		mlx_clear_window(t_win->ptr, t_win->win);
		ft_move_left(t_win);
	}
	if (key == 53)
	{
		ft_destroy(t_win);
		exit(1);
	}
	return (0);
}
