/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 19:04:04 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/02/07 14:46:10 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_bust(char *str)
{
	ft_putendl(str);
	exit(-1);
}

void			ft_checkformod16(char *s, int f)
{
	if (ft_strlen(s) % 16)
		ft_bust("error");
	if (f == 1)
		ft_bust("error");
}

void			ft_checkforvalidlength(char *s, int i)
{
	if (ft_strlen(s) > 4)
		ft_bust("error");
	if (!(i % 5))
	{
		if (ft_strlen(s))
			ft_bust("error");
	}
}

char			**ft_create_arr(char **line)
{
	int			i;
	int			j;
	int			g;
	char		**arr;
	int			c;

	i = 0;
	j = 0;
	c = 0;
	g = ft_strlen((*line)) / 4 + 1;
	MC((arr = (char**)malloc(g * sizeof(char*))));
	while (i < g - 1)
		arr[i++] = (char*)malloc(sizeof(char) * 5);
	i = 0;
	while (i < g - 1)
	{
		j = 0;
		while (j < 4)
			arr[i][j++] = (*line)[c++];
		arr[i++][j] = '\0';
	}
	arr[i] = NULL;
	return (arr);
}

char			*ft_convert_to_line(const int fd)
{
	char		*line;
	char		*str;
	char		*tmp;
	int			f;
	int			i;

	f = 1;
	i = 1;
	MC((tmp = ft_strnew(1)));
	ft_bzero(tmp, 1);
	while ((ft_gnl(fd, &line) == 1))
	{
		if (f && !ft_strlen(line))
			ft_bust("error");
		ft_checkforvalidlength(line, i++);
		str = ft_strjoin(tmp, line);
		f = (!ft_strlen(line) ? 1 : 0);
		free(tmp);
		free(line);
		tmp = str;
	}
	ft_checkformod16(tmp, f);
	ft_check_symbols(&tmp);
	return (tmp);
}
