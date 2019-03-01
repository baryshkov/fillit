/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wconnell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:10:36 by wconnell          #+#    #+#             */
/*   Updated: 2018/11/23 18:55:11 by wconnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void *s;

	if ((s = malloc(size)))
	{
		ft_bzero(s, size);
		return (s);
	}
	else
		return (NULL);
}
