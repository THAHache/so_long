/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <jperez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:03:33 by jperez-r          #+#    #+#             */
/*   Updated: 2024/06/24 15:55:48 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * Guarda la dirección de las imágenes en su correspondiente variable
 * para dibujarlas
 */
void	select_images(t_vars vars, t_sprlst *lst)
{
	lst->wall.img = mlx_xpm_file_to_image(vars.mlx, lst->wall.route,
			&lst->width, &lst->height);
	lst->floor.img = mlx_xpm_file_to_image(vars.mlx, lst->floor.route,
			&lst->width, &lst->height);
	lst->pj.img = mlx_xpm_file_to_image(vars.mlx, lst->pj.route,
			&lst->width, &lst->height);
	lst->exi.img = mlx_xpm_file_to_image(vars.mlx, lst->exi.route,
			&lst->width, &lst->height);
	lst->coll.img = mlx_xpm_file_to_image(vars.mlx, lst->coll.route,
			&lst->width, &lst->height);
}

/**
 * Las imágenes que han sido creadas para dibujar, ahora serán destruidas
 */
void	destroy_images(t_vars vars, t_sprlst *lst)
{
	mlx_destroy_image(vars.mlx, lst->floor.img);
	mlx_destroy_image(vars.mlx, lst->wall.img);
	mlx_destroy_image(vars.mlx, lst->pj.img);
	mlx_destroy_image(vars.mlx, lst->exi.img);
	mlx_destroy_image(vars.mlx, lst->coll.img);
}

/**
 * Selecciona qué imagen se va a implementar dependiendo de qué caracter tenga
 * el mapa
 */

void	put_image(t_vars vars, t_sprlst lst, int i, int j)
{
	if (vars.map.plan[i][j] == '1')
		mlx_put_image_to_window(vars.mlx, vars.win, lst.wall.img, j * 32,
			i * 32);
	else if ((vars.map.plan[i][j] == 'P'))
		mlx_put_image_to_window(vars.mlx, vars.win, lst.pj.img, j * 32, i * 32);
	else if ((vars.map.plan[i][j] == 'E'))
		mlx_put_image_to_window(vars.mlx, vars.win, lst.exi.img, j * 32,
			i * 32);
	else if ((vars.map.plan[i][j] == 'C'))
		mlx_put_image_to_window(vars.mlx, vars.win, lst.coll.img, j * 32,
			i * 32);
	else
		mlx_put_image_to_window(vars.mlx, vars.win, lst.floor.img, j * 32,
			i * 32);
}

/**
 * pinta el mapa que lee con los sprites
 */
int	draw_map(t_vars vars)
{
	t_sprlst	lst;
	int			i;
	int			j;

	initialize_plan(&lst);
	select_images(vars, &lst);
	i = 0;
	while (i < vars.map.row)
	{
		j = 0;
		while (j < vars.map.col)
		{
			put_image(vars, lst, i, j);
			j++;
		}
		i++;
	}
	destroy_images(vars, &lst);
	return (0);
}
