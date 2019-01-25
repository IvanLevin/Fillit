/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkshleri <gkshleri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:28:11 by gkshleri          #+#    #+#             */
/*   Updated: 2018/12/23 16:49:45 by gkshleri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putnbr(int n)
{
	unsigned int nbc;

	if (n < 0)
	{
		nbc = -n;
		ft_putchar('-');
	}
	else
		nbc = n;
	if (nbc > 9)
		ft_putnbr(nbc / 10);
	ft_putchar(nbc % 10 + '0');
}
