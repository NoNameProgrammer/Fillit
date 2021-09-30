/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiles <egiles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:30:03 by egiles            #+#    #+#             */
/*   Updated: 2019/09/22 16:38:20 by egiles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t len;

	i = -1;
	j = 0;
	len = ft_strlen((char*)src);
	while (dst[++i] != '\0' && i < size)
		len++;
	if (size == 0)
		return (len);
	while (src[j] != '\0' && i < (size - 1))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (src[j] == '\0' || i == (size - 1))
		dst[i] = '\0';
	return (len);
}
