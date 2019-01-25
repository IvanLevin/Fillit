/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 13:44:54 by gkshleri          #+#    #+#             */
/*   Updated: 2018/12/23 16:49:09 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*arr;
	unsigned char	*arr_1;
	size_t			i;

	i = -1;
	c = (unsigned char)c;
	arr = (unsigned char*)src;
	arr_1 = (unsigned char*)dst;
	while (++i < n)
		if ((arr_1[i] = arr[i]) == c)
			return (&arr_1[i + 1]);
	return (NULL);
}
