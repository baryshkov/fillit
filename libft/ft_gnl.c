/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 17:27:36 by wconnell          #+#    #+#             */
/*   Updated: 2019/02/05 15:19:54 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list		*get_fd(t_list **list, int fd)
{
	t_list			*new;

	new = *list;
	while (new)
	{
		if (new->content_size == (size_t)fd)
			return (new);
		new = new->next;
	}
	if (!(new = ft_lstnew("\0", fd)))
		return (NULL);
	ft_lstadd(list, new);
	new = *list;
	return (new);
}

static int			cut_line(t_list *list, char **line)
{
	char			*newline;
	char			*tmp;

	*line = NULL;
	if ((newline = ft_strchr(list->content, '\n')))
	{
		*newline = '\0';
		*line = ft_strdup(list->content);
		tmp = ft_strdup(newline + 1);
		free(list->content);
		list->content = tmp;
		return (1);
	}
	if (ft_strlen(list->content))
	{
		*line = ft_strdup(list->content);
		free(list->content);
		list->content = "\0";
		return (1);
	}
	return (0);
}

int					ft_gnl(const int fd, char **line)
{
	static t_list	*stl;
	t_list			*tmp;
	int				ret;
	char			buf[BUFF_SIZE + 1];
	char			*cache;

	if ((fd < 0 || line == NULL || read(fd, buf, 0) < 0))
		return (-1);
	tmp = get_fd(&stl, fd);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(cache = ft_strjoin(tmp->content, buf)))
			return (-1);
		free(tmp->content);
		tmp->content = cache;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	return (cut_line(tmp, line));
}
