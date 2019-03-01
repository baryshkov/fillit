/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 02:08:09 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/02/05 15:38:58 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				ft_find_min_x(int *s)
{
	int			i;
	int			min;

	i = 0;
	min = s[i];
	while (i < 8)
	{
		if (min > s[i])
			min = s[i];
		i += 2;
	}
	return (min);
}

int				ft_find_min_y(int *s)
{
	int			i;
	int			min;

	i = 1;
	min = s[i];
	while (i < 8)
	{
		if (min > s[i])
			min = s[i];
		i += 2;
	}
	return (min);
}

int				*ft_get_right_coordinates(int *s)
{
	int			mx;
	int			my;
	int			i;

	i = 0;
	mx = ft_find_min_x(s);
	my = ft_find_min_y(s);
	while (i < 8)
	{
		s[i] = s[i] - mx;
		s[i + 1] = s[i + 1] - my;
		i += 2;
	}
	return (s);
}

int				ft_height(int *s)
{
	int			i;
	int			max;
	int			min;

	i = 1;
	max = 0;
	min = ft_find_min_y(s);
	while (i < 8)
	{
		if (max < s[i])
			max = s[i];
		i += 2;
	}
	return (max - min + 1);
}

int				ft_width(int *s)
{
	int			i;
	int			max;
	int			min;

	i = 0;
	max = 0;
	min = ft_find_min_x(s);
	while (i < 8)
	{
		if (max < s[i])
			max = s[i];
		i += 2;
	}
	return (max - min + 1);
}
