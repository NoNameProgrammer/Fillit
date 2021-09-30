/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiles <egiles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 15:54:55 by egiles            #+#    #+#             */
/*   Updated: 2019/09/21 16:50:28 by egiles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *ptr_dst;
	unsigned char *ptr_src;

	if (dst == NULL && src == NULL)
		return (NULL);
	ptr_dst = (unsigned char*)dst;
	ptr_src = (unsigned char*)src;
	while (n)
	{
		n--;
		*ptr_dst = *ptr_src;
		ptr_dst++;
		ptr_src++;
	}
	return (dst);
}
