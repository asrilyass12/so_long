/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilasrarf <ilasrarf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 22:19:04 by ilasrarf          #+#    #+#             */
/*   Updated: 2023/01/27 12:27:42 by ilasrarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../Libft/libft.h"

void	ft_err_read(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			if (i == 0 || str[i + 1] == '\0'
				|| str[i + 1] == '\n' || str[i - 1] == '\n')
			{
				write(1, "!!ERROR!!\n map not valid found extra newline", 44);
				free(str);
				exit (1);
			}
		}
		i++;
	}
}

char	**get_next_line(int fd)
{
	char		*buf;
	static char	*str;
	char		**map;
	ssize_t		read_len;

	read_len = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!str)
		str = ft_strdup("");
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (read_len)
	{
		read_len = read(fd, buf, BUFFER_SIZE);
		if (read_len < 0)
			return (free(buf), free(str), NULL);
		buf[read_len] = '\0';
		str = ft_strjoin(str, buf);
	}
	ft_err_read(str);
	map = ft_split(str, '\n');
	return (free(buf), map);
}
