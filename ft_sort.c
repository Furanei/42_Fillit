/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 00:55:00 by mbriffau          #+#    #+#             */
/*   Updated: 2017/01/18 17:38:45 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t		*ft_piece(int *t)//test ici !!!!!
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
	printf("#\n%zi\n%zi\n%zi\n%zi\n#", tab[0], tab[1], tab[2], tab[3]);
	tab = ft_top_left(tab);
	printf("T\n%zi\n%zi\n%zi\n%zi\nT", tab[0], tab[1], tab[2], tab[3]);
	return (tab);
}

int		ft_index(char *s, int nb, int i)// resoudre le probleme
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

t_piece		*ft_sort(char *s, t_piece *piece, t_piece *first)// ajouter alst a main
{
	printf("sort\n");
	int 		check;
	int			t[4];

	t[0] = ft_index(s, 0, 0);
	t[1] = ft_index(s, 1, 0);
	t[2] = ft_index(s, 2, 0);
	t[3] = ft_index(s, 3, 0);
	printf("___tab___\n%d\n%d\n%d\n%d\n______\n", t[0], t[1], t[2], t[3]);
	check = (t[0] + 1 == t[1] || t[0] + 4 == t[1]) + (t[0] + 1 == t[2] ||
		t[0] + 4 == t[2]) + (t[0] + 1 == t[3] || t[0] + 4 == t[3]) + (t[1]
		+ 1 == t[2] || t[1] + 4 == t[2]) + (t[1] + 1 == t[3] || t[1] + 4
		== t[3]) + (t[2] + 1 == t[3] || t[2] + 4 == t[3]);
	printf("%d\n", check);
	if (check == 3 || check == 4)
	{
		return ((t_piece *)ft_add_piece_to_list(ft_piece(t), first, piece)); // probleme de segfault a la sortie de ft_piece
	}
	printf("sort --> 0\n");
	return (0);
}

