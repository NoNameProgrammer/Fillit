/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiles <egiles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 17:19:03 by egiles            #+#    #+#             */
/*   Updated: 2019/09/15 17:58:59 by egiles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *ptr_s1;
	unsigned char *ptr_s2;

	ptr_s1 = (unsigned char*)s1;
	ptr_s2 = (unsigned char*)s2;
	while (n)
	{
		if (*ptr_s1 != *ptr_s2)
			return (*ptr_s1 - *ptr_s2);
		n--;
		ptr_s1++;
		ptr_s2++;
	}
	return (0);
}
