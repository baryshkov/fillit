/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wconnell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 21:13:45 by wconnell          #+#    #+#             */
/*   Updated: 2018/12/08 17:17:33 by wconnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_free(t_list **start)
{
	t_list	*tmp;

	while ((*start)->next)
	{
		tmp = (*start)->next;
		free(*start);
		*start = tmp;
	}
	*start = NULL;
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*start;

	if ((*f) == NULL || lst == NULL || !(new = ft_lstnew(NULL, 0)))
		return (NULL);
	if (!(new = f(lst)))
		return (NULL);
	start = new;
	while (lst->next)
	{
		lst = lst->next;
		new->next = f(lst);
		if (!(new->next = f(lst)))
		{
			ft_free(&start);
			return (NULL);
		}
		new = new->next;
	}
	new->next = NULL;
	return (start);
}
