/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiles <egiles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 15:26:08 by egiles            #+#    #+#             */
/*   Updated: 2019/09/25 16:23:00 by egiles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wlen(char const *s, char c)
{
	size_t i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void		*ft_free_arr(char **arr, size_t i)
{
	size_t j;

	j = -1;
	while (++j < i - 1)
	{
		free(arr[j]);
		arr[j] = NULL;
	}
	free(arr);
	arr = NULL;
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	**str;

	if (s == NULL || !(str = (char **)malloc(sizeof(char*)
	* (ft_count_words(s, c) + 1))))
		return (NULL);
	j = -1;
	i = ft_skip_ws(s, c);
	while (++j < ft_count_words(s, c) && s[i])
	{
		i = i + ft_skip_ws(s + i, c);
		if (!(str[j] = (char *)malloc(sizeof(char)
		* (ft_wlen(s + i, c) + 1))))
			return (ft_free_arr(str, j));
		k = -1;
		while (s[i] != c && s[i])
			str[j][++k] = s[i++];
		str[j][++k] = '\0';
	}
	str[j] = NULL;
	return (str);
}
