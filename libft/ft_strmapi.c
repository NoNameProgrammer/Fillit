/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiles <egiles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:19:13 by egiles            #+#    #+#             */
/*   Updated: 2019/09/19 18:28:04 by egiles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	size_t			i;
	unsigned int	count;

	if (s && f && (res = ft_strnew(ft_strlen(s))))
	{
		count = 0;
		i = 0;
		while (*s)
			res[i++] = f(count++, *s++);
		return (res);
	}
	return (NULL);
}
