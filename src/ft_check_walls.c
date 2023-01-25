/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilasrarf <ilasrarf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 22:18:41 by ilasrarf          #+#    #+#             */
/*   Updated: 2023/01/24 03:36:06 by ilasrarf         ###   ########.fr       */
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

int	ft_no_escape_map(char **str)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	ft_check_walls_len(str);
	ft_check_rec(str);
	len = ft_strlen(str[0]) - 1;
	while (str[i])
	{
		if (i == 0)
		{
			j = 0;
			while (str[i][j])
			{
				if (str[i][j] != '1')
				{
					write(1, "!!ERROR!!\nthe map most be close", 31);
					exit (1);
				}
				j++;
			}			
		}
		else
		{
			if (str[i][0] != '1' || str[i][len] != '1')
			{
				write(1, "!!ERROR!!\nthe map most be close", 31);
				exit (1);
			}
		}
		i++;
	}
	return (1);
}
