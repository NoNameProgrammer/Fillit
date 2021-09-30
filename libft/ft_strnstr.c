/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiles <egiles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:17:51 by egiles            #+#    #+#             */
/*   Updated: 2019/09/24 15:14:05 by egiles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;

	if (haystack[0] == '\0' && needle[0] == '\0')
		return ((char*)haystack);
	if (needle[0] == '\0')
		return ((char*)haystack);
	if ((!(*haystack) && !(*needle)) || len == 0)
		return (NULL);
	i = -1;
	while (haystack[++i] != '\0' && (i + ft_strlen(needle)) <= (len))
	{
		if (ft_strncmp((haystack + i), needle, ft_strlen(needle)) == 0)
		{
			haystack = haystack + i;
			return ((char*)haystack);
		}
	}
	return (0);
}
