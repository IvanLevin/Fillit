/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 18:42:38 by gkshleri          #+#    #+#             */
/*   Updated: 2018/12/23 16:49:29 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memset(void *memptr, int val, size_t num)
{
	unsigned char	*arr;
	size_t			i;

	i = 0;
	arr = (unsigned char*)memptr;
	while (i < num)
		arr[i++] = val;
	return (arr);
}
