/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 16:03:19 by gkshleri          #+#    #+#             */
/*   Updated: 2018/12/23 16:49:19 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*arr;
	unsigned char	*arr_1;
	size_t			i;

	i = 0;
	arr = (unsigned char*)dest;
	arr_1 = (unsigned char*)src;
	while (i < n)
	{
		arr[i] = arr_1[i];
		i++;
	}
	return (arr);
}
