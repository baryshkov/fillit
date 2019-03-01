/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wconnell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 19:55:52 by wconnell          #+#    #+#             */
/*   Updated: 2018/12/08 20:09:03 by wconnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iws(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	else
		return (0);
}

static int	ft_skip(const char *s)
{
	int i;
	int f;

	i = 0;
	f = 0;
	while (ft_iws(s[i]))
	{
		i++;
		f++;
	}
	if (s[i] != '\0')
	{
		i = ft_strlen(s) - 1;
		while (ft_iws(s[i]))
		{
			i--;
			f++;
		}
	}
	return (f);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		f;
	int		j;
	size_t	k;
	char	*new;

	j = 0;
	i = 0;
	f = ft_skip(s);
	k = ft_strlen(s) - (size_t)f;
	if (!s)
		return ((char*)s);
	else if ((new = (char*)malloc(k + 1 * sizeof(char))))
	{
		while (ft_iws(s[i]))
			i++;
		while (k--)
		{
			new[j++] = s[i++];
		}
		new[j] = '\0';
		return (new);
	}
	else
		return (NULL);
}
