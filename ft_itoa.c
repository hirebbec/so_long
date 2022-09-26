/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirebbec <hirebbec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:19:02 by hirebbec          #+#    #+#             */
/*   Updated: 2021/12/28 17:31:39 by hirebbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include "moves_bonus.h"

char	*ft_strdup(char *s1)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(ft_strlen(s1) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_len(int c)
{
	int	i;

	i = 0;
	if (c <= 0)
	{
		i++;
		c = c * (-1);
	}
	while (c > 0)
	{
		i++;
		c = c / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = ft_len(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = (char *)malloc(i + 1);
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n = n * (-1);
	}
	str[i--] = '\0';
	while (n != 0)
	{
		str[i] = (n % 10) + '0';
		i--;
		n = n / 10;
	}
	return ((char *)str);
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

int	exit_map(t_vars *vars)
{
	ft_free(vars);
	printf("end\n");
	exit (1);
	return (0);
}
