/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_so_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <jperez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:36:44 by jperez-r          #+#    #+#             */
/*   Updated: 2024/06/23 19:08:21 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_so_long(int er, char *s)
{
	char	*msg;

	msg = NULL;
	if (er == 0)
		ft_puterror("First argument needed is a map with an extension .ber");
	else if (er == 1)
		ft_puterror("You need only choose a map");
	else if (er == 2)
		ft_puterror("The map is incorrect");
	else if (er == 3)
		msg = ft_strjoin("No such file or directory: ", s);
	else if (er == 4)
		msg = ft_strjoin("Permission denied: ", s);
	else if (er == 6)
		msg = ft_strjoin("Access denied: ", s);
	else if (er == 5)
		ft_puterror("The path is incorrect");
	else if (er == 6)
		ft_puterror("Read is unavailable");
	if (msg)
	{
		ft_puterror(msg);
		free (msg);
	}
	return (-1);
}
