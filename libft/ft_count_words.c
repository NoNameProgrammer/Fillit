/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiles <egiles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 14:54:36 by egiles            #+#    #+#             */
/*   Updated: 2019/09/24 18:48:17 by egiles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_words(char const *str, char c)
{
	size_t wcount;

	wcount = 0;
	while (*str == c && *str)
		str++;
	while (*str)
	{
		while (*str != c && *str)
			str++;
		wcount++;
		while (*str == c && *str)
		{
			str++;
			if (*str == '\0')
				return (wcount);
		}
	}
	return (wcount);
}
