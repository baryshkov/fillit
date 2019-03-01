/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:07:22 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/02/07 15:24:10 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list			*ft_create_head(t_list **lst)
{
	t_list		*new;

	new = *lst;
	MC((new = ft_lstnew("666", 0)));
	return (new);
}

void			ft_get_coords2(int i, int j, int c, int *cd)
{
	cd[c] = j;
	cd[c + 1] = i;
}

int				*ft_get_coords_start(char **arr)
{
	int			i;
	int			j;
	int			*coords;
	int			c;

	i = 0;
	j = 0;
	c = 0;
	coords = (int *)malloc(8 * sizeof(int));
	while (i < 4)
	{
		j = 0;
		while (arr[i][j] != '\0')
		{
			if (arr[i][j] == '#')
			{
				ft_get_coords2(i, j, c, coords);
				c += 2;
			}
			j++;
		}
		i++;
	}
	return (coords);
}

void			ft_megastart(char **arr, t_list **head)
{
	int			i;
	int			j;
	t_list		*temp;

	temp = *head;
	i = 0;
	j = 0;
	while (arr[i] != '\0')
	{
		if (!ft_strlen(arr[i]))
			break ;
		ft_pushback(ft_get_coords_start(&arr[i]), j, &temp);
		i += 4;
		j++;
	}
}

t_list			*ft_pushback(int *s, int j, t_list **head)
{
	t_t			newt;

	newt.c = 'A' + j;
	newt.coord = ft_get_right_coordinates(s);
	newt.width = ft_width(newt.coord);
	newt.height = ft_height(newt.coord);
	ft_lstaddtoend(head, ft_lstnew((void *)&newt, sizeof(t_t)));
	return (*head);
}
