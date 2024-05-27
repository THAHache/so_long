/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <jperez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:48:35 by jperez-r          #+#    #+#             */
/*   Updated: 2024/05/27 18:38:03 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * Inicializar la estructura con valores por defecto
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

/**
 * Inicializar los límites del mapa y el eje central
*/
int	select_limit(t_vars *vars, double limx, double limy)
{
	vars->x = (int) limx / 2;
	vars->xlimit = limx;
	vars->y = (int) limy / 2;
	vars->ylimit = limy;
	return (0);
}

/**
 * Cierra la ventana y finaliza el programa cuando se pulsa el ESC
*/
int	closewin(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

// Función que dibuja 4 puntos blancos en el mapa
int	draw_square(t_vars *vars)
{
	mlx_pixel_put(vars->mlx, vars->win, 300, 160, 0x00FFFFFF);
	mlx_pixel_put(vars->mlx, vars->win, 300, 200, 0x00FFFFFF);
	mlx_pixel_put(vars->mlx, vars->win, 340, 160, 0x00FFFFFF);
	mlx_pixel_put(vars->mlx, vars->win, 340, 200, 0x00FFFFFF);
	return (0);
}

/**
 * Pinta el fondo de color
*/
int	paint_back(t_vars *vars, int color)
{
	int	x;
	int	y;

	x = 0;
	while (x <= vars->xlimit)
	{
		y = 0;
		while (y <= vars->xlimit)
		{
			mlx_pixel_put(vars->mlx, vars->win, x, y, color);
			y++;
		}
		x++;
	}
	return (0);
}

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
		while (y <= vars->xlimit)
		{
			mlx_pixel_put(vars->mlx, vars->win, x, y, BLACK);
			y++;
		}
		x++;
	}
	mlx_string_put(vars->mlx, vars->win, (y/2)-50, vars->ylimit + 12, WHITE, "Movimientos: ");
	mov = ft_itoa(vars->moves);
	mlx_string_put(vars->mlx, vars->win, (y/2)+30, vars->ylimit + 13, WHITE, mov);
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
	vars->x += x;
	vars->y += y;
	vars->moves++;
	return (0);
}

/**
 * Control de las teclas de movimiento y salida con el ESC
*/

int	move(int keycode, t_vars *vars)
{
	mlx_pixel_put(vars->mlx, vars->win, vars->x, vars->y, 0x00000000);
	if ((keycode == W || keycode == Z || keycode == UP) && vars->y > 0)
		//vars->y--;
		increase_move(vars, 0, -1);
	else if ((keycode == A || keycode == Q || keycode == LEFT) && vars->x > 0)
		//vars->x--;
		increase_move(vars, -1, 0);
	else if ((keycode == S || keycode == DOWN) && vars->y < vars->ylimit - 1)
		//vars->y++;
		increase_move(vars, 0, 1);
	else if ((keycode == D || keycode == RIGHT) && vars->x < vars->xlimit - 1)
		//vars->x++;
		increase_move(vars, 1, 0);
	mlx_pixel_put(vars->mlx, vars->win, vars->x, vars->y, 0x00FFFFFF);
	movement(vars);
	if (keycode == ESC)
		closewin(vars);
	return (0);
}

/**
 * Creación y control de las ventanas y la estructura
*/
int	openwin()
{
	t_vars	vars;

	initialize_vars(&vars);
	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (1);

	/**
	 * De momento, la x mínima para poder hacer bien el marcador tiene que ser
	 * de unos 110 pixeles para poder tener hasta 99999 movimientos
	*/
	select_limit(&vars, 400, 200);
	vars.win = mlx_new_window(vars.mlx, vars.xlimit, vars.ylimit + 16, "so_long");

	paint_back(&vars, 0x00FF55555);
	mlx_pixel_put(vars.mlx, vars.win, vars.x, vars.y, 0x00FFFFFF);

	movement(&vars);
	//El evento 17 representa cerrar la ventana con el aspa roja
	mlx_hook(vars.win, 17, 0L, (void *)exit, NULL);
	mlx_hook(vars.win, 2, 1L<<0, move, &vars);
	//mlx_hook(vars.win, 2, 1L<<0, closewin, &vars);

	mlx_loop(vars.mlx);

	//mlx_destroy_window(vars.mlx, vars.win);
	//mlx_destroy_display(vars.mlx); NO INCUIDA EN OpenGL? usar para evitar los leaks
	free(vars.mlx);
	return (0);
}

int	so_long(char *s)
{
	int	fd;
	
	if (can_read(s) < 0)
		return(1);
	fd = open (s, O_RDONLY);
	if (check_map(fd))
	{
		close(fd);
		return (1);
	}
	//openwin();
	close(fd);
	return (0);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
		return (0);
	if (argc != 2)
		return (error_so_long(1, NULL));
	if (!ft_strnrstr(argv[1], ".ber", 5))
		return (error_so_long(0, NULL));
	if (so_long(argv[1]))
		return (0);
	return (1);
}
