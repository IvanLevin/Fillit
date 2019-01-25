/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 14:21:50 by gkshleri          #+#    #+#             */
/*   Updated: 2018/12/23 16:51:21 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static	char	**ft_clear(char **arr, int i)
{
	while (i)
		free(arr[i--]);
	free(arr);
	return (NULL);
}

static	int		ft_split_result(char const *s, char c)
{
	int check;
	int i;

	check = 0;
	i = 0;
	while (s[i] != c && s[i])
	{
		i++;
		check++;
	}
	return (check);
}

static	int		ft_split_count(char const *s, char c)
{
	int	flag;
	int	i;

	i = 0;
	flag = 0;
	if (s[i] != c && s[i])
	{
		flag++;
		i++;
	}
	while (s[i] != '\0')
	{
		while (s[i] == c && (s[i]))
		{
			i++;
			if (s[i] != c && s[i])
				flag++;
		}
		i++;
	}
	return (flag);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;

	i = 0;
	if (!(s) || (!(str = (char **)malloc(sizeof(char *) *
						(ft_split_count(s, c) + 1)))))
		return (NULL);
	while (*s != '\0')
	{
		j = 0;
		while (*(s) == c && *s != '\0')
			s++;
		if (*s != c && *s != '\0')
		{
			if ((str[i] = (char *)malloc(sizeof(char ) *
				ft_split_result(s, c) + 1)) == NULL)
				return (ft_clear(str, i));
			while (*s != c && *s != '\0')
				str[i][j++] = *(s++);
			str[i++][j] = '\0';
		}
	}
	str[i] = NULL;
	return (str);
}
