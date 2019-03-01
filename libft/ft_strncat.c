/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wconnell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 11:50:47 by wconnell          #+#    #+#             */
/*   Updated: 2018/12/06 20:13:19 by wconnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t len;
	size_t j;

	j = 0;
	len = ft_strlen(s1);
	while (j < n && s2[j])
	{
		s1[len] = s2[j];
		len++;
		j++;
	}
	s1[len] = '\0';
	return (s1);
}
