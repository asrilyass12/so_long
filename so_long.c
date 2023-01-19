/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilasrarf <ilasrarf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 22:05:40 by ilasrarf          #+#    #+#             */
/*   Updated: 2023/01/15 10:59:27 by ilasrarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_draw(x_mlx *t_win)
{
	ft_draw_w_f(t_win);
	ft_draw_p_c(t_win);
	ft_draw_ext(t_win);
}
int	ft_map_file(char *str)
{
	int	fd;

	fd = ft_open_file(str); 
	ft_check_ex(str);
	return (fd);
}

char	**ft_error(char *av)
{
	char	**map;
	int		fd;
	
	fd = ft_map_file(av);
	map = get_next_line(fd);
	ft_no_escape_map(map);
	ft_check_characters(map);
	ft_check_extra(map);
	ft_cnt_char(map);
	return (map);
}

int main(int ac, char **av)
{
	x_mlx	t_win;
	
	t_win.move_cnt = 0;
	t_win.coin_eat = 0;
	t_win.map = ft_error(av[1]);
	t_win.ptr = mlx_init();
	t_win.win = mlx_new_window(t_win.ptr, ft_strlen(t_win.map[0]) * 32,ft_cnt_h(t_win.map) * 32, "so_long");
	// ft_check_ply_path(map);
	ft_draw(&t_win);
	mlx_key_hook(t_win.win, ft_key_check, &t_win);
	mlx_loop(t_win.ptr);
	// return(0);
}
