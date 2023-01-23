/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_coin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilasrarf <ilasrarf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 10:43:36 by ilasrarf          #+#    #+#             */
/*   Updated: 2023/01/21 19:28:46 by ilasrarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../Libft/libft.h"

int	ft_cnt_coin(t_mlx *t_win)
{
	int	i;
	int	j;
	int	cnt;

	i = 0;
	cnt = 0;
	while (t_win->map[i])
	{
		j = 0;
		while (t_win->map[i][j])
		{
			if (t_win->map[i][j] == 'C')
				cnt++;
			j++;
		}
		i++;
	}
	t_win->coin_cnt = cnt;
	return (0);
}
