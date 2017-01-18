/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_piece.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 21:42:53 by mbriffau          #+#    #+#             */
/*   Updated: 2017/01/16 23:56:01 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_itoa_piece(t_piece *piece, size_t limit)
{
	printf("itoa\n");
	size_t		nb_line; // hauteur du contenu de piece
	int		i;
	char	**dest;
	int		power;
	size_t	tmp;
	size_t		a;

	nb_line = 0;
	i = 0;
	while(piece->tab[nb_line] != 0)
	{
		nb_line++;
	}
	if (!(dest = (char **)ft_memalloc(nb_line + 1)))
		return (NULL);
	while(nb_line)
	{
		power = 31; /* on remet power a 0 pour un nouveau char*. */ 
		a = 0; /*on remet l'index 'a' a 0 pour un nouveau char*. */
		tmp = piece->tab[i];// int en cours de transformation
		if (!(dest[i] = (char*)ft_memalloc(limit + 1)))
			return (NULL);
		while(a < limit)
		{
			if (tmp & ft_pow(2, power))
			{
				tmp -= ft_pow(2, power);
				dest[i][a] = piece->letter;
			}
			else
			{
				dest[i][a] = '.';
			}
			a++;
			power--;
		}
		i++;
		nb_line--;
	}
	return (dest);
}