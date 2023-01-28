/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilasrarf <ilasrarf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 22:18:41 by ilasrarf          #+#    #+#             */
/*   Updated: 2023/01/27 13:30:29 by ilasrarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../Libft/libft.h"

int	ft_check_walls_len(char **str)
{
	int		j;
	size_t	len;

	j = 0;
	len = ft_strlen(str[0]);
	while (str[j])
	{
		if (ft_strlen(str[j]) != len)
		{
			write(1, "!!ERROR!!\nthe length of each line is not the same", 57);
			ft_free(str);
			exit (1);
		}
		j++;
	}
	return (1);
}

int	ft_check_rec(char **str)
{
	int	len;
	int	i;

	len = ft_strlen(str[0]);
	i = 0;
	while (str[i])
		i++;
	if (i == len)
	{
		write(1, "!!ERROR!!\nthe map most be rectangular", 37);
		ft_free(str);
		exit (1);
	}
	return (1);
}	

void	ft_chack_wall_p1(char c1)
{
	if (c1 != '1')
	{
		write(1, "!!ERROR!!\nthe map most be close", 31);
		exit (1);
	}
}

void	ft_chack_wall_p2(char c1, char c2)
{
	if (c1 != '1' || c2 != '1')
	{
		write(1, "!!ERROR!!\nthe map most be close", 31);
		exit (1);
	}
}

void	ft_no_escape_map(char **str)
{
	int	i;
	int	j;
	int	len;
	int	h;

	i = -1;
	j = -1;
	h = 0;
	ft_check_walls_len(str);
	while (str[h])
		h++;
	len = ft_strlen(str[0]) - 1;
	while (str[++i])
	{
		if (i == 0 || i == h - 1)
		{
			j = 0;
			while (str[i][++j])
				ft_chack_wall_p1(str[i][j]);
		}
		else
			ft_chack_wall_p2(str[i][0], str[i][len]);
	}
}
