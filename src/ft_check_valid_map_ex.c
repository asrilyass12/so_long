/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid_map_ex.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilasrarf <ilasrarf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 22:18:32 by ilasrarf          #+#    #+#             */
/*   Updated: 2023/01/24 03:36:03 by ilasrarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../Libft/libft.h"

int	ft_check_ex(char *haystack)
{
	int	i;
	int	len;

	i = 0;
	while (haystack[i])
	{
		if (haystack[i] == '.')
			break ;
		i++;
	}
	len = ft_strlen(haystack + i);
	i = ft_strncmp(".ber", haystack + i, len);
	if (i != 0)
	{
		write(1, "!!ERROR!!\nthe extension it's not allowed", 40);
		exit (1);
	}
	return (1);
}
