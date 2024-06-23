/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <jperez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:03:42 by jperez-r          #+#    #+#             */
/*   Updated: 2024/06/23 21:31:11 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * Esta función va a recorrer el mapa rellenando cada posición posible por una P
 */

void	p_refill(char **plan, int y, int x)
{
	if (ft_strchr("0CE", plan[y - 1][x]))
	{
		plan[y - 1][x] = 'P';
		p_refill(plan, y - 1, x);
	}
	if (ft_strchr("0CE", plan[y][x + 1]))
	{
		plan[y][x + 1] = 'P';
		p_refill(plan, y, x + 1);
	}
	if (ft_strchr("0CE", plan[y + 1][x]))
	{
		plan[y + 1][x] = 'P';
		p_refill(plan, y + 1, x);
	}
	if (ft_strchr("0CE", plan[y][x - 1]))
	{
		plan[y][x - 1] = 'P';
		p_refill(plan, y, x - 1);
	}
}

int	check_path(char *s, t_player *pj)
{
	char	**path;
	int		i;
	int		j;

	path = ft_split(s, '\n');
	p_refill(path, pj->ycurrent, pj->xcurrent);
	i = 0;
	while (path [i])
	{
		j = 0;
		while (path[i][j])
		{
			if (ft_strchr("CE", path[i][j]))
			{
				ft_free_double(path);
				return (1);
			}
			j++;
		}
		i++;
	}
	ft_free_double(path);
	return (0);
}
