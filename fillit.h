/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 17:03:18 by gkshleri          #+#    #+#             */
/*   Updated: 2019/01/20 15:14:15 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define ERROR 0
# define GOOD 1
# include "libft/includes/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef	struct	s_lists
{
	char			**fig;
	char			name_fig;
	int				x;
	int				y;
	struct s_lists	*next;

}				t_lists;
int				ft_fillit(int fd);
int				check_valid(char *staar, int last);
int				check_last_zero(char *staar);
int				check_valid_first(char *staar);
void			fillit_get_tab(char **arr, int num);
int				find_figures(char *starr);
t_lists			*collect_figures(char **arr, int max);
t_lists			*min_figures(char **fig, int alf);
t_lists			*record_figures(int min_x, int min_y, char **fig, int alf);
char			**ft_up(int min_y, char **fig);
char			**ft_left(int min_x, char **fig);
t_lists			*fill_struct(char **fig, int alf);
int				get_tab_size(int tab_size);
int				ft_sqrt(int nb);
char			**table_max(int tabsize);
int				recurs_fig(char **max_tab, int tabsize, t_lists *list);
void			free_tab(char **max_tab, int tabsize);
int				insert_fig(t_lists *list, char **max_tab, int tabsize);
char			**record_fig(t_lists *list, char **max_tab, int tabsize);
char			**get_lattice(t_lists *list, char **max_tab);
char			**delete_fig(char **max_tab, int tabsize, t_lists *lists);

#endif
