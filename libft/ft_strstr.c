/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 10:55:01 by gkshleri          #+#    #+#             */
/*   Updated: 2018/12/23 16:51:24 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static	int	ft_search(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

char		*ft_strstr(const char *s1, const char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (s2[j] == '\0')
		return ((char *)&s1[i]);
	while (s1[i] != '\0')
	{
		if (s1[i] == s2[j])
			if (ft_search(&s1[i], &s2[j]) == 1)
				return ((char *)&s1[i]);
		i++;
	}
	return (0);
}
