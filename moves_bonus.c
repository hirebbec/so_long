/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 02:35:58 by hirebbec          #+#    #+#             */
/*   Updated: 2021/12/28 17:31:58 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "moves_bonus.h"
#include "get_next_line.h"

int	w_move(t_vars *vars)
{
	if (vars->map[vars->player_y - 1][vars->player_x] == 'E' && !(c_chek(vars)))
	{
		ft_free(vars);
		printf("You win!\n");
		exit (1);
	}
	if (vars->map[vars->player_y - 1][vars->player_x] == 'R')
	{
		ft_free(vars);
		printf("You lose!\n");
		exit (1);
	}
	if (vars->map[vars->player_y - 1][vars->player_x] == '1')
		return (0);
	if (vars->map[vars->player_y - 1][vars->player_x] == 'E')
		return (0);
	vars->map[vars->player_y][vars->player_x] = '0';
	vars->player_y--;
	vars->steps++;
	printf("Steps:%d\n", vars->steps);
	return (1);
}

int	s_move(t_vars *vars)
{
	if (vars->map[vars->player_y + 1][vars->player_x] == 'E' && !(c_chek(vars)))
	{
		ft_free(vars);
		printf("You win!\n");
		exit (1);
	}
	if (vars->map[vars->player_y + 1][vars->player_x] == 'R')
	{
		ft_free(vars);
		printf("You lose!\n");
		exit (1);
	}
	if (vars->map[vars->player_y + 1][vars->player_x] == '1')
		return (0);
	if (vars->map[vars->player_y + 1][vars->player_x] == 'E')
		return (0);
	vars->map[vars->player_y][vars->player_x] = '0';
	vars->player_y++;
	vars->steps++;
	printf("Steps:%d\n", vars->steps);
	return (1);
}

int	a_move(t_vars *vars)
{
	if (vars->map[vars->player_y][vars->player_x - 1] == 'E' && !(c_chek(vars)))
	{
		ft_free(vars);
		printf("You win!\n");
		exit (1);
	}
	if (vars->map[vars->player_y][vars->player_x - 1] == 'R')
	{
		ft_free(vars);
		printf("You lose!\n");
		exit (1);
	}
	if (vars->map[vars->player_y][vars->player_x - 1] == '1')
		return (0);
	if (vars->map[vars->player_y][vars->player_x - 1] == 'E')
		return (0);
	vars->map[vars->player_y][vars->player_x] = '0';
	vars->player_x--;
	vars->steps++;
	printf("Steps:%d\n", vars->steps);
	return (1);
}

int	d_move(t_vars *vars)
{
	if (vars->map[vars->player_y][vars->player_x + 1] == 'E' && !(c_chek(vars)))
	{
		ft_free(vars);
		printf("You win!\n");
		exit (1);
	}
	if (vars->map[vars->player_y][vars->player_x + 1] == 'R')
	{
		ft_free(vars);
		printf("You lose!\n");
		exit (1);
	}
	if (vars->map[vars->player_y][vars->player_x + 1] == '1')
		return (0);
	if (vars->map[vars->player_y][vars->player_x + 1] == 'E')
		return (0);
	vars->map[vars->player_y][vars->player_x] = '0';
	vars->player_x++;
	vars->steps++;
	printf("Steps:%d\n", vars->steps);
	return (1);
}

int	move(int keycode, t_vars *vars)
{
	if (keycode == 13)
		if (w_move(vars))
			vars->map[vars->player_y][vars->player_x] = 'P';
	if (keycode == 1)
		if (s_move(vars))
			vars->map[vars->player_y][vars->player_x] = 'P';
	if (keycode == 2)
		if (d_move(vars))
			vars->map[vars->player_y][vars->player_x] = 'P';
	if (keycode == 0)
		if (a_move(vars))
			vars->map[vars->player_y][vars->player_x] = 'P';
	if (keycode == 53)
	{
		ft_free(vars);
		printf("End game\n");
		exit (1);
	}
	open_map(vars->map, vars);
	return (0);
}
