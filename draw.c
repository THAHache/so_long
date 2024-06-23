/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <jperez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:47:25 by jperez-r          #+#    #+#             */
/*   Updated: 2024/06/23 22:08:47 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * pinta el mapa que lee con los sprites
 */
int	draw_map(t_vars vars)
{
	t_sprlst	lst;
	int			i;
	int			j;

	initialize_plan(&lst);
	lst.wall.img = mlx_xpm_file_to_image(vars.mlx, lst.wall.route,
			&lst.width, &lst.height);
	lst.floor.img = mlx_xpm_file_to_image(vars.mlx, lst.floor.route,
			&lst.width, &lst.height);
	lst.pj.img = mlx_xpm_file_to_image(vars.mlx, lst.pj.route,
			&lst.width, &lst.height);
	lst.exi.img = mlx_xpm_file_to_image(vars.mlx, lst.exi.route,
			&lst.width, &lst.height);
	lst.coll.img = mlx_xpm_file_to_image(vars.mlx, lst.coll.route,
			&lst.width, &lst.height);
	i = 0;
	while (i < vars.map.row)
	{
		j = 0;
		while (j < vars.map.col)
		{
			if (vars.map.plan[i][j] == '1')
				mlx_put_image_to_window(vars.mlx, vars.win, lst.wall.img, j * 32, i * 32);
			else if ((vars.map.plan[i][j] == 'P'))
				mlx_put_image_to_window(vars.mlx, vars.win, lst.pj.img, j * 32, i * 32);
			else if ((vars.map.plan[i][j] == 'E'))
				mlx_put_image_to_window(vars.mlx, vars.win, lst.exi.img, j * 32, i * 32);
			else if ((vars.map.plan[i][j] == 'C'))
				mlx_put_image_to_window(vars.mlx, vars.win, lst.coll.img, j * 32, i * 32);
			else
				mlx_put_image_to_window(vars.mlx, vars.win, lst.floor.img, j * 32, i * 32);
			j++;
		}
		i++;
	}
	destroy_images(vars, &lst);
	return (0);
}

/**
 * pinta el suelo por el que se ha pasado
 */
int	draw_floor(t_vars vars)
{
	t_sprite	floor;
	int			x;
	int			y;

	initialize_img(&floor, "./sprites/grass.xpm");
	floor.img = mlx_xpm_file_to_image(vars.mlx, floor.route,
			&floor.width, &floor.height);
	x = vars.pj.xlast;
	y = vars.pj.ylast;
	mlx_put_image_to_window(vars.mlx, vars.win, floor.img, x * 32, y * 32);
	mlx_destroy_image(vars.mlx, floor.img);
	return (0);
}

/**
 * pinta la salida si se pasa por ella y está cerrada
 */
int	draw_close(t_vars vars)
{
	t_sprite	close;
	int			x;
	int			y;

	initialize_img(&close, "./sprites/close.xpm");
	close.img = mlx_xpm_file_to_image(vars.mlx, close.route,
			&close.width, &close.height);
	x = vars.pj.xlast;
	y = vars.pj.ylast;
	mlx_put_image_to_window(vars.mlx, vars.win, close.img, x * 32, y * 32);
	mlx_destroy_image(vars.mlx, close.img);
	return (0);
}

/**
 * pinta el suelo por el que se ha pasado
 */
int	draw_pj(t_vars vars)
{
	t_sprite	pj;
	int			x;
	int			y;

	initialize_img(&pj, "./sprites/pj.xpm");
	pj.img = mlx_xpm_file_to_image(vars.mlx, pj.route, &pj.width, &pj.height);
	x = vars.pj.xcurrent;
	y = vars.pj.ycurrent;
	mlx_put_image_to_window(vars.mlx, vars.win, pj.img, x * 32, y * 32);
	mlx_destroy_image(vars.mlx, pj.img);
	return (0);
}

/**
 * pinta la salida abierta
 */
int	draw_open(t_vars vars)
{
	t_sprite	open;
	int			x;
	int			y;

	initialize_img(&open, "./sprites/open.xpm");
	open.img = mlx_xpm_file_to_image(vars.mlx, open.route,
			&open.width, &open.height);
	x = vars.pj.xcurrent;
	y = vars.pj.ycurrent;
	mlx_put_image_to_window(vars.mlx, vars.win, open.img, x * 32, y * 32);
	mlx_destroy_image(vars.mlx, open.img);
	return (0);
}

/**
 * pinta el personaje sobre la salida cerrada
 */
int	draw_pje(t_vars vars)
{
	t_sprite	pj;
	int			x;
	int			y;

	initialize_img(&pj, "./sprites/pj2.xpm");
	pj.img = mlx_xpm_file_to_image(vars.mlx, pj.route, &pj.width, &pj.height);
	x = vars.pj.xcurrent;
	y = vars.pj.ycurrent;
	mlx_put_image_to_window(vars.mlx, vars.win, pj.img, x * 32, y * 32);
	mlx_destroy_image(vars.mlx, pj.img);
	return (0);
}
