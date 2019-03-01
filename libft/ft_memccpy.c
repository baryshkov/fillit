/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wconnell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 01:50:29 by wconnell          #+#    #+#             */
/*   Updated: 2018/12/05 06:49:25 by wconnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*s;
	char	*d;

	s = (char*)src;
	d = dst;
	i = 0;
	while (n--)
	{
		d[i] = s[i];
		if ((unsigned char)s[i] == (unsigned char)c)
			return (d + i + 1);
		i++;
	}
	return (NULL);
}
