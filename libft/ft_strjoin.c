/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wconnell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 14:16:47 by wconnell          #+#    #+#             */
/*   Updated: 2018/12/08 17:21:23 by wconnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*new;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if ((new = (char*)malloc(sizeof(char) * len + 1)))
	{
		while (s1[i] != '\0')
		{
			new[i] = s1[i];
			i++;
		}
		while (s2[j] != '\0')
		{
			new[i++] = s2[j++];
		}
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}
