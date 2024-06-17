/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <jperez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:47:25 by jperez-r          #+#    #+#             */
/*   Updated: 2024/06/12 19:50:01 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * pinta el mapa que lee con los sprites
 */
int	draw_map(t_vars vars)
{
	int		i;
	int		j;
	t_sprite	wall;
	t_sprite	floor;
	t_sprite	pj;
	t_sprite	exi;
	t_sprite	coll;

	initialize_plan(&floor, &wall, &pj, &exi, &coll);
	wall.img = mlx_xpm_file_to_image(vars.mlx, wall.route, &wall.width, &wall.height);
	floor.img = mlx_xpm_file_to_image(vars.mlx, floor.route, &floor.width, &floor.height);
	pj.img = mlx_xpm_file_to_image(vars.mlx, pj.route, &pj.width, &pj.height);
	exi.img = mlx_xpm_file_to_image(vars.mlx, exi.route, &exi.width, &exi.height);
	coll.img = mlx_xpm_file_to_image(vars.mlx, coll.route, &coll.width, &coll.height);
	i = 0;
	//printf("%d\n", vars.map.row);
	//j = 0;
	while (i < vars.map.row)
	{
		j = 0;
		while (j < vars.map.col)
		{
			if(vars.map.plan[i][j] == '1')
				mlx_put_image_to_window(vars.mlx, vars.win, wall.img, j*32, i*32);
			else if ((vars.map.plan[i][j] == 'P'))
				mlx_put_image_to_window(vars.mlx, vars.win, pj.img, j*32, i*32);
			else if ((vars.map.plan[i][j] == 'E'))
				mlx_put_image_to_window(vars.mlx, vars.win, exi.img, j*32, i*32);
			else if ((vars.map.plan[i][j] == 'C'))
				mlx_put_image_to_window(vars.mlx, vars.win, coll.img, j*32, i*32);
			else
				mlx_put_image_to_window(vars.mlx, vars.win, floor.img, j*32, i*32);
			j++;
		}
		//printf("%s\n", vars.map.plan[i]);
		i++;
	}
	destroy_images(vars, &floor, &wall, &pj, &exi, &coll);
	return (0);
}

/**
 * pinta el suelo por el que se ha pasado
 */
int	draw_floor(t_vars vars)
{
	int		x;
	int		y;
	t_sprite	floor;

	initialize_img(&floor, "./sprites/grass.xpm");
	floor.img = mlx_xpm_file_to_image(vars.mlx, floor.route, &floor.width, &floor.height);
	x = vars.pj.xlast;
	y = vars.pj.ylast;
	mlx_put_image_to_window(vars.mlx, vars.win, floor.img, x*32, y*32);
	mlx_destroy_image(vars.mlx, floor.img);
	return (0);
}

/**
 * pinta la salida si se pasa por ella y está cerrada
 */
int	draw_close(t_vars vars)
{
	int		x;
	int		y;
	t_sprite	close;

	initialize_img(&close, "./sprites/close.xpm");
	close.img = mlx_xpm_file_to_image(vars.mlx, close.route, &close.width, &close.height);
	x = vars.pj.xlast;
	y = vars.pj.ylast;
	mlx_put_image_to_window(vars.mlx, vars.win, close.img, x*32, y*32);
	mlx_destroy_image(vars.mlx, close.img);
	return (0);
}
/**
 * pinta el suelo por el que se ha pasado
 */
int	draw_pj(t_vars vars)
{
	int		x;
	int		y;
	t_sprite	pj;

	initialize_img(&pj, "./sprites/pj.xpm");
	pj.img = mlx_xpm_file_to_image(vars.mlx, pj.route, &pj.width, &pj.height);
	x = vars.pj.xcurrent;
	y = vars.pj.ycurrent;
	mlx_put_image_to_window(vars.mlx, vars.win, pj.img, x*32, y*32);
	mlx_destroy_image(vars.mlx, pj.img);
	return (0);
}
/**
 * pinta la salida abierta
 */
int	draw_open(t_vars vars)
{
	int		x;
	int		y;
	t_sprite	open;

	initialize_img(&open, "./sprites/open.xpm");
	open.img = mlx_xpm_file_to_image(vars.mlx, open.route, &open.width, &open.height);
	x = vars.pj.xcurrent;
	y = vars.pj.ycurrent;
	mlx_put_image_to_window(vars.mlx, vars.win, open.img, x*32, y*32);
	mlx_destroy_image(vars.mlx, open.img);
	return (0);
}
/**
 * pinta el personaje sobre la salida cerrada
 */
int	draw_pje(t_vars vars)
{
	int		x;
	int		y;
	t_sprite	pj;

	initialize_img(&pj, "./sprites/pj2.xpm");
	pj.img = mlx_xpm_file_to_image(vars.mlx, pj.route, &pj.width, &pj.height);
	x = vars.pj.xcurrent;
	y = vars.pj.ycurrent;
	mlx_put_image_to_window(vars.mlx, vars.win, pj.img, x*32, y*32);
	mlx_destroy_image(vars.mlx, pj.img);
	return (0);
}