/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_enemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilasrarf <ilasrarf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 08:10:46 by ilasrarf          #+#    #+#             */
/*   Updated: 2023/01/30 08:40:01 by ilasrarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "../Libft/libft.h"

void	ft_find_p(t_mlx *t_win)
{
	int	i;
	int	j;

	i = 0;
	while (t_win->map[i])
	{
		j = 0;
		while (t_win->map[i][j])
		{
			if (t_win->map[i][j] == 'P')
				return ;
			j++;
		}
		i++;
	}
	ft_destroy(t_win);
	exit(1);
}

void	ft_cnt_enemy(t_mlx *t_win)
{
	int	i;
	int	j;

	i = 0;
	t_win->enemy_cnt = 0;
	while (t_win->map[i])
	{
		j = 0;
		while (t_win->map[i][j])
		{
			if (t_win->map[i][j] == 'M')
				t_win->enemy_cnt++;
			j++;
		}
		i++;
	}
}

int	*ft_get_all_pos(t_mlx *t_win)
{
	int	i;
	int	j;
	int	c;
	int	*pos_enemy;

	i = 0;
	c = 0;
	ft_cnt_enemy(t_win);
	pos_enemy = malloc(sizeof(t_data_pos) * t_win->enemy_cnt);
	while (t_win->map[i])
	{
		j = 0;
		while (t_win->map[i][j])
		{
			if (t_win->map[i][j] == 'M')
			{
				pos_enemy[c++] = i;
				pos_enemy[c++] = j;
			}
			j++;
		}
		i++;
	}
	return (pos_enemy);
}

void	ft_move_enemy(t_mlx *t_win)
{
	int			i;
	int			*tab;

	i = 0;
	tab = ft_get_all_pos(t_win);
	while (i + 1 < t_win->enemy_cnt * 2)
	{
		if ((t_win->map[tab[i]][tab[i + 1] + 1] == '0'
			|| t_win->map[tab[i]][tab[i + 1] + 1] == 'P'))
		{
			t_win->map[tab[i]][tab[i + 1] + 1] = 'M';
			t_win->map[tab[i]][tab[i + 1]] = '0';
		}
		else if ((t_win->map[tab[i]][tab[i + 1] - 1] == '0'
			|| t_win->map[tab[i]][tab[i + 1] - 1] == 'P'))
		{
			t_win->map[tab[i]][tab[i + 1] - 1] = 'M';
			t_win->map[tab[i]][tab[i + 1]] = '0';
		}
		i += 2;
	}
	free(tab);
}
