/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wconnell <wconnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 01:43:27 by wconnell          #+#    #+#             */
/*   Updated: 2019/02/13 14:14:43 by wconnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				ft_findmaxi(char **arr)
{
	int i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	i--;
	return (i);
}

int				ft_findmaxj(char **arr)
{
	int j;

	j = 0;
	while (arr[0][j] != '\0')
		j++;
	j--;
	return (j);
}

int				ft_canweplace(int x, int y, t_list *list, char **arr)
{
	int		i;
	int		kx;
	int		ky;
	int		*p;

	i = 0;
	kx = 0;
	ky = 1;
	p = TETR(list);
	while (i < 4)
	{
		if (p[ky] + y > ft_findmaxi(arr) || p[kx] + x > ft_findmaxj(arr))
			return (0);
		if (arr[p[ky] + y][p[kx] + x] != '.')
			return (0);
		ky += 2;
		kx += 2;
		i++;
	}
	place(x, y, list, arr);
	return (1);
}

int				ft_solvemap(t_list *list, char **arr, int size)
{
	int			x;
	int			y;

	y = 0;
	if (list == NULL)
		return (1);
	while (y < size - HEIGHT(list) + 1)
	{
		x = 0;
		while (x < size - WID(list) + 1)
		{
			if (ft_canweplace(x, y, list, arr))
			{
				if (ft_solvemap(list->next, arr, size))
					return (1);
				else
					placedot(x, y, list, arr);
			}
			x++;
		}
		y++;
	}
	return (0);
}

char			**ft_solver(t_list *list, char **arr, int size)
{
	while (!(ft_solvemap(list, arr, size)))
	{
		ft_free_arr(arr);
		size++;
		arr = ft_create_map(size);
	}
	return (arr);
}
