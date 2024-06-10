/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_structs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <jperez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:16:49 by jperez-r          #+#    #+#             */
/*   Updated: 2024/06/10 21:16:06 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * Inicializar las estructuras con valores por defecto
*/

void	initialize_map(t_map *map)
{
	map->plan = NULL;
	map->row = 0;
	map->col = 0;
	map->p = 0;
	map->e = 0;
	map->c = 0;
}

void	initialize_player(t_player *pla)
{
	pla->xlast = 0;
	pla->xcurrent = 0;
	pla->ylast = 0;
	pla->ycurrent = 0;
	pla->c = 0;
	//pla->last_pos = 0;
}
void	initialize_img(t_sprite *floor, char *path)
{
	floor->img = NULL;
	floor->route = path;
	//floor->width = 0;
	//floor->height = 0;
}
void	initialize_plan(t_sprite *floor, t_sprite *wall, t_sprite *pj, t_sprite *exi, t_sprite *coll)
{
	floor->img = NULL;
	floor->route = "./sprites/grass.xpm";
	//floor->width = 0;
	//floor->height = 0;
	wall->img = NULL;
	wall->route = "./sprites/brick.xpm";
	//wall->width = 0;
	//wall->height = 0;
	pj->img = NULL;
	pj->route = "./sprites/pj.xpm";
	//pj->width = 0;
	//pj->height = 0;
	exi->img = NULL;
	exi->route = "./sprites/close.xpm";
	//exi->width = 0;
	//exi->height = 0;
	coll->img = NULL;
	coll->route = "./sprites/key.xpm";
	//coll->width = 0;
	//coll->height = 0;
}
void	initialize_vars(t_vars *vars)
{
	vars->mlx = NULL;
	vars->win = NULL;
	vars->x = 0;
	vars->xlimit = 0;
	vars->y = 0;
	vars->ylimit = 0;
	vars->moves = 0;
	initialize_map(&vars->map);
	initialize_player(&vars->pj);
}

void	destroy_images(t_vars vars, t_sprite *floor, t_sprite *wall, t_sprite *pj, t_sprite *exi, t_sprite *coll)
{
	mlx_destroy_image(vars.mlx, floor->img);
	mlx_destroy_image(vars.mlx, wall->img);
	mlx_destroy_image(vars.mlx, pj->img);
	mlx_destroy_image(vars.mlx, exi->img);
	mlx_destroy_image(vars.mlx, coll->img);
}

