/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wconnell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:52:31 by wconnell          #+#    #+#             */
/*   Updated: 2018/12/05 06:00:30 by wconnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (s1[i] == '\0' && s2[j] == '\0')
		return ((char *)s1);
	if (s2[0] == '\0')
		return ((char *)s1);
	if (!ft_strlen(s2))
		return ((char *)s1);
	while (s1[i] != '\0' && i < (int)len)
	{
		j = 0;
		while (i + j < (int)len && s1[i + j] == s2[j] && s2[j] != '\0')
		{
			if (s2[j + 1] == '\0')
				return ((char *)s1 + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
