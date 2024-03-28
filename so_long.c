/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:48:35 by jperez-r          #+#    #+#             */
/*   Updated: 2024/03/28 14:39:47 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	so_long(char *s)
{
	int	fd;

	if (!can_read(s))
		return (0);
	fd = open (s, O_RDONLY);
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
