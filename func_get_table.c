/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_get_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 16:12:14 by gkshleri          #+#    #+#             */
/*   Updated: 2019/01/20 15:02:37 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_tab(char **max_tab, int tabsize)
{
	int		i;

	i = -1;
	while (++i < tabsize)
		ft_strdel(&max_tab[i]);
	ft_strdel(max_tab);
}

int		get_tab_size(int tab_size)
{
	int get_tab_size;

	get_tab_size = ft_sqrt(tab_size * 4);
	return (get_tab_size);
}

char	**table_max(int tab_size)
{
	int		i;
	int		j;
	char	**table;

	i = 0;
	j = -1;
	table = (char **)malloc(sizeof(char *) * tab_size + 1);
	while (i < tab_size)
	{
		table[i] = (char *)malloc(sizeof(char) * tab_size + 1);
		j = -1;
		while (j < tab_size)
			table[i][++j] = '.';
		table[i][j] = '\0';
		i++;
	}
	table[i] = NULL;
	return (table);
}
