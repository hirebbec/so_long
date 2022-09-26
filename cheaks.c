/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheaks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 03:30:45 by hirebbec          #+#    #+#             */
/*   Updated: 2021/12/28 18:18:04 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "moves.h"
#include "get_next_line.h"

int	get_current_position(char **map, t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < vars->hight)
	{
		while (j < vars->width)
		{
			if (map[i][j] == 'P')
			{
				vars->player_x = j;
				vars->player_y = i;
				return (0);
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

int	c_chek(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < vars->hight)
	{
		while (j < vars->width)
		{
			if (vars->map[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

int	wall_cheak(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->hight)
		if (vars->map[i++][0] != '1')
			return (0);
	i = 0;
	while (i < vars->hight)
		if (vars->map[i++][vars->width - 1] != '1')
			return (0);
	i = 0;
	while (i < vars->width)
		if (vars->map[0][i++] != '1')
			return (0);
	i = 0;
	while (i < vars->width)
		if (vars->map[vars->hight - 1][i++] != '1')
			return (0);
	return (1);
}

void	map_error(t_vars *vars)
{
	ft_free(vars);
	printf("map error\n");
	exit (1);
}

void	map_error2(t_vars *vars)
{
	vars->hight = 0;
	printf("map error\n");
	exit (1);
}
