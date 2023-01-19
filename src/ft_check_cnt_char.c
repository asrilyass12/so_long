/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cnt_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilasrarf <ilasrarf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 19:00:29 by ilasrarf          #+#    #+#             */
/*   Updated: 2022/12/27 07:53:03 by ilasrarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../Libft/libft.h"

int	ft_cnt_char(char **str)
{
	int	i;
	int	j;
	int	e;
	int	c;
	int	p;
	
	j = 0;
	i = 0;
	e = 0;
	p = 0;
	c = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'E')
				e++;
			if (str[i][j] == 'P')
				p++;
			if (str[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	if (e != 1 || p != 1 || c < 1)
	{
		write(1, "!!ERROR!!\nThe map must contain 1 exit, at least 1 collectible, and 1 starting position to be valid", 98);
		exit (1);
	}
	return (1);
}
