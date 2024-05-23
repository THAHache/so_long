/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <jperez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:30:59 by jperez-r          #+#    #+#             */
/*   Updated: 2024/05/23 14:17:50 by jperez-r         ###   ########.fr       */
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

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	int	x;
	int	xlimit;
	int	y;
	int	ylimit;
	int	moves;
}				t_vars;
typedef struct	s_map {
	int	p;
	int	e;
	int	c;
	int	xfirst;
	int	xcurrent;
	int	yfirst;
	int	ycurrent;
}				t_map;

int		error_so_long(int er, char *s);
int		can_read(char *s);
int		check_map(int fd);
int		so_long(char *s);
int		main(int argc, char *argv[]);

#endif
