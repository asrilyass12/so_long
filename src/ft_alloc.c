/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilasrarf <ilasrarf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 18:01:42 by ilasrarf          #+#    #+#             */
/*   Updated: 2023/01/29 14:05:51 by ilasrarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../Libft/libft.h"

char	**ft_alloc(char **str)
{
	int		i;
	int		len_h;
	char	**map;

	i = 0;
	len_h = 0;
	while (str[len_h])
		len_h++;
	map = malloc(sizeof(char *) * len_h + 1);
	while (str[i])
	{
		map[i] = ft_strdup(str[i]);
		i++;
	}
	map[i] = NULL;
	return (map);
}
