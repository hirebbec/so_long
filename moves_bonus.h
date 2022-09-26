/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 02:37:56 by hirebbec          #+#    #+#             */
/*   Updated: 2021/12/28 18:08:09 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVES_BONUS_H
# define MOVES_BONUS_H
# include "get_next_line.h"

int		c_chek(t_vars *vars);
int		move(int keycode, t_vars *vars);
int		get_current_position(char **map, t_vars *vars);
void	ft_free(t_vars *vars);
char	**get_map(int fd, t_vars	*vars);
void	get_vars(t_vars *vars, int fd);
int		get_current_position(char **map, t_vars *vars);
int		map_cheak(t_vars *vars);
int		player_cheak(t_vars *vars);
int		wall_cheak(t_vars *vars);
void	map_error(t_vars *vars);
int		open_map_loop(t_vars	*vars);
void	*exit_pic(t_vars	*vars);
char	*ft_itoa(int n);
char	*ft_strjoin2(char *s1, char *s2);
int		exit_map(t_vars *vars);
void	map_error2(t_vars *vars);
#endif