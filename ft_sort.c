/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 00:55:00 by mbriffau          #+#    #+#             */
/*   Updated: 2017/01/14 17:10:57 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// char		*ft_convertotetri(size_t bit, int limit_size)
// {
// 	printf("ft_convertotetri\n");
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
		//printf("%s\n", ft_convertotetri(tab[tshift], 4));
		tab[tshift] += ft_pow(2, 31 - (t[i] - (4 * tshift)));
		//printf("%s\n\n", ft_convertotetri(tab[tshift], 4));
		i++;
		tshift = 0;
	}
	// printf("1\n");
	// printf("%s\n\n%s\n\n%s\n\n%s\n\n", ft_convertotetri(tab[0], 4),
	// ft_convertotetri(tab[1], 4), ft_convertotetri(tab[2], 4), ft_convertotetri(tab[3], 4));
	// printf("conver fini\n");
	return (tab);
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

t_piece		*ft_sort(char *s, t_piece *alst)// ajouter alst a main
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
	printf("check = %d\n", check);
	// if (ft_piece(t))
	// 	printf("piece OK\n");// SEGFAULT ICI !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	// if (ft_add_piece_to_list(ft_piece(t), alst, piece))
	// 	printf("add ok \n");
	if (check == 3 || check == 4)
	{
		printf("sort 3 ou 4\n");
		return ((t_piece *)ft_add_piece_to_list(ft_piece(t), alst)); // probleme de segfault a la sortie de ft_piece
	}
	printf("sort --> 0\n");
	return (0);
}
