/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <jperez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:39:28 by jperez-r          #+#    #+#             */
/*   Updated: 2024/05/23 15:10:16 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_map(t_map *map)
{
	map->p = 0;
	map->e = 0;
	map->c = 0;
	map->xfirst = 0;
	map->xcurrent = 0;
	map->yfirst = 0;
	map->ycurrent = 0;
}

int	read_map(char *buff)
{
	char **map;
	int	i;
	//int	j;

	map = ft_split(buff, '\n');
	printf("%s\n", map[0]);
	i = 1;
	/**
	 * Necesito saber cuantas ¿filas? tiene map
	 * para comprobar que la primera y la última son todo 1
	*/
	while (map[i])
	{
		//j = 0;
		printf("%s\n", map[i]);
		i++;
	}
	
		//printf("hola\n");
	ft_free_double(map);
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
 * 111	11111
 * 1p1	1pce1
 * 1c1	11111
 * 1e1
 * 111
 * 
*/
int	check_map(int fd)
{
	t_map	map;
	int	datamap;
	char	*buff;
	char	*aux[1];
	
	buff = malloc(sizeof(char) * 1000);
	if(!buff)
		return (1);
	initialize_map(&map);
	if (!*aux)
		aux[0] = ft_strdup("");
	datamap = 1;
	while (datamap > 0)
	{
		datamap = read(fd, buff, 18);
		buff[datamap] = '\0';
		if (datamap > 0)
			aux[0] = ft_strjoin(aux[0], buff);
	}
	//printf("%s\n", aux[0]);
	free(buff);
	if (datamap == -1)
	{
		free(aux[0]);
		return (1);
	}
	if (read_map(aux[0]))
	{
		free(aux[0]);
		return (1);
	}
	free(aux[0]);
	return (0);
}
