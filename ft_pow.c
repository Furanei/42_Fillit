/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 15:49:02 by mbriffau          #+#    #+#             */
/*   Updated: 2017/01/14 23:01:49 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t	ft_pow(size_t n, int power) /*donne la puissance POWER de N. */
{
	size_t		exp;

	if (power == 0)
		return (1);
	exp = n;
	while (1 < power--)
	{
		n *=  exp;
	}
	return (n);
}