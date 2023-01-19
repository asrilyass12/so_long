/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilasrarf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:16:53 by ilasrarf          #+#    #+#             */
/*   Updated: 2022/10/30 00:47:17 by ilasrarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len_s1;

	if (!s1)
		return (0);
	while (s1[0] && ft_strchr(set, s1[0]))
		s1++;
	len_s1 = ft_strlen(s1);
	while (len_s1 > 0 && ft_strrchr(set, s1[len_s1 - 1]))
		len_s1--;
	return (ft_substr(s1, 0, len_s1));
}
