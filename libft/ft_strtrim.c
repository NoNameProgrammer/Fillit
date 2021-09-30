/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiles <egiles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 13:06:33 by egiles            #+#    #+#             */
/*   Updated: 2019/09/20 14:43:17 by egiles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	start_len;
	size_t	end_len;

	if (s)
	{
		start_len = 0;
		end_len = ft_strlen(s);
		while (s[start_len] == ' ' || s[start_len] == '\n' ||
		s[start_len] == '\t')
		{
			start_len++;
		}
		while (s[end_len - 1] == ' ' || s[end_len - 1] == '\n' ||
		s[end_len - 1] == '\t')
		{
			end_len--;
		}
		if (end_len < start_len)
			end_len = start_len;
		return (ft_strsub(s, start_len, end_len - start_len));
	}
	return (NULL);
}
