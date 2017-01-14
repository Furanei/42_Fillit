/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 19:10:53 by mbriffau          #+#    #+#             */
/*   Updated: 2016/12/15 18:33:43 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int ft_pow(int n, int power);

char		*ft_convertotetri(unsigned short bit, int size)
{
	int power;
	int	i;
	char	*tertis;
	int		backn;
	int		x;

	printf("___FT_CONVERTOTERI___\n");
	x = size * size + size;
	tertis = (char *)malloc(x);
	backn = 0;
	tertis[x - 1] = '\0';
	i = 0;
	power = 15;
	while (bit > 0 || i < (x - 1))
	{
		if (backn >= size && i < (size * size))
		{
			tertis[i] = '\n';
			backn = 0;
			i++;
		}
		tertis[i] = '.';
		if (bit - (ft_pow(2, power)) >= 0)
		{
			bit -= ft_pow(2, power);
			tertis[i] = 'A';
		}
		i++;
		power--;
		backn++;
	}
	return (tertis);
}

unsigned short	ft_convertbit(const char *s, int nbtab)/* recois des str de 16 fini par un \0. */
{
	int		power;
	int		i;
	unsigned short	convert;

	printf("___FT_COVERTBIT___\n");
	convert = 0;
	i = 0;
	power = 15;
	while (s[i])
	{
		if (s[i] == '#')
			convert += ft_pow(2, power);
	power--;
	i++;
	}
	return (convert);
}

int	ft_pow(int n, int power) /*donne la puissance POWER de N. */
{
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

unsigned short		search_slot(unsigned short square, unsigned short new)
{
	int		i;

	printf("__FT_SEARCH__\nsquare = %d\nnew = %d\n", square, new);
	i = 0;
	while (square & new)
	{
		new >>= 1;
		printf("%d\n", ++i);
	}
	if (!(square & new))
	{
		printf("slot ok\n");
		return (square + new);
	}
	return (0);
}

int		main(int argc, char const *argv[])
{
	// ft_convertotetri(3);
	// printf("%d\n", ft_convertbit(argv[1], 0));
	// unsigned short	a;
	// unsigned short	b;

	// a = argc > 1 ? atoi(argv[1]) : 0;
	// b = argc > 1 ? atoi(argv[2]) : 0;
	printf("____START___\n\na = %s\nb = %s\n", argv[1], argv[2]);
	printf("%s\n", ft_convertotetri(search_slot(ft_convertbit(argv[1], 0), ft_convertbit(argv[2], 0)), 5));
	// printf("[%d]\n", search_slot(a, b));
	// printf("a : %d\n", a);
	// printf("b : %d\n", b);
	// printf("%d\n", ft_pow(a, b));

	// while ((a & b))
	// {
	// 	b = b >> 1;
	// 	printf("+1\n");
	// }
	// printf("sortie de boucle\n");
	// if (!(a & b))
	// {
	// 	printf("ac");
	// }
	return (0);
}
