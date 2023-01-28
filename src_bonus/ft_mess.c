/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mess.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilasrarf <ilasrarf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 08:06:40 by ilasrarf          #+#    #+#             */
/*   Updated: 2023/01/28 10:03:12 by ilasrarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "../Libft/libft.h"

void	ft_mess(t_mlx *t_win, char *str)
{
	ft_destroy(t_win);
	write(1, str, ft_strlen(str));
	exit(1);
}
