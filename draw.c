/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <jperez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:47:25 by jperez-r          #+#    #+#             */
/*   Updated: 2024/06/24 14:38:55 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * pinta el suelo por el que se ha pasado
 */
void	draw_floor(t_vars vars)
{
	t_sprite	floor;
	int			x;
	int			y;
	int			width;
	int			height;

	initialize_img(&floor, "./sprites/grass.xpm");
	floor.img = mlx_xpm_file_to_image(vars.mlx, floor.route, &width, &height);
	x = vars.pj.xlast;
	y = vars.pj.ylast;
	mlx_put_image_to_window(vars.mlx, vars.win, floor.img, x * 32, y * 32);
	mlx_destroy_image(vars.mlx, floor.img);
}

/**
 * pinta la salida si se pasa por ella y está cerrada
 */
void	draw_close(t_vars vars)
{
	t_sprite	close;
	int			x;
	int			y;
	int			width;
	int			height;

	initialize_img(&close, "./sprites/close.xpm");
	close.img = mlx_xpm_file_to_image(vars.mlx, close.route, &width, &height);
	x = vars.pj.xlast;
	y = vars.pj.ylast;
	mlx_put_image_to_window(vars.mlx, vars.win, close.img, x * 32, y * 32);
	mlx_destroy_image(vars.mlx, close.img);
}

/**
 * pinta el suelo por el que se ha pasado
 */
void	draw_pj(t_vars vars)
{
	t_sprite	pj;
	int			x;
	int			y;
	int			width;
	int			height;

	initialize_img(&pj, "./sprites/pj.xpm");
	pj.img = mlx_xpm_file_to_image(vars.mlx, pj.route, &width, &height);
	x = vars.pj.xcurrent;
	y = vars.pj.ycurrent;
	mlx_put_image_to_window(vars.mlx, vars.win, pj.img, x * 32, y * 32);
	mlx_destroy_image(vars.mlx, pj.img);
}

/**
 * pinta la salida abierta
 */
void	draw_open(t_vars vars)
{
	t_sprite	open;
	int			x;
	int			y;
	int			width;
	int			height;

	initialize_img(&open, "./sprites/open.xpm");
	open.img = mlx_xpm_file_to_image(vars.mlx, open.route, &width, &height);
	x = vars.pj.xcurrent;
	y = vars.pj.ycurrent;
	mlx_put_image_to_window(vars.mlx, vars.win, open.img, x * 32, y * 32);
	mlx_destroy_image(vars.mlx, open.img);
}

/**
 * pinta el personaje sobre la salida cerrada
 */
void	draw_pje(t_vars vars)
{
	t_sprite	pj;
	int			x;
	int			y;
	int			width;
	int			height;

	initialize_img(&pj, "./sprites/pj2.xpm");
	pj.img = mlx_xpm_file_to_image(vars.mlx, pj.route, &width, &height);
	x = vars.pj.xcurrent;
	y = vars.pj.ycurrent;
	mlx_put_image_to_window(vars.mlx, vars.win, pj.img, x * 32, y * 32);
	mlx_destroy_image(vars.mlx, pj.img);
}
