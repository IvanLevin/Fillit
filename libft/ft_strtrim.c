/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 19:46:47 by gkshleri          #+#    #+#             */
/*   Updated: 2018/12/23 16:51:30 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strtrim(char const *s)
{
	char	*arr;
	size_t	len;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
		i++;
	if (s[i] == '\0' && (arr = ft_strnew(sizeof(char))))
		return (arr);
	j = i;
	while (i < len && s[i] != '\0')
		i++;
	i--;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && i != 0)
		i--;
	if (!(arr = ft_strnew(i - j + 1)))
		return (NULL);
	arr = ft_strncpy(arr, &s[j], (i - j + 1));
	return (arr);
}
