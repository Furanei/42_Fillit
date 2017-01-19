/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 00:55:00 by mbriffau          #+#    #+#             */
/*   Updated: 2017/01/18 18:05:33 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t		*ft_piece(int *t)// recoit les possitions de chaque # dans un tableau d'int, puis creer la piece dans un size_t *
{
	
	size_t	i;
	size_t	tshift;
	size_t	test;
	size_t	*tab;

	if(!(tab = (size_t*)malloc(4)))
		return (0);
	i = 0;
	tshift = 0;
	while (i < 4)
	{
		tab[i++] = 0;
	}
	i = 0;
	while (i < 4)
	{
		test = t[i];
		while (test > 3)
		{
			tshift++; 
			test -= 4;
		}
		tab[tshift] += ft_pow(2, 31 - (t[i] - (4 * tshift)));
		i++;
		tshift = 0;
	}
	return (ft_top_left(tab));// passe le size_t * dans ft_top_left pour replacer la piece avant de la return.
}

int		ft_index(char *s, int nb, int i)// trouve la position de chaque #, n est le nombre de # a ignoner avant de rendre le resultat. 
{
	while (s[i] != '\0')
	{
		if (s[i] == '#')
		{
			if (nb == 0)
				return (i);
			nb--;
		}
		i++;
	}
	return (0);
}

t_piece		*ft_sort(char *s, t_piece *piece, t_piece *first)// verifie si la piece est valide avec les coordonnees trouvees avec ft_index, puis l'envoi dans ft_piece
{
		int 		check;
	int			t[4];

	t[0] = ft_index(s, 0, 0);
	t[1] = ft_index(s, 1, 0);
	t[2] = ft_index(s, 2, 0);
	t[3] = ft_index(s, 3, 0);
	check = (t[0] + 1 == t[1] || t[0] + 4 == t[1]) + (t[0] + 1 == t[2] ||
		t[0] + 4 == t[2]) + (t[0] + 1 == t[3] || t[0] + 4 == t[3]) + (t[1]
		+ 1 == t[2] || t[1] + 4 == t[2]) + (t[1] + 1 == t[3] || t[1] + 4
		== t[3]) + (t[2] + 1 == t[3] || t[2] + 4 == t[3]);
	if (check == 3 || check == 4)
	{
		return ((t_piece *)ft_add_piece_to_list(ft_piece(t), first, piece));
	}
	return (0);
}

