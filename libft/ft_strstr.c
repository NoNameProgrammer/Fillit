/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiles <egiles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:12:26 by egiles            #+#    #+#             */
/*   Updated: 2019/09/22 15:07:34 by egiles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int len;

	if (haystack == '\0' && needle == '\0')
		return ("");
	if (needle[0] == '\0')
		return ((char*)haystack);
	if (!(*haystack) && !(*needle))
		return (NULL);
	len = ft_strlen(needle);
	i = -1;
	while (haystack[++i] != '\0')
		if (ft_strncmp((haystack + i), needle, len) == 0)
			return ((char*)(haystack + i));
	return (0);
}
