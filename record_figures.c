/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_figures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 13:54:46 by gkshleri          #+#    #+#             */
/*   Updated: 2019/01/20 14:36:39 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_lists		*fill_struct(char **fig, int alf)
{
	t_lists *new;

	new = (t_lists*)malloc(sizeof(t_lists));
	new->fig = fig;
	new->name_fig = 'A' + alf;
	new->x = 0;
	new->y = 0;
	new->next = NULL;
	return (new);
}

char		**ft_left(int min_x, char **fig)
{
	int		i;
	int		j;

	i = -1;
	while (fig[++i])
	{
		j = -1;
		while (fig[i][++j])
		{
			if (fig[i][j] == '#' && j >= 0)
			{
				fig[i][j] = '.';
				fig[i][j - min_x] = '#';
			}
		}
	}
	return (fig);
}

char		**ft_up(int min_y, char **fig)
{
	int		i;
	int		j;

	i = -1;
	while (fig[++i])
	{
		j = -1;
		while (fig[i][++j])
		{
			if (fig[i][j] == '#' && i >= 0)
			{
				fig[i][j] = '.';
				fig[i - min_y][j] = '#';
			}
		}
	}
	return (fig);
}

t_lists		*record_figures(int min_x, int min_y, char **fig, int alf)
{
	t_lists *list;

	fig = ft_up(min_y, fig);
	fig = ft_left(min_x, fig);
	list = fill_struct(fig, alf);
	return (list);
}
