/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:48:35 by jperez-r          #+#    #+#             */
/*   Updated: 2024/03/27 19:28:36 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		error_so_long(int er)
{
	if (er == 0)
		ft_puterror("First argument needed is a map with an extension .ber");
	return (-1);
}
/*int	so_long(char **s)
{
	int		fdp[2];
	pid_t	pid;

	if (pipe (fdp) != 0)
		return (error_pipex(1, NULL));
	pid = fork();
	if (pid < 0)
		return (error_pipex(2, NULL));
	if (pid == 0)
	{
		if (!child(s, fdp))
		{
			close(fdp[1]);
			return (0);
		}
	}
	else if (!father(s, fdp))
	{
		close(fdp[0]);
		return (0);
	}
	return (1);
}*/

int	main(int argc, char *argv[])
{
	if (argc == 1)
		return (0);
	//if (argv[1] != ".ber")
		//Hay que comprobar que las nuevas funciones ft_strrstr y ft_strnrstr funcionan bien


	if (!ft_strnrstr(argv[1], ".ber", 4))
		return (error_so_long(0));
	/*if (!so_long(argv))
		return (0);*/
	return (1);
}
