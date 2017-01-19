/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_top_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 16:56:27 by mbriffau          #+#    #+#             */
/*   Updated: 2017/01/19 01:28:52 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t		*ft_top_left(size_t *tab)// place la piece en haut a gauche 
{
	int		i;
	int		up;
	size_t	fst;
	size_t	tmp;

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
		tmp = tab[0];
		tab[0] = tab[1];
		tab[1] = tab[2];
		tab[2] = tab[3];
		tab[3] = tmp;
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