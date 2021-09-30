/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiles <egiles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:41:59 by egiles            #+#    #+#             */
/*   Updated: 2019/09/21 16:59:34 by egiles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*res;
	size_t	i;

	if (s && f && (res = ft_strnew(ft_strlen(s))))
	{
		i = 0;
		while (*s)
			res[i++] = f(*s++);
		return (res);
	}
	return (NULL);
}
