/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <jperez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:39:28 by jperez-r          #+#    #+#             */
/*   Updated: 2024/06/23 21:30:08 by jperez-r         ###   ########.fr       */
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
int check_object(t_map *map, t_player *jp, int i, int j)
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
		if (map->plan[i][0] != '1' || map->plan[i][map->col - 1]!= '1')
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
	if (map->e !=1 || map->p != 1 || map->c < 1)
		return(ft_free_double(map->plan));
	return (0);
}

int	free_aux(char *aux, int err)
{
	if (aux)
		free(aux);
	if (err > 0)
		error_so_long(err, NULL);
	return (1);
}


int	check_bad_map(char *map_r, t_map *map, t_player *pj)
{
	if (check_nl(map_r))
	{
		free_aux(map_r, 2);
		return (1);
	}
	if (row_map(map_r, map) < 3)
	{
		free_aux(map_r, 2);
		return (1);
	}
	if (check_map(map_r, map, pj))
	{
		free_aux(map_r, 2);
		return (1);
	}
	if (check_path(map_r, pj))
	{
		ft_free_double(map->plan);
		free_aux(map_r, 5);
		return (1);
	}
	return (0);
}

/**
 * Se comprobará si el mapa que entra como argumento es correcto
 * Debe tener un personaje, una salida, coleccionables, estar rodeado
 * de paredes, que la salida sea accesible y que sea rectangular
 * 
 * El malloc se reservará con 1000 por poner un límite temporal
 * El reader leerá 18 bits porque es el tamaño más pequeño
 * con los saltos de línea
 * 11111	111
 * 1PCE1	1P1
 * 11111	1C1
 * 			1E1
 * 			111
 * 
*/
int	read_map(int fd, t_map *map, t_player *pj)
{
	static char	*map_r[4096];
	char		*buff;
	int			datamap;

	buff = malloc(sizeof(char) * 1000);
	if (!buff)
		return (1);
	if (*map_r == NULL)
		map_r[0] = ft_strdup("");
	datamap = 1;
	while (datamap > 0)
	{
		datamap = read(fd, buff, 18);
		buff[datamap] = '\0';
		if (datamap > 0)
			map_r[0] = gnl_strjoin(map_r[0], buff);
	}
	free(buff);
	if (datamap == -1)
		return (free_aux(map_r[0], 6));
	if (check_bad_map(map_r[0], map, pj))
		return (1);
	free(map_r[0]);
	return (0);
}
