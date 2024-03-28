/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:37:44 by jperez-r          #+#    #+#             */
/*   Updated: 2024/03/28 14:38:03 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	can_read(char *s)
{
	int		ret;

	ret = 1;
	if (access (s, F_OK) != 0)
		ret = error_so_long(3, s);
	else if (access (s, R_OK) != 0)
		ret = error_so_long(4, s);
	return (ret);
}
