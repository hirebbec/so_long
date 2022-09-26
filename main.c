/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 02:35:11 by hirebbec          #+#    #+#             */
/*   Updated: 2021/12/28 17:31:46 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "get_next_line.h"
#include <fcntl.h>
#include "moves.h"

int	exit_map(t_vars *vars)
{
	ft_free(vars);
	printf("end\n");
	exit (1);
	return (0);
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
	vars.win = mlx_new_window(vars.mlx, vars.width * 32, vars.hight \
	* 32, "so_longl");
	vars.map = get_map(fd, &vars);
	map_cheak(&vars);
	get_current_position(vars.map, &vars);
	open_map(vars.map, &vars);
	close (fd);
	mlx_hook(vars.win, 2, 0, move, &vars);
	mlx_hook(vars.win, 17, 0, exit_map, &vars);
	mlx_loop(vars.mlx);
	ft_free(&vars);
}
