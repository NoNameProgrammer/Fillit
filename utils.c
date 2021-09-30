/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiles <egiles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 22:04:51 by sasajj            #+#    #+#             */
/*   Updated: 2020/01/31 19:41:54 by egiles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fill_field(int field[104][104])
{
	int i;
	int j;

	i = 0;
	while (i < 104)
	{
		j = 0;
		while (j < 104)
		{
			field[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	print_field(int field[104][104], int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_putchar(field[i][j] ? (char)field[i][j] : '.');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	put_tetr(t_tetr tetr_ptr, int field[104][104], int x, int y)
{
	field[y + tetr_ptr.y[0]][x + tetr_ptr.x[0]] = tetr_ptr.nbr + 64;
	field[y + tetr_ptr.y[1]][x + tetr_ptr.x[1]] = tetr_ptr.nbr + 64;
	field[y + tetr_ptr.y[2]][x + tetr_ptr.x[2]] = tetr_ptr.nbr + 64;
	field[y + tetr_ptr.y[3]][x + tetr_ptr.x[3]] = tetr_ptr.nbr + 64;
}

void	del_tetr(t_tetr tetr_ptr, int field[104][104], int x, int y)
{
	field[y + tetr_ptr.y[0]][x + tetr_ptr.x[0]] = 0;
	field[y + tetr_ptr.y[1]][x + tetr_ptr.x[1]] = 0;
	field[y + tetr_ptr.y[2]][x + tetr_ptr.x[2]] = 0;
	field[y + tetr_ptr.y[3]][x + tetr_ptr.x[3]] = 0;
}

int		check_place(t_tetr tetr_ptr, int field[104][104], int size, int *xy)
{
	int x;
	int y;

	x = xy[0];
	y = xy[1];
	if (y + tetr_ptr.y[3] >= size || x + tetr_ptr.x[3] >= size ||
		y + tetr_ptr.y[3] < 0 || x + tetr_ptr.x[3] < 0 ||
		y + tetr_ptr.y[2] >= size || x + tetr_ptr.x[2] >= size ||
		y + tetr_ptr.y[2] < 0 || x + tetr_ptr.x[2] < 0 ||
		y + tetr_ptr.y[1] >= size || x + tetr_ptr.x[1] >= size ||
		y + tetr_ptr.y[1] < 0 || x + tetr_ptr.x[1] < 0)
		return (0);
	if (field[y + tetr_ptr.y[2]][x + tetr_ptr.x[2]] != 0 ||
		field[y + tetr_ptr.y[3]][x + tetr_ptr.x[3]] != 0 ||
		field[y + tetr_ptr.y[1]][x + tetr_ptr.x[1]] != 0)
		return (0);
	return (1);
}
