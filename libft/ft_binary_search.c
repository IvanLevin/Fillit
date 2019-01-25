/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_search.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:36:20 by gkshleri          #+#    #+#             */
/*   Updated: 2018/12/23 16:48:11 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_binary_search(int *list, int item, int len)
{
	int		low;
	int		mid;
	int		high;
	int		guess;

	low = 0;
	mid = 0;
	high = len;
	guess = 0;
	while (low <= high)
	{
		mid = (low + high) / 2;
		guess = list[mid];
		if (guess == item)
			return (mid);
		else if (guess > item)
			high = mid - 1;
		else if (guess < item)
			low = mid + 1;
	}
	return (-1);
}
