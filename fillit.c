/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 17:02:31 by gkshleri          #+#    #+#             */
/*   Updated: 2019/01/20 14:16:16 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fillit_get_tab(char **arr, int num)
{
	t_lists	*fig;
	char	**max_tab;
	int		i;
	int		tabsize;

	i = 0;
	fig = collect_figures(arr, num);
	tabsize = get_tab_size(num);
	max_tab = table_max(tabsize);
	while (recurs_fig(max_tab, tabsize, fig) == 0)
	{
		tabsize++;
		free_tab(max_tab, tabsize);
		max_tab = table_max(tabsize);
		fig->x = 0;
		fig->y = 0;
	}
	num = 0;
	while (tabsize > num)
	{
		ft_putendl(max_tab[num]);
		num++;
	}
	ft_putendl(max_tab[num]);
}

int		ft_fillit(int fd)
{
	char	buf[21];
	char	*arr[21];
	int		i;
	int		n;

	i = 0;
	while ((n = read(fd, buf, 21)))
	{
		buf[n] = '\0';
		if (!(check_valid(buf, 0)))
			return (ERROR);
		if (!(arr[i] = (char *)malloc(sizeof(char) * 21)))
			return (0);
		arr[i] = ft_strcpy(arr[i], buf);
		i++;
	}
	if (!(check_valid(buf, 1)))
		return (ERROR);
	arr[i] = NULL;
	fillit_get_tab(arr, i);
	return (0);
}
