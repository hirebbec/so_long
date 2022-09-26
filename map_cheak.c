/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_cheak.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 07:48:41 by hirebbec          #+#    #+#             */
/*   Updated: 2021/12/28 17:31:53 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "get_next_line.h"
#include "moves.h"

int	player_cheak(t_vars *vars)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	j = 0;
	p = 0;
	while (i < vars->hight)
	{
		while (j < vars->width)
		{
			if (vars->map[i][j] == 'P')
				p++;
			j++;
		}
		i++;
		j = 0;
	}
	if (p != 1)
		return (0);
	return (1);
}

int	col_cheak(t_vars *vars)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	j = 0;
	p = 0;
	while (i < vars->hight)
	{
		while (j < vars->width)
		{
			if (vars->map[i][j] == 'C')
				p++;
			j++;
		}
		i++;
		j = 0;
	}
	if (p < 1)
		return (0);
	return (1);
}

int	exit_cheak(t_vars *vars)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	j = 0;
	p = 0;
	while (i < vars->hight)
	{
		while (j < vars->width)
		{
			if (vars->map[i][j] == 'E')
				p++;
			j++;
		}
		i++;
		j = 0;
	}
	if (p < 1)
		return (0);
	return (1);
}

int	trash_cheak(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < vars->hight)
	{
		while (j < vars->width - 1)
		{
			if (vars->map[i][j] != 'C' && vars->map[i][j] != '0' && \
	vars->map[i][j] != '1' && vars->map[i][j] != 'P' && vars->map[i][j] != 'E')
				return (0);
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

int	map_cheak(t_vars *vars)
{
	if (!(player_cheak(vars)))
		map_error(vars);
	if (!(col_cheak(vars)))
		map_error(vars);
	if (!(exit_cheak(vars)))
		map_error(vars);
	if (!(trash_cheak(vars)))
		map_error(vars);
	if (!(wall_cheak(vars)))
		map_error(vars);
	return (1);
}
