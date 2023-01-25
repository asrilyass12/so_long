/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_enemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilasrarf <ilasrarf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 08:10:46 by ilasrarf          #+#    #+#             */
/*   Updated: 2023/01/25 08:21:13 by ilasrarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "../Libft/libft.h"

int ft_cnt_enemy(t_mlx *t_win)
{
	int	i;
	int	j;
	
	t_win->enemy_cnt = 0;
	i = 0;
	while(t_win->map[i])
	{
		j = 0;
		while (t_win->map[i][j])
		{
			if(t_win->map[i][j] == 'M')
				t_win->enemy_cnt++;
			j++;
		}
		i++;
	}
}

int	get_enemey_pos(t_mlx *t_win)
{
	
}

int	ft_move_enemy(t_mlx *t_win)
{
	
}