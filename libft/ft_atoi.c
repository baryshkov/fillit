/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wconnell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:45:42 by wconnell          #+#    #+#             */
/*   Updated: 2018/12/08 18:15:16 by wconnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(const char *s, int i, int sign)
{
	unsigned long long n;

	n = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		n *= 10;
		n += s[i] - '0';
		if (n > 9223372036854775807)
		{
			if (sign == -1)
				return (0);
			return (-1);
		}
		i++;
	}
	return (n * sign);
}

int			ft_atoi(const char *s)
{
	int i;
	int sign;

	sign = 1;
	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\v' || s[i] == '\f' ||
			s[i] == '\r' || s[i] == '\n')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	return (check(s, i, sign));
}
