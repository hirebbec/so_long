/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 02:35:11 by hirebbec          #+#    #+#             */
/*   Updated: 2021/12/28 17:31:42 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "get_next_line.h"
#include <fcntl.h>
#include "moves_bonus.h"

char	*get_str(t_vars *vars)
{
	return (ft_strjoin2("steps: ", ft_itoa(vars->steps)));
}

int	main(int number, char **names)
{
	int			fd;
	t_vars		vars;

	if (number != 2)
		return (0);
	fd = open(names[1], O_RDWR);
	get_vars(&vars, fd);
	close(fd);
	fd = open(names[1], O_RDWR);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.width * 32, (vars.hight + 1) \
	* 32, "so_longl");
	vars.map = get_map(fd, &vars);
	map_cheak(&vars);
	get_current_position(vars.map, &vars);
	open_map(vars.map, &vars);
	close (fd);
	mlx_hook(vars.win, 2, 0, move, &vars);
	mlx_hook(vars.win, 17, 0, exit_map, &vars);
	mlx_loop_hook(vars.mlx, open_map_loop, &vars);
	mlx_loop(vars.mlx);
	ft_free(&vars);
}

void	draw_black(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->width)
	{
		paste_img(i * 32, vars->hight * 32, vars, 'B');
		i++;
	}
}

int	open_map(char **map, t_vars	*vars)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (i < vars->hight)
	{
		while (j < vars->width)
		{
			paste_img(j * 32, i * 32, vars, map[i][j]);
			j++;
		}
		j = 0;
		i++;
	}
	str = get_str(vars);
	draw_black(vars);
	mlx_string_put(vars->mlx, vars->win, (vars->width / 2) * 32, \
	vars->hight * 32, 0xFFFFFFFF, str);
	free (str);
	return (0);
}

int	open_map_loop(t_vars	*vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < vars->hight)
	{
		while (j < vars->width)
		{
			paste_img(j * 32, i * 32, vars, vars->map[i][j]);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
