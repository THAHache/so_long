/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:48:35 by jperez-r          #+#    #+#             */
/*   Updated: 2024/04/23 19:44:33 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	closewin(int keycode, t_vars *vars)
{
	//printf("%d", keycode);
	if (keycode == ESC)
		mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	openwin()
{
	t_vars	vars;

	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (1);
	vars.win = mlx_new_window(vars.mlx, 640, 360, "so_long");
	mlx_pixel_put(vars.mlx, vars.win, 300, 160, 0x00FFFFFF);
	mlx_pixel_put(vars.mlx, vars.win, 300, 200, 0x00FFFFFF);
	mlx_pixel_put(vars.mlx, vars.win, 340, 160, 0x00FFFFFF);
	mlx_pixel_put(vars.mlx, vars.win, 340, 200, 0x00FFFFFF);

	mlx_hook(vars.win, 2, 1L<<0, closewin, &vars);


	mlx_loop(vars.mlx);

	//mlx_destroy_window(vars.mlx, vars.win);
	//mlx_destroy_display(vars.mlx); NO INCUIDA EN OpenGL? usar para evitar los leaks
	free(vars.mlx);
	return (0);
}

int	so_long(char *s)
{
	int	fd;

	if (!can_read(s))
		return (0);
	fd = open (s, O_RDONLY);
	openwin();
	close(fd);
	return (1);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
		return (0);
	if (argc != 2)
		return (error_so_long(1, NULL));
	if (!ft_strnrstr(argv[1], ".ber", 5))
		return (error_so_long(0, NULL));
	if (!so_long(argv[1]))
		return (0);
	return (1);
}
