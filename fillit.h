/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiles <egiles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 22:22:05 by sasajj            #+#    #+#             */
/*   Updated: 2020/01/31 19:37:36 by egiles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct	s_tetr
{
	int				nbr;
	int				x[4];
	int				y[4];
}				t_tetr;

void			convert_tetr(char *tetr, t_tetr *input, int i);
int				check_contacts(char *tetr);
int				check_tetr(char *tetr);
int				check_last(char *str);
int				validation(int fd, t_tetr input[27]);
void			fill_field(int field[104][104]);
void			print_field(int field[104][104], int size);
int				print_error(void);
void			put_tetr(t_tetr tetr_ptr, int field[104][104], int x, int y);
void			del_tetr(t_tetr tetr_ptr, int field[104][104], int x, int y);
int				check_place(t_tetr tetr_ptr, int field[104][104],
							int size, int *xy);

#endif
