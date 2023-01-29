/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ply_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilasrarf <ilasrarf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 11:43:40 by ilasrarf          #+#    #+#             */
/*   Updated: 2023/01/29 15:18:39 by ilasrarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../Libft/libft.h"

void	ft_exit(void)
{
	write(1, "!!ERROR!!\nTHE MAP NOT VALID", 27);
	exit(0);
}

int	ft_check_zero(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((map[i][j] == '0' || map[i][j] == 'C' ) && (map[i][j - 1] == 'P'
				|| map[i][j + 1] == 'P' || map[i + 1][j] == 'P'
				|| map[i - 1][j] == 'P'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_final_check(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
			{
				if ((map[i][j] == 'E') && (map[i][j - 1] != 'P'
				&& map[i][j + 1] != 'P' && map[i + 1][j] != 'P'
				&& map[i - 1][j] != 'P'))
					ft_exit();
				else if (map[i][j] == 'C')
					ft_exit();
			}
			j++;
		}
		i++;
	}
}

void	ft_fill(char **str)
{
	int		i;
	int		j;
	char	**m;

	m = ft_alloc(str);
	i = 0;
	while (ft_check_zero(m))
	{
		i = 0;
		j = 0;
		while (m[i])
		{
			j = 0;
			while (m[i][j])
			{
				if ((m[i][j] == '0' || m[i][j] == 'C') && (m[i][j - 1] == 'P'
					|| m[i][j + 1] == 'P' || m[i + 1][j] == 'P'
					|| m[i - 1][j] == 'P'))
						m[i][j] = 'P';
				j++;
			}
			i++;
		}
	}
	ft_final_check(m);
}
