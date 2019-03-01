/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wconnell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:04:04 by wconnell          #+#    #+#             */
/*   Updated: 2018/12/06 22:45:31 by wconnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		f;

	i = 0;
	f = 1;
	if (n == 0)
		return (0);
	n = n - 1;
	while (s1[i] != '\0' && f == 1 && i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			f--;
		else
			i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
