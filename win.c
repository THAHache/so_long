/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <jperez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:00:59 by jperez-r          #+#    #+#             */
/*   Updated: 2024/06/24 15:05:00 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * Cierra la ventana y finaliza el programa cuando se pulsa el ESC
 * Se libera todo lo posible aunque se haga exit
*/
void	closewin(t_vars *vars)
{
	ft_free_double(vars->map.plan);
	mlx_loop_end(vars->mlx);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	exit(0);
}

/**
 * Creación y control de las ventanas y la estructura
 * El evento 17 representa cerrar la ventana con el aspa roja
*/
int	openwin(t_vars	*vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (1);
	vars->xlimit = vars->map.col * 32;
	vars->ylimit = vars->map.row * 32;
	vars->win = mlx_new_window(vars->mlx, vars->xlimit,
			vars->ylimit + 16, "so_long");
	draw_map(*vars);
	movement(vars);
	mlx_hook(vars->win, 17, 0L, (void *)exit, NULL);
	mlx_hook(vars->win, 2, 1L << 0, move, vars);
	mlx_loop(vars->mlx);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	return (0);
}
