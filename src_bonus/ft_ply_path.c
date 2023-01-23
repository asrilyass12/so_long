/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ply_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilasrarf <ilasrarf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:10:35 by ilasrarf          #+#    #+#             */
/*   Updated: 2023/01/21 19:58:21 by ilasrarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../Libft/libft.h"


int		ft_pos(char **str, int *y, int *x)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'P')
			{
				*y = i;
				*x = j;
				return (1);
			}
			j++;
	
		}
		i++;
	}
	return (0);
}

// int	ft_check_other_op()
// {

// }

int		ft_check_ply_path(char **str)
{
	int	x;
	int	y;
	int g;
	
	x = 0;
	y = 0;
	ft_pos(str, &x, &y);
	if (str[x][y + 1] == '0')
	{
		// ft_check_other_op();
		str[x][y] = 'Z';
		str[x][y + 1] = 'P';
		g = 0;
		while (str[g] != NULL)
		{
			// printf("%s\n", str[g]);
			g++;
		}
		// printf("%d == %d", x,y);
		ft_check_ply_path(str);
	}
	else if (str[x][y - 1] == '0')
	{
		str[x][y] = 'Z';
		str[x][y - 1] = 'P';
		g = 0;
		while (str[g] != NULL)
		{
			// printf("%s\n", str[g]);
			g++;
		}
		// printf("%d == %d", x,y);
		ft_check_ply_path(str);
	}
	else if (str[x - 1][y] == '0')
	{
		str[x][y] = 'Z';
		str[x - 1][y] = 'P';
		g = 0;
		while (str[g] != NULL)
		{
			// printf("%s\n", str[g]);
			g++;
		}
		// printf("%d == %d", x,y);
		ft_check_ply_path(str);
	}
	else if (str[x + 1][y] == '0')
	{
		str[x][y] = 'Z';
		str[x + 1][y] = 'P';
		g = 0;
		while (str[g] != NULL)
		{
			// printf("%s\n", str[g]);
			g++;
		}
		// printf("%d == %d", x,y);
		ft_check_ply_path(str);
	}
	return (1); 
}
