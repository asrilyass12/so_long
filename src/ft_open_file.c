/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilasrarf <ilasrarf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 22:18:36 by ilasrarf          #+#    #+#             */
/*   Updated: 2023/01/24 03:36:25 by ilasrarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../Libft/libft.h"

int	ft_open_file(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		write(1, "!!ERROR!!\nI can't open the file", 31);
		exit (1);
	}
	return (fd);
}
