/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 02:39:17 by hirebbec          #+#    #+#             */
/*   Updated: 2021/12/28 18:06:05 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "get_next_line.h"
#include "moves_bonus.h"

void	get_vars(t_vars *vars, int fd)
{
	char	*str;

	vars->steps = 0;
	vars->exit = 0;
	vars->player = 0;
	str = get_next_line(fd);
	vars->hight = 0;
	vars->width = ft_strlen(str) - 1;
	while (str)
	{
		vars->hight++;
		free(str);
		str = NULL;
		str = get_next_line(fd);
	}
}

char	**get_map(int fd, t_vars	*vars)
{
	char	**map;
	int		i;

	i = 0;
	map = malloc(vars->hight * sizeof(char *));
	while (i < vars->hight)
	{	
		map[i] = get_next_line(fd);
		if ((ft_strlen(map[i])) - 1 != vars->width && i != vars->hight -1)
			map_error2(vars);
		if ((ft_strlen(map[i])) != vars->width && i == vars->hight -1)
			map_error2(vars);
		if (i != vars->hight - 1)
			map[i][ft_strlen(map[i]) - 1] = 0;
		i++;
	}
	return (map);
}

void	*exit_pic(t_vars	*vars)
{
	int	i;
	int	j;

	if (vars->exit == 0)
	{
		vars->exit++;
		return (mlx_xpm_file_to_image(vars->mlx, "./pic/exit1.xpm", &i, &j));
	}
	if (vars->exit == 1)
	{
		vars->exit++;
		return (mlx_xpm_file_to_image(vars->mlx, "./pic/exit2.xpm", &i, &j));
	}
	if (vars->exit == 2)
	{
		vars->exit = 0;
		return (mlx_xpm_file_to_image(vars->mlx, "./pic/exit3.xpm", &i, &j));
	}
	return (NULL);
}

void	*player_pic(t_vars	*vars)
{
	int		i;
	int		j;
	void	*img;

	if (vars->player == 0)
		img = (mlx_xpm_file_to_image(vars->mlx, "./pic/player1.xpm", &i, &j));
	if (vars->player == 1)
		img = (mlx_xpm_file_to_image(vars->mlx, "./pic/fly1.xpm", &i, &j));
	if (vars->player == 2)
		img = (mlx_xpm_file_to_image(vars->mlx, "./pic/fly2.xpm", &i, &j));
	if (vars->player == 3)
		img = (mlx_xpm_file_to_image(vars->mlx, "./pic/fly3.xpm", &i, &j));
	if (vars->player == 4)
		img = (mlx_xpm_file_to_image(vars->mlx, "./pic/fly4.xpm", &i, &j));
	if (vars->player == 5)
		img = (mlx_xpm_file_to_image(vars->mlx, "./pic/fly5.xpm", &i, &j));
	if (vars->player == 6)
		img = (mlx_xpm_file_to_image(vars->mlx, "./pic/fly6.xpm", &i, &j));
	if (vars->player != 6)
		vars->player++;
	else
		vars->player = 0;
	return (img);
}

void	paste_img(int x, int y, t_vars *vars, char c)
{
	void	*img;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (c == 'P')
		img = player_pic(vars);
	else if (c == '0')
		img = mlx_xpm_file_to_image(vars->mlx, "./pic/void.xpm", &i, &j);
	else if (c == 'C')
		img = mlx_xpm_file_to_image(vars->mlx, "./pic/item.xpm", &i, &j);
	else if (c == 'E')
		img = exit_pic(vars);
	else if (c == 'R')
		img = mlx_xpm_file_to_image(vars->mlx, "./pic/enemy.xpm", &i, &j);
	else if (c == 'B')
		img = mlx_xpm_file_to_image(vars->mlx, "./pic/black.xpm", &i, &j);
	else
		img = mlx_xpm_file_to_image(vars->mlx, "./pic/wall.xpm", &i, &j);
	mlx_put_image_to_window(vars->mlx, vars->win, img, x, y);
	mlx_destroy_image(vars->mlx, img);
}
