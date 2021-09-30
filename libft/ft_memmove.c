/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiles <egiles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 15:56:52 by egiles            #+#    #+#             */
/*   Updated: 2019/09/21 16:52:37 by egiles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;
	size_t			i;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	ptr_dst = (unsigned char*)dst;
	ptr_src = (unsigned char*)src;
	if (ptr_dst < ptr_src)
		while (i < len)
		{
			*(ptr_dst + i) = *(ptr_src + i);
			i++;
		}
	else
		while (len)
		{
			len--;
			*(ptr_dst + len) = *(ptr_src + len);
		}
	return (dst);
}
