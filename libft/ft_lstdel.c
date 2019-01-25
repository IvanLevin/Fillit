/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 19:15:23 by gkshleri          #+#    #+#             */
/*   Updated: 2018/12/23 16:48:52 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	if (alst == NULL || *alst == NULL || del == NULL)
		return ;
	tmp = *alst;
	while ((*alst) != NULL)
	{
		tmp = (*alst)->next;
		(del)((*alst)->content, (*alst)->content_size);
		free(*alst);
		(*alst) = NULL;
		(*alst) = tmp;
	}
}
