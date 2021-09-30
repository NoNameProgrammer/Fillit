/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiles <egiles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:53:14 by egiles            #+#    #+#             */
/*   Updated: 2020/01/31 19:50:25 by egiles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_sqrt1(int n)
{
	int		size;

	size = 2;
	while (size * size < n)
		size++;
	return (size);
}

int			print_error(void)
{
	ft_putstr("error\n");
	return (1);
}

static int	solve(int field[104][104], t_tetr input[27], int len, int i)
{
	int		xy[2];
	int		size;

	size = input[26].nbr;
	if (len == 0)
		return (1);
	xy[1] = -1;
	while (++xy[1] < size && (xy[0] = -1))
	{
		while (++xy[0] < size)
		{
			if (field[xy[1]][xy[0]] == 0 && check_place(input[i],
					field, size, xy))
			{
				put_tetr(input[i], field, xy[0], xy[1]);
				if (solve(field, input, len - 1, i + 1))
					return (1);
				del_tetr(input[i], field, xy[0], xy[1]);
			}
		}
	}
	return (0);
}

static int	solve_for_all(int field[104][104], t_tetr input[27])
{
	int		i;
	int		solved;
	int		len;

	i = 0;
	while (input[i].nbr != 0)
		i++;
	len = i;
	i = ft_sqrt1(i * 4);
	while (i < 104)
	{
		input[26].nbr = i;
		solved = solve(field, input, len, 0);
		if (solved == 1)
			break ;
		i++;
	}
	return (i);
}

int			main(int argc, char **argv)
{
	int				fd;
	int				field[104][104];
	int				i;
	static t_tetr	input[27];

	fill_field(field);
	if (argc != 2)
	{
		ft_putstr("usage: fillit file.fillit\n");
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (print_error());
	if ((validation(fd, input)) == 0)
	{
		ft_putstr("error\n");
		return (1);
	}
	i = solve_for_all(field, input);
	print_field(field, i);
	close(fd);
	return (0);
}
