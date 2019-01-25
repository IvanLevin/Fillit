/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:56:06 by gkshleri          #+#    #+#             */
/*   Updated: 2018/12/23 16:50:09 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch_a;
	char	*arr;

	ch_a = (char)c;
	arr = (char *)s;
	while (*arr != '\0' && *arr != ch_a)
		arr++;
	if (*arr != ch_a)
		return (NULL);
	else
		return (arr);
}
