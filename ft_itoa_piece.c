/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_piece.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 21:42:53 by mbriffau          #+#    #+#             */
/*   Updated: 2017/01/14 23:38:31 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// char		*ft_itoa_piece(size_t bit, int limit_size)
// {
// 	int				power;
// 	int				i;
// 	char			*tertis;
// 	int				zone;
// 	static char		letter = 'A';

// 	zone = 32;
// 	tertis = (char *)malloc(zone);
// 	tertis[zone - 1] = '\0';
// 	i = 0;
// 	power = 31;
// 	while (bit > 0 || i < (zone - 1))
// 	{
// 		tertis[i] = '.';
// 		if (bit & (ft_pow(2, power)))
// 		{
// 			bit -= ft_pow(2, power);
// 			tertis[i] = letter;
// 			letter++;
// 		}
// 		i++;
// 		power--;
// 	}
// 	return (tertis);
// }

char	**ft_itoa_piece(t_piece *piece, size_t limit)
{
	size_t		nb_line; // hauteur du contenu de piece
	int		i;
	char	**dest;
	int		power;
	size_t	tmp;
	int		a;

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