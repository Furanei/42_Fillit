/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 00:55:00 by mbriffau          #+#    #+#             */
/*   Updated: 2017/01/16 19:08:24 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t		*ft_piece(int *t)
{
	printf("piece\n");
	size_t	i;
	size_t	tshift;
	size_t	test;
	size_t	*tab;

	if(!(tab = (size_t*)malloc(4)))
		return (0);
	i = 0;
	tshift = 0;
	while (i < 4)/* voir pour creer fonction creation tableau + init 0 dans la lib*/
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
	return (ft_top_left(tab));
}

int		ft_index(char *s, int nb, int i)
{
	while (s[i])
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

t_piece		*ft_sort(char *s, t_piece *piece, t_piece *first)// ajouter alst a main
{
	printf("sort\n");
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
		printf("sort 3 ou 4\n");
		return ((t_piece *)ft_add_piece_to_list(ft_piece(t), first, piece)); // probleme de segfault a la sortie de ft_piece
	}
	printf("sort --> 0\n");
	return (0);
}

