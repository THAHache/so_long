/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <jperez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:39:28 by jperez-r          #+#    #+#             */
/*   Updated: 2024/05/27 21:21:56 by jperez-r         ###   ########.fr       */
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
/**
 * Probablemente no use esta función, pero ahí queda
*/
int	n_row_map(char **map)
{
	int	rm;

	rm = 0;
	while (map[rm])
		rm++;
	return (rm);
}

int	check_wall(char *row)
{
	int	i;

	i = 0;
	/**
	 * Aquí hay un problema con el split, parece.
	 * La primera posición dice que es Acknowledge (reconocimiento)
	 * Cuando debería ser el primer caracter que hay en el .ber
	*/
	if (!ft_isprint(row[i]))
		i++;
	while (row[i])
	{
		if(row[i] != '1')
			return (1);
		i++;
	}
	return (0);
	
}

int	read_map(char *buff)
{
	char **map;
	int	i;
	//int	row;
	//int	j;

	map = ft_split(buff, '\n');
	//row = n_row_map(map);
	if(check_wall(map[0]) != 1)
		printf("%s\n", map[0]);
	//printf("%d\n", row);
	i = 1;
	/**
	 * Necesito saber cuantas ¿filas? tiene map
	 * para comprobar que la primera y la última son todo 1
	*/
	while (map[i + 1])
	{
		//j = 0;
		printf("%s\n", map[i]);
		i++;
	}
	printf("%s\n", map[i]);
	//printf("i= %d\nmap= %lu\n", i, sizeof(map[i][3]));
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
