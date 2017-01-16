/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_searchslot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 18:27:03 by mbriffau          #+#    #+#             */
/*   Updated: 2017/01/16 16:48:53 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t		*ft_add_piece(size_t *area, size_t *add, int decal)/*ajoute une piece au bloc*/
{
	area[decal + 0] += add[0];
	area[decal + 1] += add[1];
	area[decal + 2] += add[2];
	area[decal + 3] += add[3];
	return ((size_t*)area);
}

static int		ft_check_binary_mask(size_t *area, size_t *add, int decal)/*Renvoie 1 si les pieces se chevauchent, sinon 0.*/
{/*fonction verifie c'est OK*/
	if (area[decal + 0] & add[0] || area[decal + 1] & add[1]
	 || area[decal + 2] & add[2] || area[decal + 3] & add[3])
		return (1);
	else
		return (0);
}

static int		ft_check_limit_x(size_t *add, int limit, int decal)/*Si la piece depasse la limite 'i' revoie 1, sinon 0.*/
{
	int		lmtbit;

	lmtbit = ft_pow(2, 31 - limit);// limit non inclus, barriere exterieure en binaire.
	if ((add[0] & lmtbit || add[1] & lmtbit || add[2] & lmtbit || add[3] & lmtbit))
		return (1);
	return (0);
} //besoin de placer la piece en haut a gauche pour lutiliser

static int		ft_check_limit_y(size_t *add, int limit, int decal)/*Si la piece depasse la limite 'i' revoie 1, sinon 0.*/
{
	int		size; /*size of piece*/

	size = 0;
	while (add[size] & 4294967295)/*find height of add*/
	{
		size++;
	}
	if ((decal + size == limit))
		return (1);//trop  bas
	return (0);
} //besoin de placer la piece en haut a gauche pour lutiliser

size_t		*search_slot(size_t *area, size_t *add)
{
	int		limit;/*limite*/ // a donner dans la fonction
	int		decal;/*decalage Y*/
	int		nbx;//nombre dedecalage de la piece vers x.

	decal = 0;
	limit = 4;
	nbx = 0;
	while (ft_check_binary_mask(area, add, decal))
	{
		if (ft_check_limit_x(add, limit, decal))
		{
			add[0] <<= nbx;
			add[1] <<= nbx;
			add[2] <<= nbx;
			add[3] <<= nbx;
			decal++;
			nbx = 0;
		}
		if (ft_check_limit_y(add, limit, decal))//modif
		{
			decal = 0;
			limit ++;
		}
		// faire une limit pour le bas, la piece ne prend pas forcement les 4 emplacement
		// des 4 int. il ne faut pas se baser sur decal + 3,

		// voir pour faire un test d' int utile de la piece au debut pour utiliser juste 
		// les int utile, exemple avec un carre en haut a gauche, juste les 2 premiers int.
		else
		{
			add[0] >>= 1;// fonction decalage
			add[1] >>= 1;
			add[2] >>= 1;
			add[3] >>= 1;
			nbx++;
		}
	}
	if (!(ft_check_binary_mask(area, add, decal)))
		return (ft_add_piece(area, add, decal));
	return (0);// quoi si faux??
}
