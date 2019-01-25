/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_figures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 13:52:41 by gkshleri          #+#    #+#             */
/*   Updated: 2019/01/20 14:32:41 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_lists		*min_figures(char **fig, int alf)
{
	int		i;
	int		j;
	int		min_x;
	int		min_y;
	t_lists	*list_fig;

	min_x = 3;
	min_y = 3;
	i = -1;
	while (fig[++i])
	{
		if (ft_strchr(fig[i], '#'))
			if (min_y >= i)
				min_y = i;
		j = -1;
		while (++j < 8)
			if (fig[i][j] == '#')
				if (min_x >= j)
					min_x = j;
	}
	list_fig = record_figures(min_x, min_y, fig, alf);
	return (list_fig);
}

t_lists		*collect_figures(char **arr, int max)
{
	int		i;
	t_lists	*first_list;
	t_lists	*last_list;

	i = 0;
	first_list = min_figures(ft_strsplit(arr[i], '\n'), i);
	last_list = first_list;
	i = 1;
	while (i < max)
	{
		last_list->next = min_figures(ft_strsplit(arr[i], '\n'), i);
		last_list = last_list->next;
		i++;
	}
	last_list->next = NULL;
	return (first_list);
}
