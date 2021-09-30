/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiles <egiles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 17:58:02 by egiles            #+#    #+#             */
/*   Updated: 2019/09/22 18:06:28 by egiles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;

	if (alst && *alst && del)
	{
		while ((*alst))
		{
			tmp = *alst;
			ft_lstdelone(alst, del);
			(*alst) = tmp->next;
		}
		*alst = NULL;
	}
}
