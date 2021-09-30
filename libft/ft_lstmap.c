/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiles <egiles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 15:03:23 by egiles            #+#    #+#             */
/*   Updated: 2019/09/24 16:52:36 by egiles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_cln_struct(t_list *lst)
{
	while (lst)
	{
		free(lst);
		lst = lst->next;
	}
	lst = NULL;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*tmp;

	if (!(new = f(lst)))
		return (NULL);
	tmp = new;
	if (!lst || !f)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		if (!(tmp->next = f(lst)))
		{
			ft_cln_struct(new);
			return (NULL);
		}
		tmp = tmp->next;
	}
	return (new);
}
