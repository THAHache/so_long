/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <jperez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:51:02 by jperez-r          #+#    #+#             */
/*   Updated: 2024/06/17 19:37:44 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * Muestra la barra de movimientos y el número de estos
*/
int	movement(t_vars *vars)
{
	int	x;
	int	y;
	char	*mov;

	x = 0;
	while (x <= vars->xlimit)
	{
		y = vars->ylimit;
		while (y <= vars->ylimit + 16)
		{
			mlx_pixel_put(vars->mlx, vars->win, x, y, BLACK);
			y++;
		}
		x++;
	}
	//mlx_string_put(vars->mlx, vars->win, (y/2)-50, vars->ylimit + 12, WHITE, "Movimientos: ");
	mlx_string_put(vars->mlx, vars->win, 1, vars->ylimit + 12, WHITE, "Steps:");
	mov = ft_itoa(vars->moves);
	//mlx_string_put(vars->mlx, vars->win, (y/2)+30, vars->ylimit + 13, WHITE, mov);
	mlx_string_put(vars->mlx, vars->win, 37, vars->ylimit + 13, WHITE, mov);
	if (vars->moves)
	{
		ft_putstr_fd("Steps: ", 1);
		ft_putnbr_fd(vars->moves, 1);
		ft_putchar_fd('\n', 1);
	}
	if (mov)
		free(mov);
	return (0);
}

/**
 * Incrementa el número de movimientos que se han hecho y se mueve.
 * El numero de movimientos máximo será de un int
*/
int	increase_move(t_vars *vars, int x, int y)
{
	if(vars->map.plan[vars->pj.ycurrent + y][vars->pj.xcurrent + x] == '1')
		return (0);
	vars->pj.xlast = vars->pj.xcurrent;
	vars->pj.ylast = vars->pj.ycurrent;
	if (x != 0)
		vars->pj.xcurrent += x;
	else
		vars->pj.ycurrent += y;
	if(vars->map.plan[vars->pj.ycurrent][vars->pj.xcurrent] == 'C')
	{
		vars->pj.c++;
		vars->map.plan[vars->pj.ycurrent][vars->pj.xcurrent] = '0';
	}
	if(vars->map.plan[vars->pj.ylast][vars->pj.xlast] == 'E')
		draw_close(*vars);
	else
		draw_floor(*vars);
	
	if(vars->map.plan[vars->pj.ycurrent][vars->pj.xcurrent] == 'E')
	{
		if(vars->pj.c == vars->map.c)
		{
			draw_open(*vars); // aquí hay que hacer que finalice el juego. quizá una bandera de win y a correr
			vars->map.e = 0;
		}
			else
			draw_pje(*vars);
	}
	else
		draw_pj(*vars);
	//printf("ax:%d, ay: %d\nx: %d, y: %d\n", vars->pj.xlast, vars->pj.ylast, vars->pj.xcurrent, vars->pj.ycurrent);
	//printf("coleccionables: %d\n", vars->pj.c);
	vars->moves++;

	movement(vars);
	return (0);
}

/**
 * Control de las teclas de movimiento y salida con el ESC
*/

int	move(int keycode, t_vars *vars)
{
	//mlx_pixel_put(vars->mlx, vars->win, vars->x, vars->y, 0x00000000);
	if(keycode && vars->map.e == 0)
	{
		mlx_loop_end(vars->mlx);
		return (0);
	}
	if ((keycode == W || keycode == Z || keycode == UP) && vars->pj.xcurrent > 0)
		//vars->y--;
		increase_move(vars, 0, -1);
	else if ((keycode == A || keycode == Q || keycode == LEFT) && vars->pj.ycurrent > 0)
		//vars->x--;
		increase_move(vars, -1, 0);
	else if ((keycode == S || keycode == DOWN) && vars->pj.xcurrent < vars->map.col - 1)
		//vars->y++;
		increase_move(vars, 0, 1);
	else if ((keycode == D || keycode == RIGHT) && vars->pj.ycurrent < vars->map.row - 1)
		//vars->x++;
		increase_move(vars, 1, 0);
	if(vars->map.e == 0)
		ft_putstr_fd("Press any key to exit\n", 1);
	//mlx_pixel_put(vars->mlx, vars->win, vars->x, vars->y, 0x00FFFFFF);
	else if (keycode == ESC)
		closewin(vars);
	return (0);
}
