/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiles <egiles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 17:04:48 by egiles            #+#    #+#             */
/*   Updated: 2019/09/22 16:02:07 by egiles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *src)
{
	int		len;
	char	*cpy;

	len = ft_strlen(src);
	if (!(cpy = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	cpy[len] = '\0';
	while (len >= 0)
	{
		cpy[len] = src[len];
		len--;
	}
	return (cpy);
}
