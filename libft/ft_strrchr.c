/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 20:23:19 by gkshleri          #+#    #+#             */
/*   Updated: 2018/12/23 16:51:17 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	char	*arr;
	char	*check;

	check = NULL;
	ch = (char)c;
	arr = (char *)s;
	while (*arr != '\0')
	{
		if (*arr == ch)
			check = arr;
		arr++;
	}
	if (*arr == ch)
		return (arr);
	else
		return (check);
}
