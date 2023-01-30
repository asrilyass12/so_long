/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cnt_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilasrarf <ilasrarf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 19:00:29 by ilasrarf          #+#    #+#             */
/*   Updated: 2023/01/30 08:56:45 by ilasrarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../Libft/libft.h"

int	ft_cnt_char_err(t_pars *pars)
{
	if (pars->e != 1 || pars->p != 1 || pars->c < 1)
	{
		write(1, "!!ERROR!!\nThe map must contain the exact num of sprits", 54);
		exit (1);
	}
	return (0);
}

void	ft_cnt_char(char **str, t_pars *pars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	pars->e = 0;
	pars->p = 0;
	pars->c = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'E')
				pars->e++;
			if (str[i][j] == 'P')
				pars->p++;
			if (str[i][j] == 'C')
				pars->c++;
			j++;
		}
		i++;
	}
	ft_cnt_char_err(pars);
}
