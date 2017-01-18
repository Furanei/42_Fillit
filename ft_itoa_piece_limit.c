/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_piece_limit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 23:01:41 by mbriffau          #+#    #+#             */
/*   Updated: 2017/01/18 18:45:21 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_test(size_t *t, size_t nb_line, size_t n)
{
	size_t	count;

	count = 0;
	while (nb_line)
	{
		count += t[nb_line] & n; 
		nb_line--;
	}
	if (count)
		return (1);
	return 0;
}

size_t			ft_itoa_piece_limit(size_t *t, size_t nb_line)
{
	int i;
	int	again;
	int power;
	size_t n;

	i = 0;
	again = 1;
	power = 31;
	while (again)
	{
		n = ft_pow(2, power);
		if (ft_test(t, nb_line, n))
			i++;
		else
			again = 0;
		power--;
	}
	return (i);
}