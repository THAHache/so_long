/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <jperez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:48:35 by jperez-r          #+#    #+#             */
/*   Updated: 2024/06/17 19:10:21 by jperez-r         ###   ########.fr       */
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
	vars->xlimit = vars->map.col*32;
	vars->ylimit = vars->map.row*32;
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

	vars->win = mlx_new_window(vars->mlx, vars->xlimit, vars->ylimit + 16, "so_long");

	//paint_back(vars, 0x00FF55555);
	draw_map(*vars);

	/*pj = mlx_xpm_file_to_image(vars.mlx, "./sprites/pj.xpm", &width, &height);
	exit_map = mlx_xpm_file_to_image(vars.mlx, "./sprites/close.xpm", &width, &height);
	mlx_put_image_to_window(vars.mlx, vars.win, exit_map, 20, 20);
	mlx_put_image_to_window(vars.mlx, vars.win, pj, 10, 10);*/
	//mlx_pixel_put(vars->mlx, vars->win, vars->x, vars->y, 0x00FFFFFF);

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
