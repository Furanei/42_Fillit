/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_piece_limit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 23:01:41 by mbriffau          #+#    #+#             */
/*   Updated: 2017/01/16 23:38:19 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_itoa_piece_limit(size_t *t)
{
	printf("itoa limit\n");
	int i;
	int	again;
	int power;
	int n;

	i = 0;
	again = 1;
	power = 31;
	while (again)
	{
		n = ft_pow(2, power);
		if (t[0] & n || t[1] & n || t[2] & n || t[3] & n)
			i++;
		else
			again = 0;
		power--;
	}
	return (i);
}