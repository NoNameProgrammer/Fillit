/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiles <egiles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 15:20:24 by egiles            #+#    #+#             */
/*   Updated: 2019/09/24 16:34:26 by egiles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	int			len;
	char		*str;
	long int	nb;

	nb = n;
	len = ft_nbrlen(nb);
	if (!(str = ft_strnew(len)))
		return (NULL);
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb > 9)
	{
		str[--len] = nb % 10 + '0';
		nb = nb / 10;
	}
	str[--len] = nb + '0';
	return (str);
}
