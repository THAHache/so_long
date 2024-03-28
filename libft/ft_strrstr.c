/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:54:19 by jperez-r          #+#    #+#             */
/*   Updated: 2024/03/28 12:19:31 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	int		k;
	char	*s1;
	char	*s2;

	i = ft_strlen(haystack);
	j = ft_strlen(needle) - 1;
	s1 = (char *)haystack;
	if (!s1 || i < j + 1)
		return (NULL);
	if (!*needle)
		return (s1);
	s2 = (char *)needle;
	while (--i >= 0)
	{
		k = 0;
		while (s1[i - j] && s1[i - k] == s2[j - k] && k <= j)
		{
			if (j == k)
				return (&s1[i - j]);
			k++;
		}
	}
	return (NULL);
}
