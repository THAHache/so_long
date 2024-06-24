/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <jperez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:39:28 by jperez-r          #+#    #+#             */
/*   Updated: 2024/06/24 15:55:13 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * Revisa que toda la fila esté compuesta de muros.
 * Evalua la primera y la última fila
 */
int	check_wall(char *row)
{
	int	i;

	i = 0;
	while (row[i])
	{
		if (row[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

/**
 * Se compara el caracter que haya en la posición indicada con
 * los caracteres válidos (01CEP) y se va contando cuántos hay
 */
int	check_object(t_map *map, t_player *jp, int i, int j)
{
	if (!ft_strchr("01CEP", map->plan[i][j]))
		return (1);
	if (map->plan[i][j] == 'C')
		map->c++;
	if (map->plan[i][j] == 'E')
		map->e++;
	if (map->plan[i][j] == 'P')
	{
		jp->ycurrent = i;
		jp->xcurrent = j;
		map->p++;
	}
	return (0);
}

/**
 * Función que separa el mapa por líneas en una matriz para evaluar si:
 * el mapa es cuadrado y está rodeado de muros
 * los caracteres que se encuentran dentro son válidos (01CEP)
 */
int	check_map(char *s, t_map *map, t_player *jp)
{
	int	i;
	int	j;

	map->plan = ft_split(s, '\n');
	map->col = col_map(map->plan);
	if (map->col < 2 || check_wall(map->plan[0]) == 1
		|| check_wall(map->plan[map->row - 1]) == 1)
		return (ft_free_double(map->plan));
	i = 1;
	while (map->plan[i + 1])
	{
		if (map->plan[i][0] != '1' || map->plan[i][map->col - 1] != '1')
			return (ft_free_double(map->plan));
		j = 1;
		while (map->plan[i][j] && j < map->col - 1)
		{
			if (check_object(map, jp, i, j))
				return (ft_free_double(map->plan));
			j++;
		}
		i++;
	}
	if (map->e != 1 || map->p != 1 || map->c < 1)
		return (ft_free_double(map->plan));
	return (0);
}
