/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 19:36:06 by gkshleri          #+#    #+#             */
/*   Updated: 2019/01/20 15:02:48 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**get_lattice(t_lists *list, char **max_tab)
{
	int		i;
	int		j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if (list->fig[i][j] == '#' && \
				max_tab[i + list->y][j + list->x] == '.')
				max_tab[i + list->y][j + list->x] = list->fig[i][j];
	}
	return (max_tab);
}

char	**record_fig(t_lists *list, char **max_tab, int tabsize)
{
	int		i;
	int		j;

	i = -1;
	while (++i < tabsize)
	{
		j = -1;
		while (++j < tabsize)
			if (max_tab[i][j] == '#')
				max_tab[i][j] = list->name_fig;
	}
	return (max_tab);
}

char	**delete_fig(char **max_tab, int tabsize, t_lists *list)
{
	int		i;
	int		j;

	i = -1;
	while (++i < tabsize)
	{
		j = -1;
		while (++j < tabsize)
			if (max_tab[i][j] == list->name_fig)
				max_tab[i][j] = '.';
	}
	return (max_tab);
}

int		insert_fig(t_lists *list, char **max_tab, int tabsize)
{
	int		i;
	int		j;
	int		flag;

	flag = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (list->fig[i][j] == '#')
			{
				if (i + list->y >= tabsize || j + list->x >= tabsize)
					return (0);
				if (max_tab[i + list->y][j + list->x] == '.')
					flag++;
				else
					return (0);
			}
		}
	}
	if (!(max_tab = get_lattice(list, max_tab)))
		return (0);
	return (1);
}

int		recurs_fig(char **max_tab, int tabsize, t_lists *list)
{
	if (list != NULL)
	{
		while (list->x * list->y < tabsize * tabsize)
		{
			if (insert_fig(list, max_tab, tabsize) == 1)
			{
				max_tab = record_fig(list, max_tab, tabsize);
				if (recurs_fig(max_tab, tabsize, list->next))
					return (1);
				max_tab = delete_fig(max_tab, tabsize, list);
			}
			if (list->x < tabsize)
				list->x++;
			else
			{
				list->x = 0;
				list->y++;
			}
		}
		list->x = 0;
		list->y = 0;
		return (0);
	}
	return (1);
}
