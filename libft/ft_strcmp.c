/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wconnell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:58:14 by wconnell          #+#    #+#             */
/*   Updated: 2018/12/05 05:17:23 by wconnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;
	int f;

	i = 0;
	f = 1;
	while (s1[i] != '\0' && f == 1)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			f--;
		else
			i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
