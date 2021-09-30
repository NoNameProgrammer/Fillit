/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiles <egiles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 19:48:03 by egiles            #+#    #+#             */
/*   Updated: 2019/09/18 20:07:36 by egiles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *ptr;

	ptr = 0;
	if ((char)c == 0)
		return ((char*)s + ft_strlen(s));
	while (*s)
	{
		if (*s == (char)c)
			ptr = (char*)s;
		s++;
	}
	if (ptr)
		return (ptr);
	return (NULL);
}
