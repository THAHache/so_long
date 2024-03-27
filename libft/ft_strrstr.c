/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:54:19 by jperez-r          #+#    #+#             */
/*   Updated: 2024/03/27 18:55:02 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	char	*s1;
	char	*s2;

	i = ft_strlen(haystack);
	j = ft_strlen(needle);
	s1 = (char *)haystack;
	if (!s1 || i < j)
		return (NULL);
	if (!*needle)
		return (s1);
	s2 = (char *)needle;
	i -= j;
	/*while (s1[i] && i > 0)
	{
		j = 0;
		while (s1[i + j] == s2[j])
		{

			j--;
		}
		i--;
	}

		j = 0;
		while (s1[i + j] == s2[j] && i + j < len)
		{
			if (s2[j + 1] == '\0')
				return (&s1[i]);
			j++;
		}
		i++;
	}*/
	return (NULL);
}
