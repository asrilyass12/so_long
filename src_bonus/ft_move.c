/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilasrarf <ilasrarf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 09:05:22 by ilasrarf          #+#    #+#             */
/*   Updated: 2023/01/28 10:05:36 by ilasrarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "../Libft/libft.h"

int	ft_move_up(t_mlx *t_win, void *img)
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
			ft_mess(t_win, "YOU WIN THE GAME");
		}
		if (t_win->map[x - 1][y] == 'M')
		{
			ft_mess(t_win, "YOU LOSE THE GAME");
		}
		t_win->map[x - 1][y] = 'P';
		t_win->map[x][y] = '0';
		t_win->move_cnt++;
	}
	ft_draw(t_win, img, t_win->root);
	return (0);
}

int	ft_move_left(t_mlx *t_win, void *img)
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
			ft_mess(t_win, "YOU WIN THE GAME");
		}
		if (t_win->map[x][y + 1] == 'M')
		{
			ft_mess(t_win, "YOU LOSE THE GAME");
		}
		t_win->map[x][y + 1] = 'P';
		t_win->map[x][y] = '0';
		t_win->move_cnt++;
	}
	t_win->root = 'r';
	ft_draw(t_win, img, t_win->root);
	return (0);
}

int	ft_move_right(t_mlx *t_win, void *img)
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
			ft_mess(t_win, "YOU WIN THE GAME");
		}
		if (t_win->map[x][y - 1] == 'M')
		{
			ft_mess(t_win, "YOU LOSE THE GAME");
		}
		t_win->map[x][y - 1] = 'P';
		t_win->map[x][y] = '0';
		t_win->move_cnt++;
	}
	t_win->root = 'l';
	ft_draw(t_win, img, t_win->root);
	return (0);
}

int	ft_move_down(t_mlx *t_win, void *img)
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
			ft_mess(t_win, "YOU WIN THE GAME");
		}
		if (t_win->map[x + 1][y] == 'M')
		{
			ft_mess(t_win, "YOU LOSE THE GAME");
		}
		t_win->map[x + 1][y] = 'P';
		t_win->map[x][y] = '0';
		t_win->move_cnt++;
	}
	ft_draw(t_win, img, t_win->root);
	return (0);
}

int	ft_key_check(int key, t_mlx *t_win)
{
	if (key == 13 || key == 126)
	{
		ft_up(t_win);
	}
	else if (key == 0 || key == 123)
	{
		ft_right(t_win);
	}
	else if (key == 1 || key == 125)
	{
		ft_down(t_win);
	}
	else if (key == 2 || key == 124)
	{
		ft_left(t_win);
	}
	if (key == 53)
		ft_mess(t_win, "BAY BAY");
	return (0);
}
