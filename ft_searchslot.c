/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_searchslot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 18:27:03 by mbriffau          #+#    #+#             */
/*   Updated: 2017/01/12 20:28:48 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pow(int n, int power) /*donne la puissance POWER de N. */
{/*fonction verifie c'est OK*/
	int		exp;

	if (power == 0)
		return (1);
	exp = n;
	while (1 < power--)
	{
		n *=  exp;
	}
	return (n);
}

int		*ft_add_piece(int *area, int *add, int decal)/*ajoute une piece au bloc*/
{
	area[decal + 0] += add[0];
	area[decal + 1] += add[1];
	area[decal + 2] += add[2];
	area[decal + 3] += add[3];
	return ((int*)b);
}

static int		ft_check_binary_mask(int *area, int *add, int decal)/*Renvoie 1 si les pieces se chevauchent, sinon 0.*/
{/*fonction verifie c'est OK*/
	if (area[decal + 0] & add[0] || area[decal + 1] & add[1]
	 || area[decal + 2] & add[2] || area[decal + 3] & add[3])
		return (1);
	else
		return (0);
}

int		ft_check_limit(int *add, int limit, int decal)/*Si la piece depasse la limite 'i' revoie 1, sinon 0.*/
{
	int		l;

	l = ft_pow(2, 31 - limit);
	if ((add[0] & l || add[1] & l || add[2] & l || add[3] & l) || (decal + 4 = i))// a revoir pas sur !!!
		return (1);
	return (0);
} 

int		*search_slot(int *area, int *add)
{
	int		limit;/*limite*/
	int		decal;/*decalage*/

	decal = 0;
	limit = 4;
	while (ft_check_binary_mask(*area, *add, decal) || ft_check_limit(*add, limit, decal))
	{
		if (ft_check_limit(*add, limit, decal))//et que decal + 3 < a limit alors decal ++
			// si decal + 3 = limit et que ft_limit ok  alors limit  += 1 et decal = 0 
		{
			decal++;
			limit++;
		}// faire une limit pour le bas, la piece ne prend pas forcement les 4 emplacement
		// des 4 int. il ne faut pas se baser sur decal + 3,

		// voir pour faire un test d' int utile de la piece au debut pour utileser juste 
		// les int utile, exemple avec un carre en haut a gauche, juste les 2 premiers int.
		else :
		{
			add[0] >>= 1;// fonction decalage
			add[1] >>= 1;
			add[2] >>= 1;
			add[3] >>= 1;
		}
	}
	if (!(ft_check_binary_mask(*area, *add, a)))
		return (ft_add_piece(*area, *add, a));
	return (0);// quoi si faux??
}
