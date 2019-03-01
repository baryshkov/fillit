/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wconnell <wconnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 22:32:07 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/02/13 15:34:55 by wconnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_get_map_size(int tet)
{
	int		size;

	size = 2;
	while (size * size < tet * 4)
		size++;
	return (size);
}

char		**ft_create_map(int size)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	map = NULL;
	MC((map = (char**)malloc(sizeof(char*) * size + 1)));
	while (i < size)
		map[i++] = (char*)malloc(sizeof(char) * size + 1);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
			map[i][j++] = '.';
		map[i++][j] = '\0';
	}
	map[i] = NULL;
	return (map);
}

void		ft_free_arr(char **arr)
{
	int		i;
	int		j;

	if (!arr)
		return ;
	i = 0;
	j = 0;
	while (arr[i] != 0)
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr[i]);
	free(*arr);
	arr = NULL;
}

void		ft_free_list(t_list *head)
{
	int		*p;
	t_t		*list;

	list = head->content;
	p = NULL;
	while (head)
	{
		p = TETR(head);
		free(p);
		p = NULL;
		free(head->content);
		free(head);
		head = head->next;
	}
	free(head);
}
