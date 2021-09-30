/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiles <egiles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 18:10:39 by egiles            #+#    #+#             */
/*   Updated: 2019/09/19 14:54:03 by egiles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	void *ptr;

	ptr = ft_memchr(src, c, n);
	if (ptr == NULL)
	{
		ft_memcpy(dst, src, n);
		return (NULL);
	}
	ft_memcpy(dst, src, ptr - src + 1);
	return (dst + (ptr - src + 1));
}
