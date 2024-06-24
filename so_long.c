/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <jperez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:48:35 by jperez-r          #+#    #+#             */
/*   Updated: 2024/06/24 15:01:44 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
