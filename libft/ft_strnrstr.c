/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnrstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:08:36 by jperez-r          #+#    #+#             */
/*   Updated: 2024/03/27 19:34:14 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnrstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*s1;
	char	*s2;

	i = ft_strlen(haystack);
	j = ft_strlen(needle);
	s1 = (char *)haystack;
	if ((!s1 && len == 0) || i < j || i < len || len < j)
		return (NULL);
	if (!*needle)
		return (s1);
	s2 = (char *)needle;
	//i -= j;
	printf("el tamaño de i es: %zu, el de j: %zu y la len: %zu\n", i, j, len);
	i--;
	len = i - len + j;
	j--;
	printf("el tamaño de i es: %zu, el de j: %zu y la len: %zu\n", i, j, len);
	//añadir --i al while para rebajar las líneas
	while (i >= len)
	{
		k = 0;
		while (s1[i - j] && s1[i - k] == s2[j - k] && k <= j)
		{
			printf("s1: %c, s2: %c y la k: %zu\n lo que deviera de devolver sería: %c\n", s1[i - k], s2[j - k], k, s1[i - j]);
			if (j == k)
				return (&s1[i - j]);
			k++;
		}
		i--;
	}
	return (NULL);
}
