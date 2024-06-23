/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <jperez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:48:35 by jperez-r          #+#    #+#             */
/*   Updated: 2024/06/23 21:47:00 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * Inicializar los límites del mapa y el eje central
*/
int	select_limit(t_vars *vars)
{
	vars->xlimit = vars->map.col * 32;
	vars->ylimit = vars->map.row * 32;
	return (0);
}

/**
 * Cierra la ventana y finaliza el programa cuando se pulsa el ESC
 * Se libera todo lo posible aunque se haga exit
*/
int	closewin(t_vars *vars)
{
	ft_free_double(vars->map.plan);
	mlx_loop_end(vars->mlx);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	exit(0);
	return (0);
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
	select_limit(vars);
	vars->win = mlx_new_window(vars->mlx, vars->xlimit,
			vars->ylimit + 16, "so_long");
	draw_map(*vars);
	movement(vars);
	mlx_hook(vars->win, 17, 0L, (void *)exit, NULL);
	mlx_hook(vars->win, 2, 1L << 0, move, vars);
	mlx_loop(vars->mlx);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	return (0);
}

/**
 * Función principal que gestiona la parte interna (chequeo de mapa)
 * y la parte externa (gestión de apartado visual)
 */
int	so_long(char *s)
{
	int		fd;
	t_vars	vars;

	fd = open (s, O_RDONLY);
	if (fd == -1)
		return (error_so_long(6, s));
	initialize_vars(&vars);
	if (read_map(fd, &vars.map, &vars.pj))
	{
		close(fd);
		return (1);
	}
	close(fd);
	openwin(&vars);
	ft_free_double(vars.map.plan);
	return (0);
}

int	main(int argc, char *argv[])
{
	char	*file;

	if (argc == 1)
		return (0);
	if (argc != 2)
		return (error_so_long(1, NULL));
	file = ft_strrchr(argv[1], '/');
	if (!file)
		file = argv[1];
	else
		file++;
	if (!ft_strnrstr(file, ".ber", 5))
		return (error_so_long(0, NULL));
	if (so_long(argv[1]))
		return (1);
	return (0);
}
