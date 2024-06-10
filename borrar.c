#include "so_long.h"


/**
 * Creación y control de las ventanas y la estructura
*/
int	elder_openwin()
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

int	read_map(char *s, t_map *map, t_player pla)
{
	char	**plan;
	int	i;
	int	j;


/**
 * borrar el siguiente if
 */
	if (pla.xcurrent)
		return(1);
	

	plan = ft_split(s, '\n');
	map.col = col_map(plan);
	//printf("col: %d\n", map.col);
	if(check_wall(plan[0]) == 1 || check_wall(plan[map.row - 1]) == 1 || map.col < 2)
	{
		ft_free_double(plan);
		return (1);
	}
	//printf("%s\n", plan[0]);
	i = 1;
	while (plan[i + 1])
	{
		if (plan[i][0] != '1' || plan[i][strlen(plan[i]) - 1] != '1')
		{
			ft_free_double(plan);
			return (1);
		}
		j = 1;
		while (plan[i][j] && j < map.col - 1)
		{
			if(!ft_strchr("01CEP", plan[i][j]) || map.e > 1 || map.p > 1)
			{
				//printf("%c\n", plan[i][j]);
				ft_free_double(plan);
				return (1);
			}
			if(plan[i][j] == 'C')
				map.c++;
			if(plan[i][j] == 'E')
				map.e++;
			if(plan[i][j] == 'P')
			{
				pla.xfirst = i;
				pla.yfirst = j;
				map.p++;
			}
			j++;
		}
			//printf("%s\n", plan[i]);
		i++;
	}
	//printf("%s\n", plan[i]);
	//printf("i= %d\nplan= %lu\n", i, sizeof(plan[i][3]));
	ft_free_double(plan);
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
int	openwin(t_map map, t_player *pj)
{
	//t_vars	vars;
	/*void	*pj;
	void	*exit_map;
	int	width;
	int	height;*/

	//initialize_vars(&vars);
	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (1);
	/**
	 * De momento, la x mínima para poder hacer bien el marcador tiene que ser
	 * de unos 110 pixeles para poder tener hasta 99999 movimientos
	 * con 5 columnas sólo me da para pintar 3 sprites y me descuadra los movimientos
	 * Posible solución: alinear los movimientos a la izquierda del marcador en lugar de centrarlo
	*/
	select_limit(&vars, pj, map.row*32, map.col*32);
	vars.win = mlx_new_window(vars.mlx, vars.xlimit, vars.ylimit + 16, "so_long");

	paint_back(&vars, 0x00FF55555);
	draw_map(vars, map);

	/*pj = mlx_xpm_file_to_image(vars.mlx, "./sprites/pj.xpm", &width, &height);
	exit_map = mlx_xpm_file_to_image(vars.mlx, "./sprites/close.xpm", &width, &height);
	mlx_put_image_to_window(vars.mlx, vars.win, exit_map, 20, 20);
	mlx_put_image_to_window(vars.mlx, vars.win, pj, 10, 10);*/
	mlx_pixel_put(vars.mlx, vars.win, vars.x, vars.y, 0x00FFFFFF);

	movement(&vars);
	//El evento 17 representa cerrar la ventana con el aspa roja
	mlx_hook(vars.win, 17, 0L, (void *)exit, NULL);
	mlx_hook(vars.win, 2, 1L<<0, move, &vars);
	//mlx_hook(vars.win, 2, 1L<<0, closewin, &vars);

	mlx_loop(vars.mlx);

	/*mlx_destroy_image(vars.mlx, pj);*/
	mlx_destroy_window(vars.mlx, vars.win);
	mlx_destroy_display(vars.mlx); //NO INCUIDA EN OpenGL? usar para evitar los leaks
	free(vars.mlx);
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