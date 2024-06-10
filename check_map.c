/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <jperez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:39:28 by jperez-r          #+#    #+#             */
/*   Updated: 2024/06/10 22:16:18 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * Se contará el número de líneas que tiene el mapa
 * y se obviarán las líneas vacías
*/
int	row_map(char *s)
{
	int	i;
	int	rm;

	i = 0;
	rm = 1;
	while (s[i])
	{
		if(i != 0 && s[i] == '\n' && s[i - 1] != '\n')
			rm++;
		i++;
	}
	if(s[i - 1] == '\n')
		rm--;
	return (rm);
}
/**
 * Se contará el número de columnas de cada fila y se compararán entre sí
 * para comprobar que es cuadrado
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
		if(cm != j)
			return (1);
		i++;
	}
	return (cm);
}

int	check_wall(char *row)
{
	int	i;

	i = 0;
	while (row[i])
	{
		if(row[i] != '1')
			return (1);
		//printf("%i\n", row[i]);
		i++;
	}
	return (0);
}

int	read_map(char *s, t_map *map, t_player *jp)
{
	int	i;
	int	j;

	map->plan = ft_split(s, '\n');
	map->col = col_map(map->plan);
	//printf("col: %d", map->col);
	if(check_wall(map->plan[0]) == 1 || check_wall(map->plan[map->row - 1]) == 1 || map->col < 2)
	{
		ft_free_double(map->plan);
		return (1);
	}
	i = 1;
	while (map->plan[i + 1])
	{
		if (map->plan[i][0] != '1' || map->plan[i][strlen(map->plan[i]) - 1] != '1')
		{
			ft_free_double(map->plan);
			return (1);
		}
		j = 1;
		while (map->plan[i][j] && j < map->col - 1)
		{
			if(!ft_strchr("01CEP", map->plan[i][j]) || map->e > 1 || map->p > 1)
			{
				ft_free_double(map->plan);
				return (1);
			}
			if(map->plan[i][j] == 'C')
				map->c++;
			if(map->plan[i][j] == 'E')
				map->e++;
			if(map->plan[i][j] == 'P')
			{
				jp->xcurrent = i;
				jp->ycurrent = j;
				map->p++;
			}
			j++;
		}
			//printf("%s\n", map->plan[i]);
		i++;
	}
	//printf("aqui\n");
	//ft_free_double(map->plan);
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
 * 		1E1
 * 		111
 * 
*/
int	check_map(int fd, t_map *map, t_player *pj)
{
	//t_player	pj;
	int		datamap;
	char		*buff;
	static char		*aux[4096];
	

	buff = malloc(sizeof(char) * 1000);
	if(!buff)
		return (1);
	//initialize_player(pj);
	if (*aux == NULL)
		aux[0] = ft_strdup("");
	datamap = 1;
	//printf("%i\n", aux[0][0]);
	while (datamap > 0)
	{
		datamap = read(fd, buff, 18);
		buff[datamap] = '\0';
		//printf("%i\n", buff[0]);
		if (datamap > 0)
			aux[0] = ft_strjoin(aux[0], buff);
	}
	free(buff);
	map->row = row_map(aux[0]);
	if(map->row < 3)
	{
		error_so_long(2, NULL);
		free(aux[0]);
		return (1);
	}
	if (datamap == -1)
	{
		free(aux[0]);
		return (1);
	}
	if (read_map(aux[0], map, pj))
	{
		error_so_long(2, NULL);
		free(aux[0]);
		return (1);
	}
	free(aux[0]);
	return (0);
}
