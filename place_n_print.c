/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:18:51 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/02/07 16:24:03 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			placedot(int x, int y, t_list *list, char **arr)
{
	int			i;
	int			kx;
	int			ky;
	int			*p;

	i = 0;
	kx = 0;
	ky = 1;
	p = TETR(list);
	while (i < 4)
	{
		arr[p[ky] + y][p[kx] + x] = '.';
		kx += 2;
		ky += 2;
		i++;
	}
}

void			place(int x, int y, t_list *list, char **arr)
{
	int			i;
	int			kx;
	int			ky;
	int			*p;

	i = 0;
	kx = 0;
	ky = 1;
	p = TETR(list);
	while (i < 4)
	{
		arr[p[ky] + y][p[kx] + x] = CHAR(list);
		kx += 2;
		ky += 2;
		i++;
	}
}

void			ft_print_map(char **arr)
{
	int			i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i] != NULL)
	{
		ft_putendl(arr[i]);
		i++;
	}
}
