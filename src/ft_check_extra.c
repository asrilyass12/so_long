/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_extra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilasrarf <ilasrarf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 00:16:01 by ilasrarf          #+#    #+#             */
/*   Updated: 2023/01/24 03:36:01 by ilasrarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../Libft/libft.h"

int	ft_check_characters(char **str, t_pars *pars)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strchr(str[i], '1'))
			pars->one = 1;
		if (ft_strchr(str[i], '0'))
			pars->zero = 1;
		if (ft_strchr(str[i], 'E'))
			pars->e = 1;
		if (ft_strchr(str[i], 'P'))
			pars->p = 1;
		if (ft_strchr(str[i], 'C'))
			pars->c = 1;
		i++;
	}
	pars->sum = pars->one + pars->zero + pars->c + pars->e + pars->p;
	if (pars->sum != 5)
	{
		write(1, "!!ERROR!!\nmiss characters!", 26);
		exit (1);
	}
	return (1);
}

int	ft_check_extra(char **str)
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
			if (str[i][j] != '1' && str[i][j] != '0' && str[i][j] != 'E'
				&& str[i][j] != 'C' && str[i][j] != 'P')
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
