/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiles <egiles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 17:07:57 by egiles            #+#    #+#             */
/*   Updated: 2019/09/21 17:14:16 by egiles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_over_value(long int result, int nb, int sign)
{
	if (result > result * 10 + nb)
	{
		if (sign == -1)
			return (0);
		else
			return (-1);
	}
	else
		return (1);
}

int				ft_atoi(const char *str)
{
	int			sign;
	long int	result;

	result = 0;
	sign = 1;
	while ((*str == ' ' || (*str >= 9 && *str <= 13)) && *str)
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9' && *str)
	{
		if (ft_over_value(result, *str - '0', sign) == 1)
			result = result * 10 + (*str - '0');
		else
			return (ft_over_value(result, *str - '0', sign));
		str++;
	}
	return (result * sign);
}
