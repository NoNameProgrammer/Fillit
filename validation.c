/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiles <egiles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 12:42:22 by egiles            #+#    #+#             */
/*   Updated: 2020/01/31 19:58:32 by egiles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	convert_tetr(char *tetr, t_tetr *input, int i)
{
	int		j;
	int		a;

	j = 0;
	a = 0;
	while (j < 19)
	{
		if (tetr[j] == '#')
		{
			input->x[a] = (j % 5) - input->x[0];
			input->y[a] = (j / 5) - input->y[0];
			a++;
		}
		j++;
	}
	input->x[0] = 0;
	input->y[0] = 0;
	input->nbr = i + 1;
}

int		check_contacts(char *tetr)
{
	int contact;
	int i;

	contact = 0;
	i = 0;
	while (i < 19)
	{
		if (tetr[i] == '#' && ((i + 1) % 5) != 0)
		{
			if ((i - 5) >= 0 && tetr[i - 5] == '#')
				contact++;
			if ((i + 5) < 19 && tetr[i + 5] == '#')
				contact++;
			if ((i - 1) >= 0 && tetr[i - 1] == '#')
				contact++;
			if ((i + 1) < 19 && tetr[i + 1] == '#')
				contact++;
		}
		i++;
	}
	return (contact == 6 || contact == 8);
}

int		check_tetr(char *tetr)
{
	int i;
	int nbr_hash;

	i = 0;
	nbr_hash = 0;
	while (i < 20)
	{
		if ((tetr[i] != '.' && tetr[i] != '#') && (((i + 1) % 5) != 0))
			return (0);
		if (tetr[i] != '\n' && (((i + 1) % 5) == 0))
			return (0);
		if (tetr[i] == '#')
			nbr_hash++;
		i++;
	}
	if (nbr_hash != 4)
		return (0);
	return (check_contacts(tetr));
}

int		check_last(char *str)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		if (*str == '\n')
			count++;
		str++;
	}
	return (count == 4 ? 1 : 0);
}

int		validation(int fd, t_tetr input[27])
{
	char	tetr[21];
	int		nbread;
	int		all;
	int		i;

	i = -1;
	all = 0;
	nbread = 0;
	while ((nbread = read(fd, tetr, 21)) > 0)
	{
		if (nbread < 20)
			return (0);
		if (check_tetr(tetr) && i++ <= 26)
		{
			all = all + nbread;
			convert_tetr(tetr, &(input[i]), i);
		}
		else
			return (0);
	}
	return ((i >= 0) && ((all - 20) % 21) == 0 ? 1 : 0);
}
