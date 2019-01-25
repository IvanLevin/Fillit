/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 13:51:50 by gkshleri          #+#    #+#             */
/*   Updated: 2019/01/20 15:04:29 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		find_figures(char *starr)
{
	int		i;
	int		flag;

	flag = 0;
	i = 0;
	while (starr[i])
	{
		if (starr[i] == '#')
			break ;
		i++;
	}
	while (starr[i] != '\0')
	{
		if (starr[i] == starr[i + 1] && starr[i] == '#')
			flag++;
		if (starr[i] == starr[i + 5] && starr[i] == '#')
			flag++;
		if (flag == 3)
			return (GOOD);
		i++;
	}
	return (ERROR);
}

int		check_valid_first(char *staar)
{
	int		i;
	int		pound;
	int		lattice;
	int		b_space;

	b_space = 0;
	lattice = 0;
	i = 0;
	pound = 0;
	while (staar[i])
		i++;
	if (i == 21 || i < 20)
		return (ERROR);
	else if (find_figures(staar))
		return (GOOD);
	return (ERROR);
}

int		check_last_zero(char *staar)
{
	int		i;
	int		pound;
	int		lattice;
	int		b_space;

	b_space = 0;
	lattice = 0;
	i = 0;
	pound = 0;
	while (staar[i] && (staar[i] == '.' || staar[i] == '#' || \
				staar[i] == '\n'))
	{
		if (staar[i] == '.')
			pound++;
		else if (staar[i] == '#')
			lattice++;
		else if (staar[i] == '\n' && (i == 4 || i == 9 || \
					i == 14 || i == 19 || i == 20 || i == 21))
			b_space++;
		i++;
	}
	if ((pound == 12 && lattice == 4 && (b_space == 5 || b_space == 4)))
		if (find_figures(staar))
			return (GOOD);
	return (ERROR);
}

int		check_valid(char *staar, int last)
{
	int		i;
	int		pound;
	int		lattice;
	int		b_space;

	b_space = 0;
	lattice = 0;
	i = 0;
	pound = 0;
	if (last == 0)
		if (!(check_last_zero(staar)))
		{
			write(1, "error\n", 6);
			return (ERROR);
		}
	if (last == 1)
		if (!(check_valid_first(staar)))
		{
			write(1, "error\n", 6);
			return (ERROR);
		}
	return (GOOD);
}
