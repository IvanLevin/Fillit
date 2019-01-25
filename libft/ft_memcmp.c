/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 14:57:58 by gkshleri          #+#    #+#             */
/*   Updated: 2018/12/23 16:49:15 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*arr_1;
	unsigned char	*arr_2;

	arr_1 = (unsigned char *)str1;
	arr_2 = (unsigned char *)str2;
	while (n > 0 && (*arr_1 == *arr_2))
	{
		arr_1++;
		arr_2++;
		n--;
	}
	if (n == 0)
		return (0);
	else
		return (*arr_1 - *arr_2);
}
