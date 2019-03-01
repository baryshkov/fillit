/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wconnell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 17:24:52 by wconnell          #+#    #+#             */
/*   Updated: 2018/12/08 18:19:52 by wconnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		wordss(char const *s, char c)
{
	int			i;
	int			sum;

	i = 0;
	sum = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			sum++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (sum + 1);
}

static void		*ft_free(char **a, int j)
{
	while (j)
	{
		free(a[j]);
		j--;
	}
	a = NULL;
	return (NULL);
}

static int		charss(char const *s, int i, char c)
{
	int			sum;

	sum = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		sum++;
	}
	return (sum);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t		chars;
	char		**a;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (s == NULL || !(a = (char **)malloc(sizeof(char *) * (wordss(s, c)))))
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			chars = charss(s, i, c);
			if (!(a[j] = ft_strsub(s, i, chars)))
				return (ft_free(a, j));
			j++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	a[j] = NULL;
	return (a);
}
