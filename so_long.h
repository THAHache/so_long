/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:30:59 by jperez-r          #+#    #+#             */
/*   Updated: 2024/04/26 18:39:09 by jperez-r         ###   ########.fr       */
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
# include "mlx.h"

# define W 13//119
# define A 0//97
# define S 1//115
# define D 2//100
# define Z 6
# define Q 12
# define UP 62
# define LEFT 59
# define DOWN 61
# define RIGHT 60
# define ESC 53 //65307

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

int		error_so_long(int er, char *s);
int		can_read(char *s);
int		so_long(char *s);
int		main(int argc, char *argv[]);

#endif
