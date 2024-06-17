/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <jperez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:03:42 by jperez-r          #+#    #+#             */
/*   Updated: 2024/06/17 19:18:44 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * Esta función va a recorrer el mapa rellenando cada posición posible por una P
 */

int	recursi(char **plan, int y, int x)
{
	//printf("Estoy en [%d,%d]: %c\n", y, x, plan[y][x]);
	//printf("%s\n", ft_strchr("0CE", plan[y][x - 1]));
//SUBIR
	if(ft_strchr("0CE", plan[y - 1][x]))
	{
		//printf("Quiero ver qué hay en [%d,%d]: %c\n", y-1, x, plan[y-1][x]);
		plan[y - 1][x] = 'P';
		recursi(plan, y - 1, x);
	}
//DERECHA
	if(ft_strchr("0CE", plan[y][x + 1]))
	{
		//printf("Quiero ver qué hay en [%d,%d]: %c\n", y, x+1, plan[y][x + 1]);
		plan[y][x + 1] = 'P';
		recursi(plan, y, x + 1);
	}
//BAJAR
	if(ft_strchr("0CE", plan[y + 1][x]))
	{
		//printf("Quiero ver qué hay en [%d,%d]: %c\n", y+1, x, plan[y+1][x]);
		plan[y + 1][x] = 'P';
		recursi(plan, y + 1, x);
	}
//IZQUIERDA
	if(ft_strchr("0CE", plan[y][x - 1]))
	{
		//printf("Quiero ver qué hay en [%d,%d]: %c\n", y, x-1, plan[y][x - 1]);
		plan[y][x - 1] = 'P';
		recursi(plan, y, x - 1);
	}
	
	return (0);
}

int	check_path(char *s, t_player *pj)
{
	char **path;
	int	i;
	int	j;

	path = ft_split(s, '\n');
	recursi(path, pj->ycurrent, pj->xcurrent);

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
