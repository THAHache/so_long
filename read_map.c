/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <jperez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:10:51 by jperez-r          #+#    #+#             */
/*   Updated: 2024/06/24 15:18:05 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * 
 */
int	free_read(char *aux, int err)
{
	if (aux)
		free(aux);
	if (err > 0)
		error_so_long(err, NULL);
	return (1);
}

/**
 * Se comprueba los posibles errores que pueda tener un mapa para ser incorrecto
 * Si tiene saltos de línea sueltos, si es cuadrado,
 * los caracteres que lo componen y si se puede resolver
 */
int	check_bad_map(char *map_r, t_map *map, t_player *pj)
{
	if (check_nl(map_r))
	{
		free_read(map_r, 2);
		return (1);
	}
	if (row_map(map_r, map) < 3)
	{
		free_read(map_r, 2);
		return (1);
	}
	if (check_map(map_r, map, pj))
	{
		free_read(map_r, 2);
		return (1);
	}
	if (check_path(map_r, pj))
	{
		ft_free_double(map->plan);
		free_read(map_r, 5);
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
		return (free_read(map_r[0], 6));
	if (check_bad_map(map_r[0], map, pj))
		return (1);
	free(map_r[0]);
	return (0);
}
