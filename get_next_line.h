/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 22:23:15 by hirebbec          #+#    #+#             */
/*   Updated: 2021/12/27 18:28:53 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 1
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct open_map
{
	int		hight;
	int		width;
	void	*mlx;
	void	*win;
	char	**map;
	int		player_x;
	int		player_y;
	int		steps;
	int		exit;
	int		player;
}	t_vars;
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
int		ft_strlen(char *s);
char	*ft_strrchr(char *s, int c);
char	*ft_strtrim(char *s1, char *set);
char	*ft_strdup(char *s1);
char	*ft_substr(char *s, int start, int len);
int		open_map(char **map, t_vars	*vars);
void	paste_img(int x, int y, t_vars *vars, char c);
#endif