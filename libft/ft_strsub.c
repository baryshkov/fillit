/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wconnell <wconnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 13:56:42 by wconnell          #+#    #+#             */
/*   Updated: 2018/12/15 18:37:14 by wconnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if ((new = (char*)malloc(len + 1 * sizeof(char))))
	{
		while (i < len)
		{
			new[i++] = s[start++];
		}
		new[i] = '\0';
		return (new);
	}
	else
		return (NULL);
}
