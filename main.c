/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wconnell <wconnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 14:33:06 by wconnell          #+#    #+#             */
/*   Updated: 2019/02/13 14:15:44 by wconnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			**solve(char *s)
{
	char		**new;
	int			i;
	char		**map;
	t_list		*head;
	int			g;

	i = 0;
	new = NULL;
	map = NULL;
	head = NULL;
	new = ft_create_arr(&s);
	i = ft_check_connections(new);
	head = ft_create_head(&head);
	ft_megastart(new, &head);
	g = ft_get_map_size(i);
	map = ft_create_map(g);
	map = ft_solver(head->next, map, g);
	ft_free_list(head->next);
	free(head);
	ft_free_arr(new);
	free(new);
	return (map);
}

int				main(int argc, char **argv)
{
	int			fd;
	char		*tmp;
	char		**arr;

	arr = NULL;
	tmp = NULL;
	if (argc != 2)
	{
		ft_putendl("Usage: ./fillit target_file");
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		ft_bust("fd < 0");
	tmp = ft_convert_to_line(fd);
	arr = solve(tmp);
	ft_print_map(arr);
	ft_free_arr(arr);
	free(arr);
	free(tmp);
	return (0);
}
