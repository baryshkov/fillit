/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wconnell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 21:13:43 by wconnell          #+#    #+#             */
/*   Updated: 2018/12/08 17:38:30 by wconnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_length(int c)
{
	size_t i;

	i = 1;
	while (c /= 10)
	{
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char			*new;
	size_t			i;
	unsigned int	nn;

	i = ft_length(n);
	nn = n;
	if (n < 0)
	{
		nn = -n;
		i += 1;
	}
	if (!(new = ft_strnew(i)))
		return (NULL);
	new[--i] = nn % 10 + '0';
	while (nn /= 10)
		new[--i] = nn % 10 + '0';
	if (n < 0)
		new[0] = '-';
	return (new);
}
