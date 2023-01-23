/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilasrarf <ilasrarf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 22:05:40 by ilasrarf          #+#    #+#             */
/*   Updated: 2023/01/23 04:16:18 by ilasrarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_draw(t_mlx *t_win, char root)
{
	char	*str;
	int		h;

	h = ft_cnt_h(t_win->map);
	ft_put_img(t_win);
	ft_draw_w_f(t_win);
	ft_draw_p_c(t_win, root);
	ft_draw_ext(t_win);
	str = ft_itoa(t_win->move_cnt);
	mlx_string_put(t_win->ptr, t_win->win, 2, h * 64 + 32, 0xFFFFFF, "move:");
	mlx_string_put(t_win->ptr, t_win->win, 64, h * 64 + 32, 0xFFFFFF, str);
	if (t_win->coin_cnt != t_win->coin_eat)
	{
		mlx_string_put(t_win->ptr, t_win->win, 5, 5, 0xFFFFFF, "hey boy \
			your mission is to collect all coins to be rich and be careful xD ");
	}
	else if (t_win->coin_cnt == t_win->coin_eat)
	{
		mlx_string_put(t_win->ptr, t_win->win, 5, 5, 0xFFFFFF, "hhhhhhhhhh \
			ghalik bgha yweli rich hhhh sir sir f7alk");
	}
	free(str);
	return (0);
}

int	ft_map_file(char *str)
{
	int	fd;

	fd = ft_open_file(str);
	ft_check_ex(str);
	return (fd);
}

char	**ft_error(char *av, t_pars *pars)
{
	char	**map;
	int		fd;

	fd = ft_map_file(av);
	map = get_next_line(fd);
	ft_no_escape_map(map);
	ft_check_characters(map, pars);
	ft_check_extra(map);
	ft_cnt_char(map, pars);
	return (map);
}

int	mouse_hook(t_mlx *t_win)
{
	ft_destroy(t_win);
	exit(1);
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx	t_win;
	t_pars	pars;

	if (ac != 2)
		return (0);
	t_win.move_cnt = 0;
	t_win.coin_eat = 0;
	t_win.root = 'r';
	t_win.map = ft_error(av[1], &pars);
	ft_cnt_coin(&t_win);
	t_win.ptr = mlx_init();
	t_win.win = mlx_new_window(t_win.ptr, ft_strlen(t_win.map[0])
			* 64, ft_cnt_h(t_win.map) * 64 + 64, "so_long");
	ft_draw(&t_win, t_win.root);
	mlx_key_hook(t_win.win, ft_key_check, &t_win);
	mlx_hook(t_win.win, 17, 0, &mouse_hook, &t_win);
	mlx_loop(t_win.ptr);
	return (0);
}
