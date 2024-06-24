/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <jperez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 18:06:48 by jperez-r          #+#    #+#             */
/*   Updated: 2024/06/24 15:52:43 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * Comprobar que no haya líneas vacías antes de aplicar el split
 */
int	check_nl(char *s)
{
	int	i;

	i = 1;
	if (s[0] == '\n')
		return (1);
	while (s[i])
	{
		if (s[i] == '\n' && (s[i - 1] == '\n' || s[i + 1] == '\0'))
			return (1);
		i++;
	}
	return (0);
}

/**
 * Se contará el número de líneas que tiene el mapa
 * y se obviarán las líneas vacías
*/
int	row_map(char *s, t_map *map)
{
	int	i;
	int	rm;

	i = 0;
	rm = 1;
	while (s[i])
	{
		if (i != 0 && s[i] == '\n' && s[i - 1] != '\n')
			rm++;
		i++;
	}
	if (s[i - 1] == '\n')
		rm--;
	map->row = rm;
	return (rm);
}

/**
 * Se contará el número de columnas de cada fila y se compararán entre sí
 * para comprobar que es cuadrado. Mejorable sustituyendo los while internos
 * por ft_strlen
*/
int	col_map(char **s)
{
	int	i;
	int	j;
	int	cm;

	i = 0;
	while (s[0][i])
		i++;
	cm = i;
	i = 1;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
			j++;
		if (cm != j)
			return (1);
		i++;
	}
	return (cm);
}
