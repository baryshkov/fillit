/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wconnell <wconnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 20:15:06 by wconnell          #+#    #+#             */
/*   Updated: 2019/01/12 19:01:36 by wconnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	size_t	len;
	char	*new;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s) + 1;
	if (!(new = (char*)malloc(len * sizeof(char))))
		return (NULL);
	while (s[i] != '\0')
	{
		new[i] = f(s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
