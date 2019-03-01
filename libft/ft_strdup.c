/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wconnell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 20:18:36 by wconnell          #+#    #+#             */
/*   Updated: 2019/01/12 18:59:07 by wconnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	size_t	i;
	char	*new;
	size_t	k;

	i = 0;
	k = 0;
	while (s1[k] != '\0')
		k++;
	if ((new = (char*)malloc(k + 1 * sizeof(char))))
	{
		while (i < k)
		{
			new[i] = s1[i];
			i++;
		}
		new[i] = '\0';
		return (new);
	}
	else
		return (NULL);
}
