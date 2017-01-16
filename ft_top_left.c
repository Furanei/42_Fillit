/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_top_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 16:56:27 by mbriffau          #+#    #+#             */
/*   Updated: 2017/01/16 18:54:24 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t		*ft_top_left(size_t *tab)
{
	int		i;
	int		up;
	size_t	fst;

	fst = ft_pow(2, 31);
	i = 0;
	up = 0;
	while (tab[i] == 0)/*x*/
	{
		up++;
		i++;
	}
	while (up--)
	{
		tab[0] = tab[1];
		tab[1] = tab[2];
		tab[2] = tab[3];
		tab[3] = tab[0];
	}
	while (!(tab[0] & fst || tab[1] & fst || tab[2] & fst || tab[3] & fst))/*y*/
	{
		tab[0] <<= 1;
		tab[1] <<= 1;
		tab[2] <<= 1;
		tab[3] <<= 1;
	}
	return (tab);
}