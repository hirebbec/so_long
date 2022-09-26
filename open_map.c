/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 02:39:17 by hirebbec          #+#    #+#             */
/*   Updated: 2021/12/28 18:14:45 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "get_next_line.h"
#include "moves.h"

void	get_vars(t_vars *vars, int fd)
{
	char	*str;

	vars->steps = 0;
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

void	paste_img(int x, int y, t_vars *vars, char c)
{
	void	*img;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (c == 'P')
		img = mlx_xpm_file_to_image(vars->mlx, "./pic/player1.xpm", &i, &j);
	else if (c == '0')
		img = mlx_xpm_file_to_image(vars->mlx, "./pic/void.xpm", &i, &j);
	else if (c == 'C')
		img = mlx_xpm_file_to_image(vars->mlx, "./pic/item.xpm", &i, &j);
	else if (c == 'E')
		img = mlx_xpm_file_to_image(vars->mlx, "./pic/exit1.xpm", &i, &j);
	else
		img = mlx_xpm_file_to_image(vars->mlx, "./pic/wall.xpm", &i, &j);
	mlx_put_image_to_window(vars->mlx, vars->win, img, x, y);
	mlx_destroy_image(vars->mlx, img);
}

int	open_map(char **map, t_vars	*vars)
{
	int	i;
	int	j;

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
	return (0);
}

void	ft_free(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->hight)
	{
		free(vars->map[i]);
		i++;
	}
	free(vars->map);
}
