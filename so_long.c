/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <jperez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:48:35 by jperez-r          #+#    #+#             */
/*   Updated: 2024/06/10 22:21:46 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * Inicializar los límites del mapa y el eje central
*/
int	select_limit(t_vars *vars)
{
	//vars->x = pj->xcurrent;
	//vars->y = pj->ycurrent;
	vars->xlimit = vars->map.row*32;
	vars->ylimit = vars->map.col*32;
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
	printf("%d\n", vars.map.row);
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
		printf("%s\n", vars.map.plan[i]);
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
	mlx_string_put(vars->mlx, vars->win, 1, vars->ylimit + 12, WHITE, "Movimientos:");
	mov = ft_itoa(vars->moves);
	//mlx_string_put(vars->mlx, vars->win, (y/2)+30, vars->ylimit + 13, WHITE, mov);
	mlx_string_put(vars->mlx, vars->win, 73, vars->ylimit + 13, WHITE, mov);
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
	if(vars->map.plan[vars->pj.xcurrent + x][vars->pj.ycurrent + y] == '1')
		return (0);
	vars->pj.xlast = vars->pj.xcurrent;
	vars->pj.ylast = vars->pj.ycurrent;
	if (x != 0)
		vars->pj.xcurrent += x;
	else
		vars->pj.ycurrent += y;
	if(vars->map.plan[vars->pj.xcurrent][vars->pj.ycurrent] == 'C')
	{
		vars->pj.c++;
		vars->map.plan[vars->pj.xcurrent][vars->pj.ycurrent] = '0';
	}
	if(vars->map.plan[vars->pj.xlast][vars->pj.ylast] == 'E')
		draw_close(*vars);
	else
		draw_floor(*vars);
	
	if(vars->map.plan[vars->pj.xcurrent][vars->pj.ycurrent] == 'E')
	{
		if(vars->pj.c == vars->map.c)
			draw_open(*vars); // aquí hay que hacer que finalice el juego. quizá una bandera de win y a correr
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
	if ((keycode == W || keycode == Z || keycode == UP) && vars->pj.ycurrent > 0)
		//vars->y--;
		increase_move(vars, 0, -1);
	else if ((keycode == A || keycode == Q || keycode == LEFT) && vars->pj.xcurrent > 0)
		//vars->x--;
		increase_move(vars, -1, 0);
	else if ((keycode == S || keycode == DOWN) && vars->pj.ycurrent < vars->map.col - 1)
		//vars->y++;
		increase_move(vars, 0, 1);
	else if ((keycode == D || keycode == RIGHT) && vars->pj.xcurrent < vars->map.row - 1)
		//vars->x++;
		increase_move(vars, 1, 0);
	//mlx_pixel_put(vars->mlx, vars->win, vars->x, vars->y, 0x00FFFFFF);
	else if (keycode == ESC)
		closewin(vars);
	return (0);
}

/**
 * Creación y control de las ventanas y la estructura
*/
int	openwin(t_vars	*vars)
{
	//t_vars	vars;
	/*void	*pj;
	void	*exit_map;
	int	width;
	int	height;*/

	//initialize_vars(&vars);
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (1);
	/**
	 * De momento, la x mínima para poder hacer bien el marcador tiene que ser
	 * de unos 110 pixeles para poder tener hasta 99999 movimientos
	 * con 5 columnas sólo me da para pintar 3 sprites y me descuadra los movimientos
	 * Posible solución: alinear los movimientos a la izquierda del marcador en lugar de centrarlo
	*/
	select_limit(vars);

	//vars->win = mlx_new_window(vars->mlx, vars->ylimit, vars->xlimit + 16, "so_long");
	vars->win = mlx_new_window(vars->mlx, vars->xlimit, vars->ylimit + 16, "so_long");

	//paint_back(vars, 0x00FF55555);
	draw_map(*vars);

	/*pj = mlx_xpm_file_to_image(vars.mlx, "./sprites/pj.xpm", &width, &height);
	exit_map = mlx_xpm_file_to_image(vars.mlx, "./sprites/close.xpm", &width, &height);
	mlx_put_image_to_window(vars.mlx, vars.win, exit_map, 20, 20);
	mlx_put_image_to_window(vars.mlx, vars.win, pj, 10, 10);*/
	mlx_pixel_put(vars->mlx, vars->win, vars->x, vars->y, 0x00FFFFFF);

	movement(vars);
	//El evento 17 representa cerrar la ventana con el aspa roja
	mlx_hook(vars->win, 17, 0L, (void *)exit, NULL);
	mlx_hook(vars->win, 2, 1L<<0, move, vars);
	//mlx_hook(vars.win, 2, 1L<<0, closewin, &vars);

	mlx_loop(vars->mlx);

	/*mlx_destroy_image(vars.mlx, pj);*/
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx); //NO INCUIDA EN OpenGL? usar para evitar los leaks
	free(vars->mlx);
	return (0);
}

int	so_long(char *s)
{
	int		fd;
	t_vars	vars;
	//t_map		map;
	//t_player	pj;
	
	if (can_read(s) < 0)
		return(1);
	fd = open (s, O_RDONLY);
	initialize_vars(&vars);
	//initialize_map(&map);
	//initialize_player(&pj);
	if (check_map(fd, &vars.map, &vars.pj))
	{
		close(fd);
		return (1);
	}
	openwin(&vars);
	ft_free_double(vars.map.plan);
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
