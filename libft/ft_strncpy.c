/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wconnell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 14:17:36 by wconnell          #+#    #+#             */
/*   Updated: 2018/12/05 03:23:04 by wconnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	while (len--)
	{
		if (src[i] == '\0')
		{
			while (len-- && dst)
			{
				dst[i++] = '\0';
			}
			dst[i] = '\0';
			return (dst);
		}
		dst[i] = src[i];
		i++;
	}
	return (dst);
}
