/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_structs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <jperez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:16:49 by jperez-r          #+#    #+#             */
/*   Updated: 2024/05/29 17:30:12 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * Inicializar las estructuras con valores por defecto
*/
void	initialize_vars(t_vars *vars)
{
	vars->mlx = NULL;
	vars->win = NULL;
	vars->x = 0;
	vars->xlimit = 0;
	vars->y = 0;
	vars->ylimit = 0;
	vars->moves = 0;
}

void	initialize_map(t_map *map)
{
	map->row = 0;
	map->col = 0;
	map->p = 0;
	map->e = 0;
	map->c = 0;
}

void	initialize_player(t_player *pla)
{
	pla->xfirst = 0;
	pla->xcurrent = 0;
	pla->yfirst = 0;
	pla->ycurrent = 0;
	pla->c = 0;
	//pla->last_pos = 0;
}