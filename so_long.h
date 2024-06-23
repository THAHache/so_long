/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <jperez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:30:59 by jperez-r          #+#    #+#             */
/*   Updated: 2024/06/23 22:06:15 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include <ctype.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <errno.h>
# include "./libft/libft.h"
# include "./libft/gnl/get_next_line.h"
# include "./mlx_linux/mlx.h"

# define W 119 //13
# define A 97 //0
# define S 115 //1
# define D 100 //2
# define Z 122 //6
# define Q 113 //12
# define UP 65362 //62
# define LEFT 65361 //59
# define DOWN 65364 //61
# define RIGHT 65363 //60
# define ESC 65307 //53

# define WHITE 0x00FFFFFF
# define BLACK 0x00000000
# define RED 0x00FF0000
# define GREEN 0x00FFFFFF
# define BLUE 0x0000FF00

typedef struct	s_map {
	char	**plan;
	int	row;
	int	col;
	int	p;
	int	e;
	int	c;
}				t_map;


/**
 * Estructura para guardar los sprites
 */
typedef struct	s_sprite {
	void	*img;
	char	*route;
}				t_sprite;

typedef struct	s_sprlst {
	t_sprite	wall;
	t_sprite	floor;
	t_sprite	pj;
	t_sprite	exi;
	t_sprite	coll;
	int	width;
	int	height;
}				t_sprlst;

typedef	struct s_player {
	int	xlast;
	int	xcurrent;
	int	ylast;
	int	ycurrent;
	int	c;
}				t_player;

typedef struct	s_vars {
	void		*mlx;
	void		*win;
	int		x;
	int		xlimit;
	int		y;
	int		ylimit;
	int		moves;
	t_map		map;
	t_player	pj;
}				t_vars;

int	closewin(t_vars *vars);

void		initialize_vars(t_vars *vars);
void		initialize_map(t_map *map);
void		initialize_player(t_player *pla);
void		initialize_img(t_sprite *floor, char *path);
void		initialize_plan(t_sprlst *lst);

int	check_nl(char *s);
int	row_map(char *s, t_map *map);
int	col_map(char **s);


int	draw_map(t_vars vars);
int	draw_floor(t_vars vars);
int	draw_close(t_vars vars);
int	draw_pj(t_vars vars);
int	draw_open(t_vars vars);
int	draw_pje(t_vars vars);

int	movement(t_vars *vars);
int	increase_move(t_vars *vars, int x, int y);
int	move(int keycode, t_vars *vars);

void	destroy_images(t_vars vars, t_sprlst *lst);

int		error_so_long(int er, char *s);
int		can_read(char *s);
int		read_map(int fd, t_map *map, t_player *pj);
int	check_path(char *s, t_player *jp);
int		so_long(char *s);
int		main(int argc, char *argv[]);

#endif
