/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_extra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilasrarf <ilasrarf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 00:16:01 by ilasrarf          #+#    #+#             */
/*   Updated: 2022/12/27 09:37:23 by ilasrarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../Libft/libft.h"

int	ft_check_characters(char **str)
{
	int i;
	int zero;
	int one;
	int c;
	int e;
	int p;
	int sum;
	
	i = 0;
	while (str[i])
	{
		if(ft_strchr(str[i], '1'))
			one = 1;
		if(ft_strchr(str[i], '0'))
			zero = 1;
		if(ft_strchr(str[i], 'E'))
			e = 1;
		if(ft_strchr(str[i], 'P'))
			p = 1;
		if(ft_strchr(str[i], 'C'))
			c = 1;
		i++;
	}
	sum = one + zero + c + e + p;
	if(sum != 5)
	{
		write(1, "!!ERROR!!\nmiss characters!", 26);
		exit (1);
	}
	return (1);
}

int	ft_check_extra(char **str)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] != '1' && str[i][j] != '0' && str[i][j] != 'E' && str[i][j] != 'C' && str[i][j] != 'P')
			{
				write(1, "!!ERROR!!\nthe map has contain extra characters", 46);
				exit (1);
			}
			j++;
		}
		i++;
	}
	return (1);
}