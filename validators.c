/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wconnell <wconnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 21:01:40 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/02/13 14:15:00 by wconnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_check_symbols(char **line)
{
	int			i;
	int			f;
	int			l;

	l = 0;
	i = 0;
	f = 0;
	while ((*line)[i] != '\0')
	{
		while (l <= 15)
		{
			if ((*line)[i] != '#' && (*line)[i] != '.')
				ft_bust("error");
			if ((*line)[i] == '#')
				f++;
			i++;
			l++;
		}
		if (f == 4)
			f = 0;
		else
			ft_bust("error");
		l = 0;
	}
}

int				get_link(int i, int j, char **arr)
{
	int f;

	f = 0;
	if (i != 3)
		f += (arr[i + 1][j] == '#') ? 1 : 0;
	if (i > 0)
		f += (arr[i - 1][j] == '#') ? 1 : 0;
	f += (arr[i][j + 1] == '#') ? 1 : 0;
	if (j > 0)
		f += (arr[i][j - 1] == '#') ? 1 : 0;
	return (f);
}

int				ft_check_tetro(char **arr)
{
	int			i;
	int			j;
	int			c;

	i = 0;
	j = 0;
	c = 0;
	while (i < 4)
	{
		j = 0;
		while (arr[i][j] != '\0')
		{
			if (arr[i][j] == '#')
			{
				c += get_link(i, j, arr);
			}
			j++;
		}
		i++;
	}
	return (c);
}

int				ft_check_connections(char **arr)
{
	int			i;
	int			l;
	int			t;

	i = 0;
	l = 0;
	t = 0;
	while (arr[i] != '\0')
	{
		if (!ft_strlen(arr[i]))
			break ;
		l = ft_check_tetro(&arr[i]);
		if (l != 6 && l != 8)
			ft_bust("error");
		i += 4;
		t++;
	}
	if (!(t >= 1 && t <= 25))
	{
		ft_free_arr(arr);
		ft_bust("error");
	}
	return (t);
}
